#include "vsinstall.h"
#include "ui_vsinstall.h"
#include <QPropertyAnimation>

vsinstall::vsinstall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vsinstall)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->pB->hide();
}

vsinstall::~vsinstall()
{
    delete ui;
}

void vsinstall::on_vsproceed_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    ui->vsQuestion->setText("VSCode Editor is being Installed on your Computer...");
    ui->vsproceed->hide();
    ui->pB->show();
    ui->done->hide();
    animation->setDuration(4000);
    animation->setStartValue(0);
    animation->setEndValue(69);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(updatePB()));
}


void vsinstall::on_done_clicked()
{
    hide();
}

void vsinstall::updatePB()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    int vserror = system("installer.exe vscode");
    animation->setDuration(200);
    animation->setStartValue(ui->pB->value());
    animation->setEndValue(100);
    animation->start();
    ui->done->show();
    if(vserror >= 1)
    {
        ui->vsQuestion->setText("An error occured! Please try uninstalling and reinstalling the Application.");
    }
    else{
        ui->vsQuestion->setText("VSCode Editor Installed Successful!!!");
    }
    ui->done->setText("Done");
}

