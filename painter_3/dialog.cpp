#include "dialog.h"
#include "ui_dialog.h"

#include <QPainter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    resize(600, 500);
    pix = QPixmap(200, 200);
    pix.fill(Qt::white);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *)
{
#if 0
    QPainter pp(&pix);
    pp.drawLine(lastPoint, endPoint);
    lastPoint = endPoint;
    QPainter painter(this);
    painter.drawPixmap(0, 0, pix);
#endif

    int x, y, w, h;
    x = lastPoint.x();
    y = lastPoint.y();
    w = endPoint.x() - x;
    h = endPoint.y() - y;
#if 0
    QPainter painter(this);
    painter.drawRect(x, y, w, h);
#else
    QPainter pp(&pix);
    pp.drawRect(x, y, w, h);
    QPainter painter(this);
    painter.drawPixmap(0, 0, pix);
#endif
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        endPoint = event->pos();
        update();
    }
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        endPoint = event->pos();
        update();
    }
}
