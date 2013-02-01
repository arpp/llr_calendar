#include "networksetup.h"
#include "ui_networksetup.h"

NetworkSetup::NetworkSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetworkSetup)
{
    ui->setupUi(this);
}

NetworkSetup::~NetworkSetup()
{
    delete ui;
}

void NetworkSetup::on_buttonBox_accepted()
{
    serverAddress=ui->address->text();
    serverPort=ui->port->text();
}



