#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *openAction = new QAction(tr("&Open"), this);

    QIcon icon(":/myImages/image/2.jpg");
    openAction->setIcon(icon);

    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));

    ui->menuBar->addAction(openAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
