#include "editors.h"
#include "ui_editors.h"

editors::editors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editors)
{
    ui->setupUi(this);
    ui->sselect->hide();
    ui->aselect->hide();
    int installstatus = system("code --version");
    if(installstatus != 0)
    {
        ui->installStatus->hide();
    }
    else{
        ui->installStatus->show();
    }
}

editors::~editors()
{
    delete ui;
}

bool editors::checkInternet()
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

void editors::on_vscode_clicked()
{
    ui->vselect->show();
    ui->sselect->hide();
    ui->aselect->hide();
    ui->recommended->show();
    ui->editorImage->setPixmap(QPixmap(":/assets/assets/vscode.png"));
    ui->editortitle->setText("Visual Studio Code");
    ui->editodescription->setText("Visual Studio Code is a code editor redefined and optimized for building and debugging modern web and cloud applications. Visual Studio Code is free and available on your favorite platform - Linux, macOS, and Windows.");
}


void editors::on_sublime_clicked()
{
    ui->installStatus->hide();
    ui->vselect->hide();
    ui->sselect->show();
    ui->aselect->hide();
    ui->recommended->hide();
    ui->editorImage->setPixmap(QPixmap(":/assets/assets/sublime.png"));
    ui->editortitle->setText("Sublime Text Editor");
    ui->editodescription->setText("Sublime Text is a sophisticated text editor for code, markup and prose. You'll love the slick user interface, extraordinary features and amazing performance.");
}


void editors::on_atom_clicked()
{
    ui->installStatus->hide();
    ui->vselect->hide();
    ui->sselect->hide();
    ui->aselect->show();
    ui->recommended->hide();
    ui->editorImage->setPixmap(QPixmap(":/assets/assets/atom.png"));
    ui->editortitle->setText("Atom Code Editor");
    ui->editodescription->setText("The comprehensive text editor for programmers, created by GitHub. GitHub is one of the best software development communities.");

}


void editors::on_vselect_clicked()
{
    if(checkInternet() == true)
    {
        proceedTab vscode(6,this);
        vscode.setModal(true);
        vscode.exec();
    }
    else{
        QMessageBox::critical(this,tr("Info"),tr("Not connected to Internet! Please connect and try again."));
    }
}


void editors::on_sselect_clicked()
{
    if(checkInternet() == true)
    {
        proceedTab sublime(5,this);
        sublime.setModal(true);
        sublime.exec();
    }
    else{
        QMessageBox::critical(this,tr("Info"),tr("Not connected to Internet! Please connect and try again."));
    }
}


void editors::on_aselect_clicked()
{
    if(checkInternet() == true)
    {
        proceedTab atom(4,this);
        atom.setModal(true);
        atom.exec();
    }
    else{
        QMessageBox::critical(this,tr("Info"),tr("Not connected to Internet! Please connect and try again."));
    }
}

