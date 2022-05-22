#include "memoryinfo.h"
#include<math.h>

MemoryInfo::MemoryInfo()
{
    QString buf = getInfoFromFile(file_ram, "MemTotal");
    buf = buf.split(" ",QString::SkipEmptyParts).at(0);
    this->total_mem = QString::number(round(double(buf.toInt()) / 1000));

    buf = getInfoFromFile(file_ram, "MemAvailable");
    buf = buf.split(" ",QString::SkipEmptyParts).at(0);
    this->available_mem = QString::number(round(double(buf.toInt()) / 1000));

    buf = getInfoFromFile(file_ram, "SwapTotal");
    buf = buf.split(" ", QString::SkipEmptyParts).at(0);
    this->swap_total = buf;

    buf = getInfoFromFile(file_ram, "SwapFree");
    buf = buf.split(" ", QString::SkipEmptyParts).at(0);
    this->swap_free = buf;
}


QString MemoryInfo::getTotalMemory()
{
    return this->total_mem;
}

QString MemoryInfo::getAvailableMemory()
{
    return this->available_mem;
}

QString MemoryInfo::getSwapTotal()
{
    return this->swap_total;
}

QString MemoryInfo::getSwapFree()
{
    return this->swap_free;
}



QString MemoryInfo::getInfoFromFile(QFile &file, const QString &param)
{
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream info(&file);
    QString line;
    do
    {
        line = info.readLine();
        if(line.contains(param))
        {
            file.close();
            return line.split(":").at(1);
        }
    }
    while(!line.isNull());
    file.close();
    return QString();
}
