#include "pythonselect.h"
#include "ui_pythonselect.h"
#include <QPropertyAnimation>

pythonselect::pythonselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pythonselect)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->pB->hide();
}

pythonselect::~pythonselect()
{
    delete ui;
}

void pythonselect::on_pythonproceed_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    ui->pythonQuestion->setText("Python Setup is being Installed on your Computer...");
    ui->pythonproceed->hide();
    ui->pB->show();
    ui->done->hide();
    animation->setDuration(4000);
    animation->setStartValue(0);
    animation->setEndValue(69);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(updatePB()));
}


void pythonselect::on_done_clicked()
{
    hide();
}

void pythonselect::updatePB()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    int pythonerror = system("installer.exe python");
    animation->setDuration(200);
    animation->setStartValue(ui->pB->value());
    animation->setEndValue(100);
    animation->start();
    ui->done->show();
    if(pythonerror >= 1)
    {
        ui->pythonQuestion->setText("An error occured! Please try uninstalling and reinstalling the Application.");
    }
    else{
        ui->pythonQuestion->setText("Python Setup Successful!!!");
    }
    ui->done->setText("Done");
}
