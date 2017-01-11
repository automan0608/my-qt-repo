#include "dialog.h"
#include "ui_dialog.h"

#include "QPainter"
#include "QDebug"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../painter_2/1.jpg");

#if 0
    painter.translate(50, 50);
#elif 0
    painter.drawPixmap(0, 0, 250, 250, pix);
#else
    qreal width = pix.width();
    qreal height = pix.height();

    pix = pix.scaled(width * 2, height * 2, Qt::KeepAspectRatio);
#if 1
    painter.shear(0.5, 0);
#endif
    painter.drawPixmap(70, 70, pix);

#endif
}

void Dialog::mousePressEvent(QMouseEvent *e)
{
    qDebug() << e->pos();
}
