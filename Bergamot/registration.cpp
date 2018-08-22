#include "registration.h"
#include "ui_registration.h"
#include "bergamot.h"
#include <QMessageBox>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    QIcon icon("E:\\Programming\\Bergamot\\Bergamot\\bergamot-2.jpg");
    this->setWindowIcon(icon);
    this->setWindowTitle("Bergamot");
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_okButton_clicked()
{
    if(ui->passwdEdit->text()!=ui->reppassEdit->text())
    {
        QMessageBox::warning(this,"Error","Passwords are not the same");
    }

    else
    {
        Bergamot *bg = new Bergamot;
        bg->show();
        this->close();
    }
}
