#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

enum class ColorLayer { RED, GREEN, BLUE };

struct Pixel {
    unsigned char r, g, b;
};

class Image {
public:
    Image();
    ~Image();

    void load(const std::string& filename);
    void save_as(const std::string& filename) const;
    void add_watermark();
    void blurr();
    void extract_layer(ColorLayer color_layer);
    void filter();
    void flip_horizontally();
    void flip_vertically();
    void inflate();
    void negative();
    void rotate_clockwise_90();
    void sepia();
    void shrink();
    void to_grayscale();
    int height() const;
    int width() const;

private:
    int m_width;
    int m_height;
    std::vector<Pixel> m_data;
};

#endif // IMAGE_H