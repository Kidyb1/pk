#include "my_widget.h"
#include <QPainter>
#include <QRadialGradient>

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent), timer(this)
{
    connect(&timer, &QTimer::timeout, this, &MyWidget::onTimer);
    timer.start(timerInterval);
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor("#aeadac"))); // Background color
    painter.drawRect(this->rect());

    painter.translate(width() / 2.0, height() / 2.0);
    int side = std::min(width(), height());
    painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);

    QPointF center(20, 75);
    int radius = 25;
    QRadialGradient radialGrad(center, radius);
    radialGrad.setColorAt(0, Qt::magenta);
    radialGrad.setColorAt(0.5, Qt::transparent);
    painter.setBrush(radialGrad);

    for (int i = 0; i < numDisks; ++i) {
        if (i != hiddenDisk) {
            painter.drawEllipse(center.x() - radius / 2, center.y() - radius / 2, radius, radius);
        }
        painter.rotate(360.0 / numDisks);
    }

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(Qt::black, 2));
    int crossSize = 8;
    painter.drawLine(-crossSize / 2, 0, crossSize / 2, 0);
    painter.drawLine(0, -crossSize / 2, 0, crossSize / 2);
}

void MyWidget::onTimer()
{
    hiddenDisk = (hiddenDisk + 1) % numDisks;
    update();
}

void MyWidget::toggleAnimation()
{
    timer.isActive() ? timer.stop() : timer.start(timerInterval);
}
