#include "cppselect.h"
#include "ui_cppselect.h"
#include <QPropertyAnimation>

cppselect::cppselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cppselect)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->pB->hide();
}

cppselect::~cppselect()
{
    delete ui;
}

void cppselect::on_done_clicked()
{
    hide();
}

void cppselect::on_cppProceed_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    ui->cppQuestion->setText("C/C++ Setup is being Installed on your Computer...");
    ui->cppProceed->hide();
    ui->pB->show();
    ui->done->hide();
    animation->setDuration(4000);
    animation->setStartValue(0);
    animation->setEndValue(69);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(updatePB()));
}

void cppselect::updatePB()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    int cpperror = system("installer.exe cpp");
    animation->setDuration(200);
    animation->setStartValue(ui->pB->value());
    animation->setEndValue(100);
    animation->start();
    ui->done->show();
    if(cpperror >= 1)
    {
        ui->cppQuestion->setText("An error occured! Please try uninstalling and reinstalling the Application.");
    }
    else{
        ui->cppProceed->setText("C++ Setup Successful!!!");
    }
    ui->done->setText("Done");
}

