#include "proceedtab.h"
#include "ui_proceedtab.h"

proceedTab::proceedTab(int envId,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::proceedTab)
{
    ui->setupUi(this);
    ui->progressBar->hide();
    switch (envId) {
    case 1:
        ui->proceedInfo->setText("Do you want to proceed to setup C/C++ Development Environment?");
        break;
    case 2:
        ui->proceedInfo->setText("Do you want to proceed to setup Java Development Environment?");
        break;
    case 3:
        ui->proceedInfo->setText("Do you want to proceed to setup Python Development Environment?");
        break;
    case 4:
        ui->proceedInfo->setText("Do you want to proceed to setup Atom Code Editor?");
        break;
    case 5:
        ui->proceedInfo->setText("Do you want to proceed to setup Sublime Text Editor?");
        break;
    case 6:
        ui->proceedInfo->setText("Do you want to proceed to setup Visual Studio Code Editor?");
        break;
    default:
        break;
    }
    this->envId = envId;

    QObject::connect(install, &downloader::data,this, &proceedTab::fileProgress);
    QObject::connect(install, &downloader::finished,this, &proceedTab::executeInstaller);
    QObject::connect(install, &downloader::filename,this, &proceedTab::setFilename);
}

void proceedTab::setupPath()
{
    switch (envId) {
    case 1:
        system("setx path \"%path%;C:\\LimeLight\\MinGW\\bin\" /m");
        break;
    case 2:
        system("setx path \"%path%;C:\\LimeLight\\Java\\jdk-17.0.1\\bin\" /m");
        break;
    default:
        break;
    }
}

proceedTab::~proceedTab()
{
    delete ui;
}

void proceedTab::on_btnProceed_clicked()
{
    ui->btnProceed->hide();
    ui->btnCancel->hide();
    ui->progressBar->show();

    if(envId == 1)
    {
        ui->proceedInfo->setText("C/C++ Development Environment is being downloaded and installed...");
        link = QUrl("https://cdn-132.anonfiles.com/T4bbUb87y1/180c0afe-1663660960/MinGW.exe");
        install->append(link);
    }
    else if(envId == 2)
    {
        ui->proceedInfo->setText("Java Development Environment is being downloaded and installed...");
        link = QUrl("https://cdn-102.anonfiles.com/fbcdUb80ya/de6cc2f6-1663660983/Java.exe");
        install->append(link);
    }
    else if(envId == 3)
    {
        ui->proceedInfo->setText("Python Development Environment is being downloaded and installed...");
        link = QUrl("https://www.python.org/ftp/python/3.10.6/python-3.10.6-amd64.exe");
        install->append(link);
    }
    else if(envId == 4)
    {
        ui->proceedInfo->setText("Atom Code Editor is being downloaded and installed...");
        link = QUrl("https://github.com/atom/atom/releases/download/v1.60.0/AtomSetup-x64.exe");
        install->append(link);
    }
    else if(envId == 5)
    {
        ui->proceedInfo->setText("Sublime text Editor is being downloaded and installed...");
        link = QUrl("https://download.sublimetext.com/sublime_text_build_4126_x64_setup.exe");
        install->append(link);
    }
    else if(envId == 6)
    {
        ui->proceedInfo->setText("Visual Studio Code Editor is being downloaded and installed...");
        link = QUrl("https://az764295.vo.msecnd.net/stable/e4503b30fc78200f846c62cf8091b76ff5547662/VSCodeSetup-x64-1.70.2.exe");
        install->append(link);
    }
    else{
        reject();
    }
}

void proceedTab::fileProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qint64 percent = (bytesReceived*100)/bytesTotal;
    ui->progressBar->setValue(percent);
}

void proceedTab::setFilename(QString filename)
{
    this->filename = filename;
}

void proceedTab::executeInstaller()
{
    QString folder = "C:/LimeLight";
    QDir mydir(folder);
    if(!mydir.exists())
    {
        mydir.mkpath(".");
    }
    QString path = QDir::currentPath();
    path = path + "/" + filename;
    ui->progressBar->setValue(99);

    QProcess *myProcess = new QProcess();
    connect(myProcess, qOverload<int, QProcess::ExitStatus>(&QProcess::finished), [myProcess, this]
    {
        finishedDownloading();
        myProcess->deleteLater();
    });
    myProcess->start(path);
}

void proceedTab::finishedDownloading()
{
    setupPath();
    QFile myfile;
    if(myfile.exists(filename))
    {
        QFile::remove(filename);
    }
    ui->progressBar->setValue(100);
    ui->btnCancel->show();
    ui->btnCancel->setText("Done");
    ui->progressBar->hide();
    switch (envId){
    case 1:
        ui->proceedInfo->setText("C/C++ Environment is installed successfully!");
        break;
    case 2:
        ui->proceedInfo->setText("Java Environment is installed successfully!");
        break;
    case 3:
        ui->proceedInfo->setText("Python Environment is installed successfully!");
        break;
    case 4:
        ui->proceedInfo->setText("Atom Code Editor is installed successfully!");
        break;
    case 5:
        ui->proceedInfo->setText("Sublime Text Editor is installed successfully!");
        break;
    case 6:
        ui->proceedInfo->setText("Visual Studio Code Editor is installed successfully!");
        break;
    default:
        break;
    }
}

