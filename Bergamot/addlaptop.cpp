#include "addlaptop.h"
#include "ui_addlaptop.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QRegExpValidator>

addLaptop::addLaptop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addLaptop)
{
    ui->setupUi(this);
    this->setWindowTitle("Bergamot");
    QIcon icon("E:\\Programming\\Bergamot\\Bergamot\\bergamot-2.jpg");
    this->setWindowIcon(icon);

    QRegExp comp_exp("^[a-zA-Z]{1,20}&");
    QRegExp name_exp("^[a-zA-Z][a-zA-Z0-9-_\\.]{1,20}$");
    QRegExp price_exp ("^[0-9]{1,20}$");
    QRegExp maxdisc_exp("[0-9]{1,}");
    QRegExp diag_exp ("[0-9]{1,}[?,][0-9]{0,4}");
    QRegExp weight_exp ("[0-9]{1,}[?,][0-9]{0,4}");
    QRegExp proc_exp ("[a-zA-Z]{1,}");
    QRegExp memory_exp("[0-9]{1,}");
    QRegExpValidator *comval = new QRegExpValidator(comp_exp,this);
    QRegExpValidator *nameval = new QRegExpValidator(name_exp,this);
    QRegExpValidator *priceval = new QRegExpValidator(price_exp,this);
    QRegExpValidator *maxdiscval = new QRegExpValidator(maxdisc_exp,this);
    QRegExpValidator *diagval = new QRegExpValidator(diag_exp,this);
    QRegExpValidator *weightval = new QRegExpValidator(weight_exp,this);
    QRegExpValidator *proccval = new QRegExpValidator(proc_exp,this);
    QRegExpValidator *memval = new QRegExpValidator(memory_exp,this);
    ui->compEdit->setValidator(comval);
    ui->modelEdit->setValidator(nameval);
    ui->priceEdit->setValidator(priceval);
    ui->maxDiscEdit->setValidator(maxdiscval);
    ui->diagEdit->setValidator(diagval);
    ui->weightEdit->setValidator(weightval);
    ui->procEdit->setValidator(proccval);
    ui->memEdit->setValidator(memval);
}

addLaptop::~addLaptop()
{
    delete ui;
}

void addLaptop::on_okButton_clicked()
{
    QFile fgoods("D:\\QWERTY\\Laptops.txt");
    if(ui->compEdit->text()==""||ui->diagEdit->text()==""||ui->maxDiscEdit->text()==""||ui->memEdit->text()==""||ui->modelEdit->text()==""||ui->procEdit->text()==""||ui->priceEdit->text()=="")
    {
        QMessageBox::warning(this,"Error","Enter all data");
    }
    else{
    if(fgoods.open(QIODevice::Append))
    {
       QTextStream fout(&fgoods);
       fout<<ui->compEdit->text();
       fout<<" ";
       fout<<ui->modelEdit->text();
       fout<<" ";
       fout<<ui->priceEdit->text();
       fout<<" ";
       fout<<ui->maxDiscEdit->text();
       fout<<" ";
       fout<<ui->diagEdit->text();
       fout<<" ";
       fout<<ui->weightEdit->text();
       fout<<" ";
       fout<<ui->procEdit->text();
       fout<<" ";
       fout<<ui->memEdit->text();
       fout<<"\r\n";
        fgoods.close();
    }
    else{
        QMessageBox::warning(this,"Error","No such file");
    }
    this->close();
    }
}
