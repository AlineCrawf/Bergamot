#ifndef SHOP_H
#define SHOP_H

#include <QMainWindow>
#include "addlaptop.h"
#include "addsmartphone.h"

namespace Ui {
class Shop;
}

class Shop : public QMainWindow
{
    Q_OBJECT

public:
    explicit Shop(QWidget *parent = nullptr);
    ~Shop();

private slots:
    void on_actionMy_account_triggered();

    void on_actionLaptop_triggered();

    void on_actionSmartphone_triggered();

    void on_actionMobile_triggered();

private:
    Ui::Shop *ui;
};

#endif // SHOP_H
