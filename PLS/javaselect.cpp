#include "javaselect.h"
#include "ui_javaselect.h"
#include <QPropertyAnimation>

javaselect::javaselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::javaselect)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->pB->hide();
}

javaselect::~javaselect()
{
    delete ui;
}

void javaselect::on_javaproceed_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    ui->javaQuestion->setText("Java Setup is being Installed on your Computer...");
    ui->javaproceed->hide();
    ui->pB->show();
    ui->done->hide();
    animation->setDuration(4000);
    animation->setStartValue(0);
    animation->setEndValue(69);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(updatePB()));
}


void javaselect::on_done_clicked()
{
    hide();
}

void javaselect::updatePB()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pB,"value");
    int javaerror = system("installer.exe java");
    animation->setDuration(200);
    animation->setStartValue(ui->pB->value());
    animation->setEndValue(100);
    animation->start();
    ui->done->show();
    if(javaerror >= 1)
    {
        ui->javaQuestion->setText("An error occured! Please try uninstalling and reinstalling the Application.");
    }
    else{
        ui->javaQuestion->setText("Java Setup Successful!!!");
    }
    ui->done->setText("Done");
}
