#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QCoreApplication::setOrganizationName("Konstantin Maleev");
    QCoreApplication::setOrganizationDomain("simplevolk.net");
    QCoreApplication::setApplicationName("TimeCounter");

    ui->setupUi(this);
    h=0;m=0;s=0;ms=0;
    time=new QTime(h,m,s,ms);
    date=new QDate();

    connect(ui->pB_time,SIGNAL(clicked()),this,SLOT(getTime()));
}

QTime MainWindow::getTime()
{
    qDebug()<<time->currentTime().toString();

    saveTime(time);
    return time->currentTime();

}

void MainWindow::saveTime(QTime *time)
{


    timemap.insertMulti(date->currentDate().toString(),time->currentTime());
    qDebug()<<timemap;
}

MainWindow::~MainWindow()
{
    delete ui;
}
