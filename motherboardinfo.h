#ifndef MOTHERBOARDINFO_H
#define MOTHERBOARDINFO_H
#include <QString>
#include <QDebug>
#include <QStringList>
class MotherBoardInfo
{
private:
    QString manufacturer;
    QString model;
    QString version;

public:
    MotherBoardInfo();
    QString getManufacturer();
    QString getModel();
    QString getVersion();
};

#endif // MOTHERBOARDINFO_H
