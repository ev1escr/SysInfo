#include "mainwindow.h"
#include "cpuinfo.h"
#include "memoryinfo.h"
#include <QApplication>
#include<iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("System Info");
    w.show();
    return a.exec();
}
