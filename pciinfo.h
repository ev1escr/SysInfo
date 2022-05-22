#ifndef PCIINFO_H
#define PCIINFO_H
#include <QString>
#include <QStringList>

class PciInfo
{
private:
    QStringList audioDevices;
    QStringList gpuDevices;
    QStringList networkDevices;

    QString getFromLspci(const QString& attribute);
    FILE * command;
public:
    PciInfo();
    QStringList getAudioDevices();
    QStringList getGpuDevices();
    QStringList getNetworkDevices();
};
#endif // PCIINFO_H
