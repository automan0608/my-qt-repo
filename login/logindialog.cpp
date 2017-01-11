#include "logindialog.h"
#include "ui_logindialog.h"
#include "qmessagebox.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->usrLineEdit->text() == tr("zhaosheng")
            && ui->pwdLineEdit->text() == tr("111111"))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, tr("warning"), tr("user name or password error!"), QMessageBox::Yes);

        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}
