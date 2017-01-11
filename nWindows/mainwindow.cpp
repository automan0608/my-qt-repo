#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("new window");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
#if 1
    QDialog *dlg = new QDialog(this);
    dlg->show();
#else
    QMainWindow *mw = new QMainWindow(this);
    mw->show();
#endif
}
