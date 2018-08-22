#include "shop.h"
#include "useracc.h"
#include "ui_shop.h"

Shop::Shop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    this->setWindowTitle("Bergamot");
    QIcon icon("E:\\Programming\\Bergamot\\Bergamot\\bergamot-2.jpg");
    this->setWindowIcon(icon);
}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_actionMy_account_triggered()
{
    UserAcc *acc = new UserAcc;
    acc->show();
}

void Shop::on_actionLaptop_triggered()
{
    addLaptop *lt = new addLaptop;
    lt->show();
}

void Shop::on_actionSmartphone_triggered()
{
    Addsmartphone *smart = new Addsmartphone;
    smart->show();
}

