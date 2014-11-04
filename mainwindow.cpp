#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fxload/fxload.h"
#include <QProcess>
#include <QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
    QFile f(":/hantek6022be-firmware.hex");
    f.copy("/sdcard/hantek6022be-firmware.hex");

    QProcess root;
    root.start("su");
    root.waitForStarted(5000);
    root.start("/bin/bash");
    root.waitForStarted(1000);
    root.write("chmod -R 777 /dev/bus/usb/ \n");
    root.waitForFinished(1000);
    int deb;
    char *argvv[] = {"fxload", "-t", "fx2", "-d", "04b4:6022", "-i", "/sdcard/hantek6022be-firmware.hex",  NULL};
    int argcc = 7;


    deb = fxload(argcc, argvv);
    QString temp = QString::number(deb);
    ui->label->setText(temp);
}

void MainWindow::on_pushButton_2_clicked()
{
    QProcess root;
    root.start("su");
    root.waitForStarted(5000);
    root.start("/bin/bash");
    root.waitForStarted(1000);
    root.write("chmod -R 777 /dev/bus/usb/ \n");
    root.waitForFinished(1000);
    ui->label->setText("set");

}
