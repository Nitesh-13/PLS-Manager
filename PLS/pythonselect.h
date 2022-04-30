#ifndef PYTHONSELECT_H
#define PYTHONSELECT_H

#include <QDialog>
#include <QPropertyAnimation>

namespace Ui {
class pythonselect;
}

class pythonselect : public QDialog
{
    Q_OBJECT

public:
    explicit pythonselect(QWidget *parent = nullptr);
    ~pythonselect();

private slots:
    void on_pythonproceed_clicked();

    void on_done_clicked();

    void updatePB();

private:
    Ui::pythonselect *ui;
};

#endif // PYTHONSELECT_H
