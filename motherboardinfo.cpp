#include "motherboardinfo.h"

MotherBoardInfo::MotherBoardInfo()
{
    char b[225];

    FILE *com = fopen("/sys/devices/virtual/dmi/id/board_vendor", "r");
    if(com == NULL)
    {
        qDebug() << "Error openning a pipe";
        exit(-1);
    }
    fgets(b, 225, com);
    fclose(com);
    manufacturer = QString(b).split("\n").at(0);

    com = fopen("/sys/devices/virtual/dmi/id/board_name", "r");
    fgets(b, 225, com);
    fclose(com);
    model = QString(b).split("\n").at(0);

    com = fopen("/sys/devices/virtual/dmi/id/board_version", "r");
    fgets(b, 225, com);
    version = QString(b).split("\n").at(0);
}

QString MotherBoardInfo::getManufacturer()
{
    return manufacturer;
}

QString MotherBoardInfo::getModel()
{
    return model;
}

QString MotherBoardInfo::getVersion()
{
    return version;
}
