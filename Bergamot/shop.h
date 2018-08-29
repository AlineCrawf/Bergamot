#ifndef SHOP_H
#define SHOP_H

#include <QMainWindow>
#include "addlaptop.h"
#include "addsmartphone.h"
#include <user.h>

namespace Ui {
class Shop;
}

class Shop : public QMainWindow
{
    Q_OBJECT

public:
    explicit Shop(QWidget *parent = nullptr, User *user = nullptr);
    ~Shop();

private slots:
    void on_actionMy_account_triggered();

    void on_actionLaptop_triggered();

    void on_actionSmartphone_triggered();

    void on_actionMobile_triggered();

    void on_showButton_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_currentIndexChanged(int index);

    void on_okButton_clicked();

    void on_buyButton_clicked();

private:
    Ui::Shop *ui;
    User *user;
};

#endif // SHOP_H
