#include "atominstall.h"
#include "ui_atominstall.h"
#include <QPropertyAnimation>

atominstall::atominstall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::atominstall)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->pB->hide();
}

atominstall::~atominstall()
{
    delete ui;
}

void atominstall::on_atomproceed_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    ui->atomQuestion->setText("Atom Code Editor is being Installed on your Computer...");
    ui->atomproceed->hide();
    ui->pB->show();
    ui->done->hide();
    animation->setDuration(4000);
    animation->setStartValue(0);
    animation->setEndValue(69);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(updatePB()));
}


void atominstall::on_done_clicked()
{
    hide();
}

void atominstall::updatePB()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    int atomerror = system("installer.exe atom");
    animation->setDuration(200);
    animation->setStartValue(ui->pB->value());
    animation->setEndValue(100);
    animation->start();
    ui->done->show();
    if(atomerror >= 1)
    {
        ui->atomQuestion->setText("An error occured! Please try uninstalling and reinstalling the Application.");
    }
    else{
        ui->atomQuestion->setText("Atom Editor Installed Successful!!!");
    }
    ui->done->setText("Done");
}

