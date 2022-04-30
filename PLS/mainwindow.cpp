#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editors.h"
#include "cppselect.h"
#include "javaselect.h"
#include "pythonselect.h"
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QtWidgets>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    this->statusBar()->setSizeGripEnabled(false);
    this->statusBar()->hide();
    ui->java->hide();
    ui->python->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkInternet()
{
    QNetworkAccessManager nam;
    QNetworkRequest req(QUrl("http://www.google.com"));
    QNetworkReply* reply = nam.get(req);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if (reply->bytesAvailable())
        return true;
    else
        return false;
}

void MainWindow::on_cselect_clicked()
{
    ui->langImage->setPixmap(QPixmap(":/assets/assets/cpp.png"));
    ui->title->setText("C/C++");
    ui->description->setText("C++ is a popular programming language. C++ is used to create computer programs, and is one of the most used language in game development.");
    ui->cpp->show();
    ui->java->hide();
    ui->python->hide();
}

void MainWindow::on_jselect_clicked()
{
    ui->langImage->setPixmap(QPixmap(":/assets/assets/java.png"));
    ui->title->setText("Java");
    ui->description->setText("Java is a programming language and computing platform first released by Sun Microsystems in 1995.");
    ui->java->show();
    ui->python->hide();
    ui->cpp->hide();
}

void MainWindow::on_pselect_clicked()
{
    ui->langImage->setPixmap(QPixmap(":/assets/assets/python.png"));
    ui->title->setText("Python");
    ui->description->setText("Python is a high-level, general-purpose programming language. Its design philosophy emphasizes code readability with the use of significant indentation.");
    ui->python->show();
    ui->cpp->hide();
    ui->java->hide();
}


void MainWindow::on_editors_clicked()
{
    editors editors;
    editors.setModal(true);
    editors.exec();
}


void MainWindow::on_cpp_clicked()
{
    if(checkInternet() == true)
    {
        cppselect cpp;
        cpp.setModal(true);
        cpp.exec();
    }
    else{
        QMessageBox::critical(this,tr("Info"),tr("Not connected to Internet! Please connect and try again."));
    }
}


void MainWindow::on_actionC_C_triggered()
{
    if(checkInternet() == true)
    {
        cppselect cpp;
        cpp.setModal(true);
        cpp.exec();
    }
    else{
        QMessageBox::critical(this,tr("Info"),tr("Not connected to Internet! Please connect and try again."));
    }
}


void MainWindow::on_java_clicked()
{
    if(checkInternet() == true)
    {
        javaselect java;
        java.setModal(true);
        java.exec();
    }
    else{
        QMessageBox::critical(this,tr("Info"),tr("Not connected to Internet! Please connect and try again."));
    }
}


void MainWindow::on_actionJava_triggered()
{
    if(checkInternet() == true)
    {
        javaselect java;
        java.setModal(true);
        java.exec();
    }
    else{
        QMessageBox::critical(this,tr("Info"),tr("Not connected to Internet! Please connect and try again."));
    }
}


void MainWindow::on_actionPython_triggered()
{
    if(checkInternet() == true)
    {
        pythonselect python;
        python.setModal(true);
        python.exec();
    }
    else{
        QMessageBox::critical(this,tr("Info"),tr("Not connected to Internet! Please connect and try again."));
    }
}


void MainWindow::on_python_clicked()
{
    if(checkInternet() == true)
    {
        pythonselect python;
        python.setModal(true);
        python.exec();
    }
    else{
        QMessageBox::critical(this,tr("Info"),tr("Not connected to Internet! Please connect and try again."));
    }
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}


void MainWindow::on_actionGithub_Repo_triggered()
{
    QString repolink = "https://github.com/Nitesh-13/Language-Compiler-Setup";
    QDesktopServices::openUrl(QUrl(repolink));
}


void MainWindow::on_actionGithub_Profile_triggered()
{
    QString profilelink = "https://github.com/Nitesh-13";
    QDesktopServices::openUrl(QUrl(profilelink));
}


void MainWindow::on_actionAbout_Me_triggered()
{
    QMessageBox::information(this,tr("About Me"),tr("I am Nitesh, a coding enthusiast and a CSE Student"));
}


void MainWindow::on_actionContact_Me_triggered()
{
    QMessageBox::information(this,tr("Contact Me"),tr("Contact me at niteshmali132002@gmail.com"));
}

