#include "port.h"
#include <QDebug>

port::port()
{  
    portemu = new QSerialPort(this);
    portemu->setPortName("COM1");
    portemu->setBaudRate(QSerialPort::Baud9600);
    portemu->setDataBits(QSerialPort::Data8);
    portemu->setParity(QSerialPort::NoParity);
    portemu->setStopBits(QSerialPort::OneStop);
    portemu->setFlowControl(QSerialPort::NoFlowControl);


}

// --- DECONSTRUCTOR ---
port::~port() {
    // free resources
}

// --- PROCESS ---
// Start processing data.
void port::process() {
    int i=0;
    QString msg;
    while (isWriting){
        i++;
        msg = QString::number(i);
        QByteArray message = msg.toUtf8();
        portemu->write(message);
        qDebug() << "Data is writing...";
        portemu->waitForBytesWritten(1000);
        Sleep(2000);
    }
    portemu->close();
    emit finished();
    qDebug() << "Writing is over";
}
void port::OpenPort(){
    portemu->open(QIODevice::ReadWrite);
    if(portemu->isOpen())
        qDebug() << "Port is open";
    else
        qDebug() << "Critical error";
}
void port::ClosePort()
{
    isWriting = false;
}
