#ifndef CPPSELECT_H
#define CPPSELECT_H

#include <QDialog>

namespace Ui {
class cppselect;
}

class cppselect : public QDialog
{
    Q_OBJECT

public:
    explicit cppselect(QWidget *parent = nullptr);
    ~cppselect();
private slots:
    void on_done_clicked();

    void updatePB();

    void on_cppProceed_clicked();

private:
    Ui::cppselect *ui;
};

#endif // CPPSELECT_H
