#ifndef SUBLIMEINSTALL_H
#define SUBLIMEINSTALL_H

#include <QDialog>

namespace Ui {
class sublimeinstall;
}

class sublimeinstall : public QDialog
{
    Q_OBJECT

public:
    explicit sublimeinstall(QWidget *parent = nullptr);
    ~sublimeinstall();

private slots:
    void on_done_clicked();

    void on_sublimeproceed_clicked();

    void updatePB();

private:
    Ui::sublimeinstall *ui;
};

#endif // SUBLIMEINSTALL_H
