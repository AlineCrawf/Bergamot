#ifndef ADDSMARTPHONE_H
#define ADDSMARTPHONE_H

#include <QDialog>

namespace Ui {
class Addsmartphone;
}
//hi
class Addsmartphone : public QDialog
{
    Q_OBJECT

public:
    explicit Addsmartphone(QWidget *parent = 0);
    ~Addsmartphone();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Addsmartphone *ui;
};

#endif // ADDSMARTPHONE_H
