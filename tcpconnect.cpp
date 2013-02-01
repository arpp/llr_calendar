#include "tcpconnect.h"

//Error may be due to previous unflushed value in string

/**
  *The constructor connects the socket to the server
  */
TCPConnect::TCPConnect(QWidget *parent, QString add, int pt) :
    QWidget(parent),
    signal(1)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(add,pt);
    if(!socket->waitForConnected(3000))
    {
        signal=0;
        QMessageBox::information(this,"Error!","Connection not available");
    }
}


/*
 *Destructor
 */
TCPConnect::~TCPConnect()
{
    free(socket);
}



/**
  *Used for sign up of new users
  *
  */


int TCPConnect::SignUP(QString userName, QString password)
{
    regString = "REG "+userName+" "+password;
    socket->write(regString.toLocal8Bit().data());

    if(!socket->waitForBytesWritten(3000))
    {
        QMessageBox::information(this,"Error!",socket->errorString());
        return 0;
    }

    socket->waitForReadyRead(3000);
    regString = socket->readAll();
    if(regString == QString("REG1"))
    {
        QMessageBox::information(this,"Registration","You have registered successfully.\nLogin to continue");
        return 1;
    }
    else if(regString == QString("REG0"))
    {
        QMessageBox::information(this,"Registration","Not Successful.\nTry Again!");
        return 0;
    }
    else
    {
         QMessageBox::information(this,"Registration","Server timed out!");
         return 0;
    }

}


/**
  *Used for sign in of registered user
  */
int TCPConnect::SignIN(QString userName, QString password)
{
    logString = "LOGIN "+userName+" "+password;
    socket->write(logString.toLocal8Bit().data());

    if(!socket->waitForBytesWritten(3000))
    {
        QMessageBox::information(this,"Error!",socket->errorString());
        return 0;
    }
    else
    {
        socket->waitForReadyRead(3000);
        logString = socket->readAll();
        if(logString == QString("LOGIN1"))
        {
            return 1;
        }
        else if(logString == QString("LOGIN0"))
        {
            QMessageBox::information(this,"Login","Incorrect password/username!");
            return 0;
        }
        else
        {
            QMessageBox::information(this,"Login","Server timed out!");
            return 0;
        }
    }
}


/**
  *Used for marking the current day
  */
void TCPConnect::mark()
{
    socket->write("MARK");

    if(!socket->waitForBytesWritten(3000))
    {
        QMessageBox::information(this,"Error!",socket->errorString());
    }

    socket->waitForReadyRead(3000);
    dayMark = socket->readAll();
    if(dayMark == QString("MARK1"))
    {
        QMessageBox::information(this,"Success","You have successfully updated the database");
    }
    else if(dayMark == QString("MARK0"))
    {
        QMessageBox::information(this,"Error!","Unable to mark!");
    }
    else
    {
        QMessageBox::information(this,"Error!","Server timed out!");
    }
}


/**
  *Day's status
  */
int TCPConnect::fetchDateStatus(QDate *d)
{
    QString day="", month="", year="";
    int dd,mm,yyyy;
    dd=d->day();
    mm=d->month();
    yyyy=d->year();
    day=day.append(QString("%1").arg(dd));
    month=month.append(QString("%1").arg(mm));
    year=year.append(QString("%1").arg(yyyy));
    if(dd<10&&mm<10)
        date = "DAY 0"+day+"/0"+month+"/"+year;
    else if(dd<10)
        date = "DAY 0"+day+"/"+month+"/"+year;
    else if(mm<10)
        date = "DAY "+day+"/0"+month+"/"+year;
    else
        date = "DAY "+day+"/"+month+"/"+year;


    socket->write(date.toLocal8Bit().data());

    if(!socket->waitForBytesWritten(3000))
    {
        QMessageBox::information(this,"Error!",socket->errorString());
    }

    socket->waitForReadyRead(3000);
    date = socket->readAll();
    if(date == QString("1"))
    {
        return 1;
    }
    else if(date == QString("0"))
    {
        return 0;
    }
    else
    {
        QMessageBox::information(this,"Error!","Server timed out!");
        return 0;
    }
}


/**
  *Month status
  */
int* TCPConnect::fetchMonthStatus(QDate *d)
{
    QString month="", year="";
    int mm,yyyy;
    mm=d->month();
    yyyy=d->year();

    mon = new int[d->daysInMonth()];

    month=month.append(QString("%1").arg(mm));
    year=year.append(QString("%1").arg(yyyy));

    if(mm<10)
            monthString = "MONTH 0"+month+"/"+year;
    else
        monthString = "MONTH "+month+"/"+year;

    socket->write(monthString.toLocal8Bit().data());

    if(!socket->waitForBytesWritten(3000))
    {
        QMessageBox::information(this,"Error!",socket->errorString());
    }

    socket->waitForReadyRead(3000);
    monthString = socket->readAll();
    if(monthString=="")
    {
        QMessageBox::information(this,"Error!","Server timed out!");
        return NULL;
    }
    else if(monthString.at(2*d->daysInMonth()-1)!=';')
    {
        QMessageBox::information(this,"Error!","Server error!");
        return NULL;
    }
    else
    {
        for(int i=0;i<d->daysInMonth();i++)
        {
            mon[i]=monthString.at(2*i).digitValue();
        }
        return mon;
    }
}













