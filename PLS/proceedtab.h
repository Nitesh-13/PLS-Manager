#ifndef PROCEEDTAB_H
#define PROCEEDTAB_H

#include <QDialog>
#include <QUrl>
#include <QProcess>
#include <windows.h>
#include <QMessageBox>
#include <QDir>
#include "downloader.h"

namespace Ui {
class proceedTab;
}

class proceedTab : public QDialog
{
    Q_OBJECT

public:
    explicit proceedTab(int envId,QWidget *parent = nullptr);
    void setupPath();
    ~proceedTab();

private slots:
    void on_btnProceed_clicked();
    void finishedDownloading();
    void fileProgress(qint64 bytesReceived, qint64 bytesTotal);
    void setFilename(QString filename);
    void executeInstaller();

private:
    Ui::proceedTab *ui;
    int envId;
    QUrl link;
    QString filename;

    downloader *install = new downloader(this);
};

#endif // PROCEEDTAB_H
