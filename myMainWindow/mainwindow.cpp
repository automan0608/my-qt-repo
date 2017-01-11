#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QMessageBox"
#include "QPushButton"
#include "QFileDialog"
#include "QTextStream"

#include "QLineEdit"
#include "QDialog"
#include "QPushButton"

#include "QLabel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isUntitled = true;
    curFile = tr("noname.txt");
    setWindowTitle(curFile);

#if 0
    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("find"));
    findLineEdit = new QLineEdit(findDlg);
    QPushButton *btn = new QPushButton(tr("find next"), findDlg);
    QVBoxLayout *layout = new QVBoxLayout(findDlg);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked(), this, SLOT(showFindText()));]
#endif

#if 0
    ui->statusBar->showMessage(tr("welcome to use qt"), 2000);
#else
    statusLabel = new QLabel;
    statusLabel->setMinimumSize(150, 20);
    statusLabel->setFrameShape(QFrame::WinPanel);
    statusLabel->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(statusLabel);
    statusLabel->setText(tr("welcome to use qt"));

    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText(tr("<a href=\"www.baidu.com\">www.baidu.com</a>"));
    permanent->setTextFormat(Qt::RichText);
    permanent->setOpenExternalLinks(true);
    ui->statusBar->addPermanentWidget(permanent);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    if(maybeSave())
    {
        isUntitled = true;
        curFile = tr("noname.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool MainWindow::maybeSave()
{
    if(ui->textEdit->document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle(tr("WARNING! "));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr("not saved, need to save? "));

        QPushButton *yesBtn = box.addButton(tr("Yes(&Y)"), QMessageBox::YesRole);
        box.addButton(tr("No(&N)"), QMessageBox::NoRole);

        QPushButton *cancelBtn = box.addButton(tr("Cancle(&C)"), QMessageBox::RejectRole);

        box.exec();
        if(box.clickedButton() == yesBtn)
        {
            return save();
        }
        else if (box.clickedButton() == cancelBtn)
        {
            return false;
        }
    }

    return true;
}

bool MainWindow::save()
{
    if(isUntitled)
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("save as"), curFile);

    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("multiple file edit"), tr("cannot write to file %1: /n %2").arg(fileName).arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();

    QApplication::restoreOverrideCursor();
    isUntitled = false;

    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_actionNew_N_triggered()
{
    newFile();
}

void MainWindow::showFindText()
{
    QString str = findLineEdit->text();
    if(!ui->textEdit->find(str, QTextDocument::FindBackward))
    {
        QMessageBox::warning(this, tr("find"), tr("cannot find %1").arg(str));
    }
}

void MainWindow::on_actionSave_S_triggered()
{
    save();
}

void MainWindow::on_actionSave_as_A_triggered()
{
    saveAs();
}

