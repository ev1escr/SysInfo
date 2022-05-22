#include "cpuinfo.h"
CpuInfo::CpuInfo()
{
    char buffer[225];

    FILE *command = popen("cat /proc/cpuinfo | grep -m 1  'model name'", "r");
    if(command == NULL)
    {
        qDebug() << "Error openning a pipe";
        exit(-1);
    }
    fgets(buffer, 225, command);
    this->name = buffer;
    this->name = this->name.split(":", QString::SkipEmptyParts).at(1);
    this->name.chop(1);
    pclose(command);

    command = popen("cat /proc/cpuinfo | grep -m 1  'cache size'", "r");
    fgets(buffer, 225, command);
    this->cacheSize = buffer;
    this->cacheSize = this->cacheSize.split(":", QString::SkipEmptyParts).at(1);
    this->cacheSize.chop(1);
    pclose(command);

    command = popen("cat /proc/cpuinfo | grep -m 1  'cpu cores'", "r");
    fgets(buffer, 225, command);
    this->coresAmount = buffer;
    this->coresAmount = this->coresAmount.split(":", QString::SkipEmptyParts).at(1);
     this->coresAmount.chop(1);
    pclose(command);

    command = popen("cat /proc/cpuinfo | grep -m 1  stepping", "r");
    fgets(buffer, 225, command);
    this->cpuid = buffer;
    this->cpuid = this->cpuid.split(":", QString::SkipEmptyParts).at(1);
    this->cpuid.chop(1);
    pclose(command);

    command = popen("cat /proc/cpuinfo | grep -m 1  'cpu MHz'", "r");
    fgets(buffer, 225, command);
    this->mhz = buffer;
    this->mhz = this->mhz.split(":", QString::SkipEmptyParts).at(1);
    this->mhz.chop(1);
    pclose(command);


}

QString CpuInfo::getName()
{
    return name;
}

QString CpuInfo::getCacheSize()
{
    return cacheSize;
}

QString CpuInfo::getCoresAmount()
{
    return coresAmount;
}

QString CpuInfo::getMhz()
{
    return mhz;
}

QString CpuInfo::getCPUID()
{
    return cpuid;
}
