#include "pciinfo.h"

QString PciInfo::getFromLspci(const QString &attribute)
{
    char buffer[255];
    QString lspci_com = QString("lspci | ").append(attribute);
    command = popen(lspci_com.toStdString().c_str(), "r");
    fread(buffer, sizeof(buffer), 1, command);
    pclose(command);
    return QString(buffer);
}

PciInfo::PciInfo()
{
    QString audio = getFromLspci("grep -i audio");
    audioDevices = audio.split("\n");
    audioDevices.removeLast();
    for(auto &i : audioDevices)
    {
        i = i.split(":").at(2);
        i.chop(9);
    }

    QString gpu = getFromLspci("grep -i VGA");
    gpuDevices = gpu.split("\n");
    gpuDevices.removeLast();
    for(auto &i : gpuDevices)
    {
        i = i.split(":").at(2);
        i.chop(9);
    }

    QString netw = getFromLspci("grep -i Network");
    networkDevices = netw.split("\n");
    networkDevices.removeLast();
    for(auto &i : networkDevices)
    {
        i = i.split(":").at(2);
        i.chop(9);
    }
}

QStringList PciInfo::getAudioDevices()
{
    return audioDevices;
}

QStringList PciInfo::getGpuDevices()
{
    return gpuDevices;
}

QStringList PciInfo::getNetworkDevices()
{
    return networkDevices;
}
