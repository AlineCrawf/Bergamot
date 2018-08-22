#include "bergamot.h"
#include "ui_bergamot.h"
#include "registration.h"
#include "shop.h"

Bergamot::Bergamot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bergamot)
{
    ui->setupUi(this);
    QIcon icon("E:\\Programming\\Bergamot\\Bergamot\\bergamot-2.jpg");
    this->setWindowIcon(icon);
    this->setWindowTitle("Bergamot");
}

Bergamot::~Bergamot()
{
    delete ui;
}

void Bergamot::on_registButton_clicked()
{
    Registration *rg = new Registration;
    rg->show();
    this->close();
}

void Bergamot::on_loginButton_clicked()
{
    Shop *shop = new Shop;
    shop->show();
    this->close();
}
