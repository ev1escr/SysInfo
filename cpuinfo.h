#ifndef CPUINFO_H
#define CPUINFO_H

#include <QObject>
#include<QString>
#include<QTextStream>
#include<filesystem>
#include<QProcess>
#include<QFile>
#include<QTextCodec>
#include<QDebug>
#include<stdio.h>

class CpuInfo
{
private:
    QString name;
    QString cacheSize;
    QString coresAmount;
    QString mhz;
    QString cpuid;
public:
    CpuInfo();
    QString getName();
    QString getCacheSize();
    QString getCoresAmount();
    QString getMhz();
    QString getCPUID();
};

#endif // CPUINFO_H
