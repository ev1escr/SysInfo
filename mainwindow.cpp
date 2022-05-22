#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->cpu_name->setText(cpu.getName());
    ui->cpu_cache->setText(cpu.getCacheSize());
    ui->cpu_cores->setText(cpu.getCoresAmount());
    ui->cpu_mhz->setText(cpu.getMhz());

    QStringList audioDevices = pci.getAudioDevices();
    int pos = 1;
    for(auto &i : audioDevices)
    {
        QWidget * title = new QLabel(QString("Device ") + (pos + '0') + ':');
        ui->audio_layaout->addRow(title, new QLabel(i));
        pos++;
    }

    pos = 1;
    QStringList gpuDevices = pci.getGpuDevices();
    for(auto &i : gpuDevices)
    {
        QWidget * title = new QLabel(QString("Device ") + (pos + '0') + ':');
        ui->gpu_layout->addRow(title, new QLabel(i));
        pos++;
    }

    pos = 1;
    QStringList networkDevices = pci.getNetworkDevices();
    for(auto &i : networkDevices)
    {
        QWidget * title = new QLabel(QString("Device ") + (pos + '0') + ':');
        ui->network_layout->addRow(title, new QLabel(i));
        pos++;
    }

    ui->system_os->setText(os.getSysName());
    ui->system_machine->setText(os.getArch());
    ui->system_release->setText(os.getRealese());
    ui->system_version->setText(os.getVersion());
    ui->system_nodename->setText(os.getNodeName());

    ui->ram_totalmem->setText(mem.getTotalMemory());
    ui->ram_avaiblmem->setText(mem.getAvailableMemory());
    ui->ram_swaptotal->setText(mem.getSwapTotal());
    ui->ram_swapavaibl->setText(mem.getSwapFree());

    ui->mb_manufacturer->setText(mb.getManufacturer());
    ui->mb_model->setText(mb.getModel());
    ui->mb_version->setText(mb.getVersion());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_save_button_clicked()
{
   QString path = QFileDialog::getSaveFileName();
   qDebug() << path;
   QFile f(path.append(".txt"));
   f.open(QIODevice::WriteOnly | QIODevice::Text);
   QTextStream fs (&f);
   fs << "System info:\n\n" << "OS: " << os.getSysName()
      << "\nArchitecture: " << os.getArch() << "\nRelease: "
      << os.getRealese() << "\nVersion: " << os.getVersion()
      << "\nNodeName: " << os.getNodeName();

   fs << "\n\nMotherboard\n\n" << "Manufacturer: " << mb.getManufacturer()
      << "\nModel: " << mb.getModel() << "\nVersion: " << mb.getVersion();

   fs << "\n\nCPU:\n\n" << "Name: " << cpu.getName() << "\nCache Size: "
      << cpu.getCacheSize() << " KB\nCores Amount: " << cpu.getCoresAmount()
      << "\nMHz :" << cpu.getMhz();

   fs << "\n\nMemory\n\n" <<  "\nTotal memory(MB): "
      << mem.getTotalMemory() << "\nAvailable memory: " << mem.getAvailableMemory();

   fs << "\n\nPCI devices:\n\n" << pci.getAudioDevices().join("\n") << "\n" << pci.getGpuDevices().join("\n");
   f.close();
}
