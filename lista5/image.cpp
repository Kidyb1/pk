#include "image.h"
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <algorithm>

Image::Image() : m_width(0), m_height(0) {}

Image::~Image() {}

void Image::load(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) throw std::runtime_error("Could not open file");

    std::string header;
    file >> header;
    if (header != "P6") throw std::runtime_error("Invalid file format");

    file >> m_width >> m_height;

    int maxval;
    file >> maxval;
    file.ignore(256, '\n');

    m_data.resize(m_width * m_height);
    file.read(reinterpret_cast<char*>(&m_data[0]), m_data.size() * sizeof(Pixel));

    if (!file) throw std::runtime_error("Error reading pixel data");
}

void Image::save_as(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) throw std::runtime_error("Could not open file");

    file << "P6\n" << m_width << " " << m_height << "\n255\n";
    file.write(reinterpret_cast<const char*>(&m_data[0]), m_data.size() * sizeof(Pixel));
    if (!file) throw std::runtime_error("Error writing pixel data");
}

void Image::add_watermark() {
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            if (x == y || x == m_width - y - 1) {
                m_data[y * m_width + x] = { 255, 255, 255 };
            }
        }
    }
}

void Image::blurr() {
    std::vector<Pixel> temp = m_data;
    auto getPixel = [&](int x, int y) -> Pixel& {
        return temp[y * m_width + x];
        };

    for (int y = 1; y < m_height - 1; ++y) {
        for (int x = 1; x < m_width - 1; ++x) {
            int r = 0, g = 0, b = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    Pixel& p = getPixel(x + dx, y + dy);
                    r += p.r;
                    g += p.g;
                    b += p.b;
                }
            }
            m_data[y * m_width + x] = { static_cast<unsigned char>(r / 9),
                                       static_cast<unsigned char>(g / 9),
                                       static_cast<unsigned char>(b / 9) };
        }
    }
}

void Image::extract_layer(ColorLayer color_layer) {
    for (auto& p : m_data) {
        switch (color_layer) {
        case ColorLayer::RED:
            p.g = 0;
            p.b = 0;
            break;
        case ColorLayer::GREEN:
            p.r = 0;
            p.b = 0;
            break;
        case ColorLayer::BLUE:
            p.r = 0;
            p.g = 0;
            break;
        }
    }
}

void Image::filter() {
    std::vector<Pixel> temp = m_data;
    for (int y = 0; y < m_height - 1; ++y) {
        for (int x = 0; x < m_width - 1; ++x) {
            Pixel& current = temp[y * m_width + x];
            Pixel& next = temp[(y + 1) * m_width + (x + 1)];
            m_data[y * m_width + x] = { static_cast<unsigned char>(std::abs(current.r - next.r)),
                                       static_cast<unsigned char>(std::abs(current.g - next.g)),
                                       static_cast<unsigned char>(std::abs(current.b - next.b)) };
        }
    }
}

void Image::flip_horizontally() {
    for (int y = 0; y < m_height; ++y) {
        std::reverse(m_data.begin() + y * m_width, m_data.begin() + (y + 1) * m_width);
    }
}

void Image::flip_vertically() {
    for (int x = 0; x < m_width; ++x) {
        for (int y = 0; y < m_height / 2; ++y) {
            std::swap(m_data[y * m_width + x], m_data[(m_height - y - 1) * m_width + x]);
        }
    }
}

void Image::inflate() {
    int new_width = m_width * 2;
    int new_height = m_height * 2;
    std::vector<Pixel> new_data(new_width * new_height);

    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            Pixel& p = m_data[y * m_width + x];
            new_data[(2 * y) * new_width + (2 * x)] = p;
            new_data[(2 * y) * new_width + (2 * x + 1)] = p;
            new_data[(2 * y + 1) * new_width + (2 * x)] = p;
            new_data[(2 * y + 1) * new_width + (2 * x + 1)] = p;
        }
    }

    m_data = std::move(new_data);
    m_width = new_width;
    m_height = new_height;
}

void Image::negative() {
    for (auto& p : m_data) {
        p.r = 255 - p.r;
        p.g = 255 - p.g;
        p.b = 255 - p.b;
    }
}

void Image::rotate_clockwise_90() {
    std::vector<Pixel> new_data(m_height * m_width);
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            new_data[x * m_height + (m_height - y - 1)] = m_data[y * m_width + x];
        }
    }
    std::swap(m_width, m_height);
    m_data = std::move(new_data);
}

void Image::sepia() {
    to_grayscale();
    for (auto& p : m_data) {
        unsigned char tr = static_cast<unsigned char>(std::min(255, (int)(p.r * 0.393 + p.g * 0.769 + p.b * 0.189)));
        unsigned char tg = static_cast<unsigned char>(std::min(255, (int)(p.r * 0.349 + p.g * 0.686 + p.b * 0.168)));
        unsigned char tb = static_cast<unsigned char>(std::min(255, (int)(p.r * 0.272 + p.g * 0.534 + p.b * 0.131)));
        p.r = tr;
        p.g = tg;
        p.b = tb;
    }
}

void Image::shrink() {
    int new_width = m_width / 2;
    int new_height = m_height / 2;
    std::vector<Pixel> new_data(new_width * new_height);

    for (int y = 0; y < new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            Pixel& p1 = m_data[(2 * y) * m_width + (2 * x)];
            Pixel& p2 = m_data[(2 * y) * m_width + (2 * x + 1)];
            Pixel& p3 = m_data[(2 * y + 1) * m_width + (2 * x)];
            Pixel& p4 = m_data[(2 * y + 1) * m_width + (2 * x + 1)];

            new_data[y * new_width + x] = {
                static_cast<unsigned char>((p1.r + p2.r + p3.r + p4.r) / 4),
                static_cast<unsigned char>((p1.g + p2.g + p3.g + p4.g) / 4),
                static_cast<unsigned char>((p1.b + p2.b + p3.b + p4.b) / 4)
            };
        }
    }

    m_data = std::move(new_data);
    m_width = new_width;
    m_height = new_height;
}

void Image::to_grayscale() {
    for (auto& p : m_data) {
        unsigned char gray = static_cast<unsigned char>((p.r + p.g + p.b) / 3);
        p.r = gray;
        p.g = gray;
        p.b = gray;
    }
}

int Image::height() const {
    return m_height;
}

int Image::width() const {
    return m_width;
}
