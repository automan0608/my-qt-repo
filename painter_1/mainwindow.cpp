#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QPainter"
#include "QFontDatabase"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
#if 0
    QPainter painter(this);
    QPen pen(Qt::DotLine);
    QBrush brush(Qt::blue);
    brush.setStyle(Qt::HorPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(50, 50, 200, 200);

    painter.drawLine(QPointF(0,0), QPointF(300, 100));

    QRectF rectangle(10.0, 20.0, 80.0, 60.0);
    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
    QPainter painter1(this);
    painter1.drawArc(rectangle, startAngle, spanAngle);
#endif

#if 0
    QPainter painter2(this);
    QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190));
    linearGradient.setColorAt(0, Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::red);
    linearGradient.setColorAt(1, Qt::green);
    linearGradient.setSpread(QGradient::RepeatSpread);
    painter2.setBrush(linearGradient);
    painter2.drawRect(10, 20, 90, 40);

    QRadialGradient radialGradient(QPointF(100, 190), 50, QPointF(275, 200));
    radialGradient.setColorAt(0, QColor(255, 255, 100, 150));
    radialGradient.setColorAt(1, QColor(0, 0, 0, 50));
    painter2.setBrush(radialGradient);
    painter2.drawEllipse(QPointF(100, 190), 50, 50);

    QConicalGradient conicalGradient(QPointF(250, 190), 60);
    conicalGradient.setColorAt(0.2, Qt::cyan);
    conicalGradient.setColorAt(0.9, Qt::black);
    painter2.setBrush(conicalGradient);
    painter2.drawEllipse(QPointF(250, 190), 50, 50);
#endif

#if 0
    QPainter painter(this);
    QRectF rect(20, 20, 300, 200);
    painter.drawRect(rect);
    painter.setPen(QColor(Qt::red));
    painter.drawText(rect, Qt::AlignHCenter, "www.baidu.com");

    QFont font("songti", 15, QFont::Bold, true);
    font.setUnderline(true);
    font.setOverline(true);
    font.setCapitalization(QFont::SmallCaps);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 10);

    painter.setFont(font);
    painter.setPen(Qt::green);
    painter.drawText(120, 80, tr("zhaosheng"));
    painter.translate(50, 50);
    painter.rotate(90);
    painter.drawText(0, 0, tr("hello qt"));
#endif

#if 0
    QPainterPath path;
    path.addEllipse(100, 100, 50, 50);
    path.lineTo(200, 200);
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::red);
    painter.drawPath(path);

    QPainterPath path2;
    path2.addPath(path);
    path2.translate(100, 0);
    painter.drawPath(path2);
#endif

    QPainterPath path;
    path.addRect(50, 50, 40, 40);
#if 1
    path.moveTo(100, 100);
#endif
    path.lineTo(200, 200);
    QPainter painter(this);
    painter.drawPath(path);
}
