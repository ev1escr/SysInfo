#include "osinfo.h"
#include<QDebug>
OSInfo::OSInfo()
{
    struct utsname name;
    uname(&name);
    this->machine = name.machine;
    this->release = name.release;
    this->sysname = name.sysname;
    this->version = name.version;
    this->nodename = name.nodename;
}

QString OSInfo::getSysName()
{
    return sysname;
}

QString OSInfo::getArch()
{
    return machine;
}

QString OSInfo::getNodeName()
{
    return nodename;
}

QString OSInfo::getRealese()
{
    return release;
}

QString OSInfo::getVersion()
{
    return version;
}
