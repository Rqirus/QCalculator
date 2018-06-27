#include "mainwindow.h"
#include <QApplication>

/**
*@projectName    QCalculator
*@brief          Imitation Windows7 standard Calculator
*@author         Rqirus
*@date           2018/6/27
*/



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
