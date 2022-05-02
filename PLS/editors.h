#ifndef EDITORS_H
#define EDITORS_H

#include <QDialog>

namespace Ui {
class editors;
}

class editors : public QDialog
{
    Q_OBJECT

public:
    explicit editors(QWidget *parent = nullptr);
    ~editors();

private slots:
    bool checkInternet();

    void on_vscode_clicked();

    void on_sublime_clicked();

    void on_atom_clicked();

    void on_vselect_clicked();

    void on_sselect_clicked();

    void on_aselect_clicked();

private:
    Ui::editors *ui;
};

#endif // EDITORS_H
