#include "addsmartphone.h"
#include "ui_addsmartphone.h"
#include <QRegExpValidator>
#include <QFile>
#include <QRegExpValidator>
#include <QTextStream>
#include <QMessageBox>

Addsmartphone::Addsmartphone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addsmartphone)
{
    ui->setupUi(this);
    this->setWindowTitle("Bergamot");
    QIcon icon("E:\\Programming\\Bergamot\\Bergamot\\bergamot-2.jpg");
    this->setWindowIcon(icon);

    QRegExp comp_exp("^[a-zA-Z]{1,20}&");
    QRegExp name_exp("^[a-zA-Z][a-zA-Z0-9-_\\.]{1,20}$");
    QRegExp price_exp ("^[0-9]{1,20}$");
    QRegExp maxdisc_exp("[0-9]{1,}");
    QRegExp os_exp("^[a-zA-Z][a-zA-Z0-9]{1,20}$");
    QRegExp prog_exp("^[a-zA-Z]{1,20}[,]{0,1}[a-zA-Z]&");
    QRegExpValidator *comval = new QRegExpValidator(comp_exp,this);
    QRegExpValidator *nameval = new QRegExpValidator(name_exp,this);
    QRegExpValidator *priceval = new QRegExpValidator(price_exp,this);
    QRegExpValidator *maxdiscval = new QRegExpValidator(maxdisc_exp,this);
    QRegExpValidator *osval = new QRegExpValidator(os_exp,this);
    QRegExpValidator *progval = new QRegExpValidator(prog_exp,this);
    ui->compEdit->setValidator(comval);
    ui->modelEdit->setValidator(nameval);
    ui->priceEdit->setValidator(priceval);
    ui->maxDiscEdit->setValidator(maxdiscval);
    ui->OSEdit->setValidator(osval);
    ui->OSEdit->setValidator(progval);
}

Addsmartphone::~Addsmartphone()
{
    delete ui;
}

void Addsmartphone::on_pushButton_clicked()
{
    if(ui->compEdit->text()==""||ui->modelEdit->text()==""||ui->priceEdit->text()==""||ui->maxDiscEdit->text()==""||ui->OSEdit->text()==""||ui->ProgEdit->text()=="")
    {
        QMessageBox::warning(this,"Error","Enter all data");
    }
    else{
        QFile fgoods("E:\\Programming\\Bergamot\\Bergamot\\Smart.txt");
        if(fgoods.open(QIODevice::Append))
        {
            QTextStream fout(&fgoods);
            fout<<"\r\n";
            fout<<ui->compEdit->text();
            fout<<" ";
            fout<<ui->modelEdit->text();
            fout<<" ";
            fout<<ui->priceEdit->text();
            fout<<" ";
            fout<<ui->maxDiscEdit->text();
            fout<<" ";
            fout<<ui->OSEdit->text();
            fout<<" ";
            fout<<ui->ProgEdit->text();
            fgoods.close();
        }
        else{
            QMessageBox::warning(this,"Error","No such file");
        }
        this->close();
    }
}
