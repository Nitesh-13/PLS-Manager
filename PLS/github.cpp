#include "github.h"
#include "ui_github.h"
#include <QDesktopServices>

github::github(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::github)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

github::~github()
{
    delete ui;
}

void github::on_prof_Nit_clicked()
{
    QString nit_profile = "https://github.com/Nitesh-13";
    QDesktopServices::openUrl(QUrl(nit_profile));
}


void github::on_prof_Yash_clicked()
{
    QString yash_profile = "https://github.com/Yash71";
    QDesktopServices::openUrl(QUrl(yash_profile));
}

