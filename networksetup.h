#ifndef NETWORKSETUP_H
#define NETWORKSETUP_H

#include <QDialog>

namespace Ui {
class NetworkSetup;
}

class NetworkSetup : public QDialog
{
    Q_OBJECT
    
public:
    explicit NetworkSetup(QWidget *parent = 0);
    QString serverAddress, serverPort;
    ~NetworkSetup();
    
private slots:
    void on_buttonBox_accepted();


private:
    Ui::NetworkSetup *ui;
};

#endif // NETWORKSETUP_H
