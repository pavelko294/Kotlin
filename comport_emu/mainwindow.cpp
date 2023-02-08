#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"
#include <port.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete portemu;
}

void MainWindow::on_pushButton_clicked()
{
    comport->OpenPort();
    //ui->portopen->setText(); // открытие порта по нажатию кнопки, сообщение об это пользователю
}

void MainWindow::on_pushButton_2_clicked() // отправка данных по ком-порту, пока порт открыт
{

    QThread *thread = new QThread();
    comport->moveToThread(thread);
    connect(thread, SIGNAL(started()), comport, SLOT(process()));
    connect(comport, SIGNAL(finished()), thread, SLOT(quit()));
    connect(comport, SIGNAL(finished()), comport, SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

void MainWindow::update(){
    ui->data->setText("123456789");
}
void MainWindow::on_pushButton_3_clicked()
{
    comport->ClosePort();// закрытие порта по нажатию кнопки
    ui->portopen->setText("Порт закрыт.");
}
