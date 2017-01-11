#include "widget.h"
#include "ui_widget.h"

#include "QTimer"
#include "QDateTime"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(3000);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == id1)
    {
        ui->label->setText(tr("%1").arg(qrand()%10));
    }
    else if (e->timerId() == id2)
    {
        static int i = 0;
        i = (i + 1)%2;
        if(0 == i)
        {
            ui->label_2->setText(tr("hello"));
        }
        else
        {
            ui->label_2->setText(tr("world"));
        }
    }
    else
    {
//        qApp->quit();
    }

    int rand = qrand() %300;
    ui->lineEdit->move(rand, rand);
}

void Widget::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");

    ui->lineEdit->setText(str);
}
