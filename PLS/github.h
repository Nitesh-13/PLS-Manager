#ifndef GITHUB_H
#define GITHUB_H

#include <QDialog>
#include <QDesktopServices>

namespace Ui {
class github;
}

class github : public QDialog
{
    Q_OBJECT

public:
    explicit github(QWidget *parent = nullptr);
    ~github();

private slots:
    void on_prof_Nit_clicked();

    void on_prof_Yash_clicked();

private:
    Ui::github *ui;
};

#endif // GITHUB_H
