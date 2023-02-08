#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include "windows.h"

class port : public QObject {
    Q_OBJECT

public:
    port();
    ~port();

public slots:
    void process();
    void ClosePort();
    void OpenPort();

signals:
    void finished();

private:
    // add your variables here
     QSerialPort *portemu;
     bool isWriting = true;
     QString message;

};
#endif // PORT_H
