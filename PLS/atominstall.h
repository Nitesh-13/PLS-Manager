#ifndef ATOMINSTALL_H
#define ATOMINSTALL_H

#include <QDialog>

namespace Ui {
class atominstall;
}

class atominstall : public QDialog
{
    Q_OBJECT

public:
    explicit atominstall(QWidget *parent = nullptr);
    ~atominstall();

private slots:
    void on_atomproceed_clicked();

    void on_done_clicked();

    void updatePB();

private:
    Ui::atominstall *ui;
};

#endif // ATOMINSTALL_H
