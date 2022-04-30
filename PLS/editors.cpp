#include "editors.h"
#include "ui_editors.h"
#include "vsinstall.h"
#include "sublimeinstall.h"
#include "atominstall.h"

editors::editors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editors)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->sselect->hide();
    ui->aselect->hide();
}

editors::~editors()
{
    delete ui;
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
    vsinstall vscode;
    vscode.setModal(true);
    vscode.exec();
}


void editors::on_sselect_clicked()
{
    sublimeinstall sublime;
    sublime.setModal(true);
    sublime.exec();
}


void editors::on_aselect_clicked()
{
    atominstall atom;
    atom.setModal(true);
    atom.exec();
}

