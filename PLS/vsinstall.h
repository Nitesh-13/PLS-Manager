#ifndef VSINSTALL_H
#define VSINSTALL_H

#include <QDialog>

namespace Ui {
class vsinstall;
}

class vsinstall : public QDialog
{
    Q_OBJECT

public:
    explicit vsinstall(QWidget *parent = nullptr);
    ~vsinstall();

private slots:
    void on_vsproceed_clicked();

    void on_done_clicked();

    void updatePB();

private:
    Ui::vsinstall *ui;
};

#endif // VSINSTALL_H
