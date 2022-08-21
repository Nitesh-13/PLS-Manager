#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editors.h"
#include "github.h"
#include "proceedtab.h"
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QtWidgets>
#include <QtNetwork>
#include <QEventLoop>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    bool checkInternet();

    void on_cselect_clicked();

    void on_jselect_clicked();

    void on_pselect_clicked();

    void on_editors_clicked();

    void on_cpp_clicked();

    void on_actionC_C_triggered();

    void on_java_clicked();

    void on_actionJava_triggered();

    void on_actionPython_triggered();

    void on_python_clicked();

    void on_actionExit_triggered();

    void on_actionGithub_Repo_triggered();

    void on_actionGithub_Profile_triggered();

    void on_reportBug_triggered();

    void on_actionContact_Me_triggered();

    void on_actionVSCode_triggered();

    void on_actionSublime_triggered();

    void on_actionAtom_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
