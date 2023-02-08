#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    serial = new QSerialPort(this);
    serial->setPortName("COM1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadOnly);
    //serial->write("что-то будет, полагаю");
    
    connect(serial, SIGNAL(readyRead()), this, SLOT(serialRecieve()));
    
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        QSerialPort port;
        port.setPort(info);
        if (port.isOpen())
        {
            qDebug() << "Название: " + info.portName() + " " + info.description() + info.manufacturer();
        }
        
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    serial -> close();
    delete serial;
}

void MainWindow:: serialRecieve()
{
    QByteArray message;
    message = serial -> readAll();

    ui -> label -> setText(QString(message));
}

