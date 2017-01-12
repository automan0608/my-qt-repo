#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

#if 0
    QString localHostName = QHostInfo::localHostName();
    qDebug() << "localHostName" << localHostName;

    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug() << "IP Address" << info.addresses();
#endif

#if 0
    QHostInfo::lookupHost("cloud-sdk.tp-link.net", this, SLOT(lookedUp(QHostInfo)));
#endif

#if 0
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface interface, list) {
        qDebug() << "Device: " << interface.name();
        qDebug() << "HardwareAddress: " << interface.hardwareAddress();

        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        foreach (QNetworkAddressEntry entry, entryList) {
            qDebug() << "IP Address: " << entry.ip().toString();
            qDebug() << "Netmask: " << entry.netmask().toString();
            qDebug() << "Broadcast: " << entry.broadcast().toString();
        }
    }
#endif

#if 1
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list) {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            qDebug() << address.toString();
    }
#endif
}

Widget::~Widget()
{
    delete ui;
}

void Widget::lookedUp(const QHostInfo &host)
{
    qDebug() << host.addresses().first().toString();
}
