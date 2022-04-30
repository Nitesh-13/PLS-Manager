#ifndef JAVASELECT_H
#define JAVASELECT_H

#include <QDialog>

namespace Ui {
class javaselect;
}

class javaselect : public QDialog
{
    Q_OBJECT

public:
    explicit javaselect(QWidget *parent = nullptr);
    ~javaselect();

private slots:
    void on_javaproceed_clicked();

    void on_done_clicked();

    void updatePB();

private:
    Ui::javaselect *ui;
};

#endif // JAVASELECT_H
