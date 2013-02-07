#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    networkStatus(0),
    loginStatus(0),
    signUpStatus(0)
{
    ui->setupUi(this);

    setWindowTitle("Seinfeld Calendar");


    task=0;
    selectedDate = QDate::currentDate();
    fontSize = 9;
    t = new int[31];

    centralWidget = new QWidget;

    dateLabel = new QLabel(tr("Month:"));
    yearLabel = new QLabel(tr("Year:"));
    monthCombo = new QComboBox;

    for (int month = 1; month <= 12; ++month)
        monthCombo->addItem(QDate::longMonthName(month));

    yearEdit = new QDateTimeEdit;
    yearEdit->setDisplayFormat("yyyy");
    yearEdit->setDateRange(QDate(1753, 1, 1), QDate(8000, 1, 1));

    monthCombo->setCurrentIndex(selectedDate.month() - 1);
    yearEdit->setDate(selectedDate);




    editor = new QTextBrowser;
    insertCalendar(t,31);

    connect(monthCombo, SIGNAL(activated(int)), this, SLOT(setMonth(int)));
    connect(yearEdit, SIGNAL(dateChanged(QDate)), this, SLOT(setYear(QDate)));


    controlsLayout = new QHBoxLayout;

    controlsLayout->addWidget(dateLabel);
    controlsLayout->addWidget(monthCombo);
    controlsLayout->addSpacing(24);
    controlsLayout->addStretch(1);
    controlsLayout->addWidget(yearLabel);
    controlsLayout->addWidget(yearEdit);


    button1 = new QPushButton("Yes");
    button2 = new QPushButton("No");

    button1->setDisabled(true);
    button2->setDisabled(true);

    connect(button1, SIGNAL(clicked()), this, SLOT(taskdone()));
    connect(button2,SIGNAL(clicked()),this,SLOT(undone()));

    label = new QLabel("Did you go to gym today?");

   // button1->setPalette(QPalette(Qt::green));

    bottomLayout = new QHBoxLayout;

    bottomLayout->addSpacing(50);
    bottomLayout->addWidget(label);
    bottomLayout->addSpacing(50);
    bottomLayout->addWidget(button1);
    bottomLayout->addWidget(button2);
    bottomLayout->addSpacing(225);

    centralLayout = new QVBoxLayout;
    centralLayout->addLayout(controlsLayout);
    centralLayout->addWidget(editor, 1);
    centralWidget->setLayout(centralLayout);
    centralLayout->addLayout(bottomLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    on_actionClose_Connection_triggered();

    delete ui;
}

void MainWindow::on_actionQuick_Connect_triggered()
{
        bool ok;
        newNetworkSetup = new NetworkSetup();
        newNetworkSetup->setModal(true);
        newNetworkSetup->show();
        newNetworkSetup->setWindowTitle("Network Setup");
        newNetworkSetup->exec();
        serverAddress = newNetworkSetup->serverAddress;
        serverPort = newNetworkSetup->serverPort;
        port = serverPort.toInt(&ok,10);
        if(ok==false)
            QMessageBox::information(this,"Error","Wrong port format");
        else
        {
            newTCPConnect = new TCPConnect(this,serverAddress,port);
            networkStatus=newTCPConnect->signal;
        }
        delete newNetworkSetup;
}

void MainWindow::on_actionLogin_triggered()
{
    newLogin = new Login();
    newLogin->setModal(true);
    newLogin->show();
    newLogin->setWindowTitle("Login");
    newLogin->exec();
    username = newLogin->userName;
    password = newLogin->password;
    if(networkStatus==1)
    {
        loginStatus=newTCPConnect->SignIN(username,password);

       // selectedDate=QDate::currentDate();
        t = newTCPConnect->fetchMonthStatus(&selectedDate);
        insertCalendar(t,selectedDate.daysInMonth());

        button1->setEnabled(true);
        button2->setEnabled(true);
    }
    else
        QMessageBox::information(this,"Error","Connect First!!!");
}



void MainWindow::on_actionSignUp_triggered()
{
    newLogin = new Login();
    newLogin->setModal(true);
    newLogin->show();
    newLogin->setWindowTitle("SignUP");
    newLogin->exec();
    username = newLogin->userName;
    password = newLogin->password;
    if(networkStatus==1)
    {
        signUpStatus=newTCPConnect->SignUP(username,password);
    }
    else
        QMessageBox::information(this,"Error","Connect First!!!");
}

void MainWindow::on_actionLogout_triggered()
{
    int temp;
    if(loginStatus==1)
    {
        temp = newTCPConnect->LogOut();
        if(temp==1)
            loginStatus=0;
    }
    else
        QMessageBox::information(this,"Logout Error","You need to Login first");
}

void MainWindow::on_actionClose_Connection_triggered()
{
    if(networkStatus==1)
    {
    newTCPConnect->closeConnection();
    networkStatus=0;
    loginStatus=0;
    delete newTCPConnect;
    }
}


///////////////////////////////////////////////////////////////////////////

void MainWindow::insertCalendar(int *t,int n)
{
   editor->clear();
   QTextCursor cursor = editor->textCursor();
   cursor.beginEditBlock();

   QDate date(selectedDate.year(), selectedDate.month(), 1);

   QTextTableFormat tableFormat;
   tableFormat.setAlignment(Qt::AlignHCenter);
   tableFormat.setBackground(QColor("#fedcba"));
   tableFormat.setCellPadding(2);
   tableFormat.setCellSpacing(4);
   QVector<QTextLength> constraints;
   constraints << QTextLength(QTextLength::PercentageLength, 14)
               << QTextLength(QTextLength::PercentageLength, 14)
               << QTextLength(QTextLength::PercentageLength, 14)
               << QTextLength(QTextLength::PercentageLength, 14)
               << QTextLength(QTextLength::PercentageLength, 14)
               << QTextLength(QTextLength::PercentageLength, 14)
               << QTextLength(QTextLength::PercentageLength, 14);
   tableFormat.setColumnWidthConstraints(constraints);

   QTextTable *table = cursor.insertTable(1, 7, tableFormat);




   QTextFrame *frame = cursor.currentFrame();
   QTextFrameFormat frameFormat = frame->frameFormat();
   frameFormat.setBorder(1);
   frame->setFrameFormat(frameFormat);

   QTextCharFormat format = cursor.charFormat();
   format.setFontPointSize(fontSize);

   QTextCharFormat boldFormat = format;
   boldFormat.setFontWeight(QFont::Bold);

   QTextCharFormat highlightedFormat = boldFormat;

   QTextCharFormat highlightedFormat1 = boldFormat;

   if(task==0) highlightedFormat.setBackground(Qt::yellow);
   else highlightedFormat.setBackground(Qt::green);

   for (int weekDay = 1; weekDay <= 7; ++weekDay) {
       QTextTableCell cell = table->cellAt(0, weekDay-1);
       QTextCursor cellCursor = cell.firstCursorPosition();
       cellCursor.insertText(QString("%1").arg(QDate::longDayName(weekDay)),
                             boldFormat);
   }

   table->insertRows(table->rows(), 1);

   while (date.month() == selectedDate.month()) {
       int weekDay = date.dayOfWeek();


       QTextTableCell cell = table->cellAt(table->rows()-1, weekDay-1);
       QTextCursor cellCursor = cell.firstCursorPosition();

       if (date == QDate::currentDate())
           cellCursor.insertText(QString("%1").arg(date.day()), highlightedFormat);
       else{
           if(date.day()<=n)
           if(t[date.day()-1]>0)
           {
               highlightedFormat1.setBackground(Qt::green);
               cellCursor.insertText(QString("%1").arg(date.day()), highlightedFormat1);
           }
           else
           {
               highlightedFormat1.clearBackground();
               cellCursor.insertText(QString("%1").arg(date.day()), highlightedFormat1);
           }
           else cellCursor.insertText(QString("%1").arg(date.day()), format);
       }
       date = date.addDays(1);
       if (weekDay == 7 && date.month() == selectedDate.month())
           table->insertRows(table->rows(), 1);
   }

   cursor.endEditBlock();
}

void MainWindow::setMonth(int month)
{
    if(loginStatus==0)
    {
        selectedDate = QDate(selectedDate.year(), month + 1, selectedDate.day());
        insertCalendar(t,selectedDate.daysInMonth());
    }
    else
    {
        selectedDate = QDate(selectedDate.year(), month + 1, selectedDate.day());
        t = newTCPConnect->fetchMonthStatus(&selectedDate);
        insertCalendar(t,selectedDate.daysInMonth());
    }
}

void MainWindow::setYear(QDate date)
{
    if(loginStatus==0)
    {
        selectedDate = QDate(date.year(), selectedDate.month(), selectedDate.day());
        insertCalendar(t,selectedDate.daysInMonth());
    }
    else
    {
        selectedDate = QDate(date.year(), selectedDate.month(), selectedDate.day());
        t = newTCPConnect->fetchMonthStatus(&selectedDate);
        insertCalendar(t,selectedDate.daysInMonth());
    }
}



void MainWindow::taskdone()
{
    if(loginStatus==1)
    {
        newTCPConnect->mark();
        selectedDate=QDate::currentDate();
        t = newTCPConnect->fetchMonthStatus(&selectedDate);
        insertCalendar(t,selectedDate.daysInMonth());
        button1->setDisabled(true);
        button2->setDisabled(true);
    }
}


void MainWindow::undone()
{
    if(loginStatus==1)
    {
        button1->setDisabled(true);
        button2->setDisabled(true);
    }
}

void MainWindow::on_actionGet_Your_Streak_triggered()
{
    if(loginStatus==1)
    {
        int curr,max;
        curr=newTCPConnect->fetchCurrentStreak();
        max = newTCPConnect->fetchMaxStreak();
        QMessageBox::information(this,"Streak","Your current streak "+QString::number(curr)+"\nYour maximum streak "+QString::number(max));
    }
    else
    {
        QMessageBox::information(this,"Error","You need to Login first") ;
    }
}
