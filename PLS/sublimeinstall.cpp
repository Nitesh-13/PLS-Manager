#include "sublimeinstall.h"
#include "ui_sublimeinstall.h"
#include <QPropertyAnimation>

sublimeinstall::sublimeinstall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sublimeinstall)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->pB->hide();
}

sublimeinstall::~sublimeinstall()
{
    delete ui;
}

void sublimeinstall::on_done_clicked()
{
    hide();
}


void sublimeinstall::on_sublimeproceed_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    ui->sublimeQuestion->setText("Sublime Code Editor is being Installed on your Computer...");
    ui->sublimeproceed->hide();
    ui->pB->show();
    ui->done->hide();
    animation->setDuration(4000);
    animation->setStartValue(0);
    animation->setEndValue(69);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(updatePB()));
}

void sublimeinstall::updatePB()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    int sublimeerror = system("installer.exe sublime");
    animation->setDuration(200);
    animation->setStartValue(ui->pB->value());
    animation->setEndValue(100);
    animation->start();
    ui->done->show();
    if(sublimeerror >= 1)
    {
        ui->sublimeQuestion->setText("An error occured! Please try uninstalling and reinstalling the Application.");
    }
    else{
        ui->sublimeQuestion->setText("Sublime Editor Installed Successful!!!");
    }
    ui->done->setText("Done");
}

