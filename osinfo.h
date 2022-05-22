#ifndef OSINFO_H
#define OSINFO_H
#include <QString>
#include<sys/utsname.h>

class OSInfo
{
private:
    QString sysname;
    QString machine;
    QString nodename;
    QString release;
    QString version;
    QString manufacturer;

public:
    OSInfo();
    QString getSysName();
    QString getArch();
    QString getNodeName();
    QString getRealese();
    QString getVersion();
};

#endif // OSINFO_H
