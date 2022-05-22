#ifndef RAMINFO_H
#define RAMINFO_H
#include <QString>
#include <QFile>
#include <QDebug>
#include<QProcess>
#include<QStringList>


static QFile file_ram("/proc/meminfo");

class MemoryInfo
{
private:
    QString total_mem;
    QString available_mem;
    QString swap_total;
    QString swap_free;

public:

    MemoryInfo();
    QString getTotalMemory();
    QString getAvailableMemory();
    QString getSwapTotal();
    QString getSwapFree();

private:
    QString getInfoFromFile(QFile &file, const QString &param);
};

#endif // RAMINFO_H
