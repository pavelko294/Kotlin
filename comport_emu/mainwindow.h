#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QThread>
#include "port.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void update();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

signals:
    void started();


private:
    Ui::MainWindow *ui;
    QSerialPort *portemu; 
    bool isWriting = true;
    QThread* thread;
    port *comport = new port();
    //port* comport;
    //QTimer *timer;
};

#endif // MAINWINDOW_H
