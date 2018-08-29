#include "shop.h"
#include "useracc.h"
#include "ui_shop.h"
#include <QTextStream>
#include <QMessageBox>
#include<QFile>

Shop::Shop(QWidget *parent, User* user) :
    QMainWindow(parent),
    ui(new Ui::Shop)
{
    this->user = user;
    ui->setupUi(this);
    this->setWindowTitle("Bergamot");
    QIcon icon("E:\\Programming\\Bergamot\\Bergamot\\bergamot-2.jpg");
    this->setWindowIcon(icon);
    QFile goodsList("E:\\Programming\\Bergamot\\Bergamot\\aaa.txt");
    QTextStream fout(&goodsList);
    fout<<user->Info();
}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_actionMy_account_triggered()
{
    UserAcc *acc = new UserAcc(nullptr,this->user);
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



void Shop::on_comboBox_currentIndexChanged(int index)
{


}

void Shop::on_okButton_clicked()
{
    QString file;
    ui->listWidget->clear();
    if(ui->comboBox->currentIndex()==1)
    {
        file = "E:\\Programming\\Bergamot\\Bergamot\\Smart.txt";
    }
    else if(ui->comboBox->currentIndex()==2)
    {
        file = "E:\\Programming\\Bergamot\\Bergamot\\Laptop.txt";
    }
        QFile goods(file);
        if(!goods.open(QIODevice::ReadOnly))
              return;

       QString line = goods.readAll();
       goods.close();
       ui->listWidget->addItems(line.split("\n"));

}

void Shop::on_buyButton_clicked()
{

    QFile goodsList("E:\\Programming\\Bergamot\\Bergamot\\aaa.txt");
    if(!goodsList.open(QFile::ReadOnly|QFile::Text)/*||!user.open(QFile::ReadOnly|QFile::Text)*/)
    {
        QMessageBox::information(this,"Error","No such file");
    }
    else
    {
    QTextStream fin(&goodsList);
    fin<<ui->listWidget->currentItem()->text()<<"\r\n";
    goodsList.close();
    }
}
