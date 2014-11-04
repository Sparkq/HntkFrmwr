#include "mainwindow.h"
#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;





    //label->setText (temp);
    w.show();

    return a.exec();
}
