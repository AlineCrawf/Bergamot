#include "registration.h"
#include "ui_registration.h"
#include "bergamot.h"
#include <QMessageBox>
#include<QRegExpValidator>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    QIcon icon("E:\\Programming\\Bergamot\\Bergamot\\bergamot-2.jpg");
    this->setWindowIcon(icon);
    this->setWindowTitle("Bergamot");
    QRegExp log_exp("^[a-zA-Z][a-zA-Z0-9-_\\.]{1,20}$");
    QRegExp passwd_exp ("^[a-zA-Z0-9]{1,20}$");
    QRegExpValidator *logval = new QRegExpValidator(log_exp,this);
    QRegExpValidator *passval = new QRegExpValidator(passwd_exp,this);
    ui->nameEdit->setValidator(logval);
    ui->passwdEdit->setValidator(passval);
    ui->reppassEdit->setValidator(passval);
}

Registration::~Registration()
{
    delete ui;
}


void Registration::on_okButton_clicked()
{


    if(ui->passwdEdit->text()==""||ui->nameEdit->text()==""||ui->reppassEdit->text()=="")
    {
        ui->nameEdit->setStyleSheet((QString("QLineEdit {border-width: 2px;"
                                             "  border-style: solid; "
                                             "border-color: FireBrick;}")));
        ui->passwdEdit->setStyleSheet((QString("QLineEdit {border-width: 2px;"
                                               "  border-style: solid; "
                                               "border-color: FireBrick;}")));
        ui->reppassEdit->setStyleSheet((QString("QLineEdit {border-width: 2px;"
                                                "  border-style: solid; "
                                                "border-color: FireBrick;}")));
        QMessageBox::warning(this,"Error","Enter all data");
    }

    else if(ui->passwdEdit->text()!=ui->reppassEdit->text())
    {
        ui->passwdEdit->setStyleSheet((QString("QLineEdit {border-width: 2px;"
                                               "  border-style: solid; "
                                               "border-color: FireBrick;}")));
        ui->reppassEdit->setStyleSheet((QString("QLineEdit {border-width: 2px;"
                                                "  border-style: solid; "
                                                "border-color: FireBrick;}")));
        QMessageBox::warning(this,"Error","Passwords are not the same");
    }

    else
    {
        QFile User("E:\\Programming\\Bergamot\\Bergamot\\Users.txt");
        if(User.open(QIODevice::Append))
        {
           QTextStream fout (&User);
           fout<<ui->nameEdit->text();
           fout<<" ";
           fout<<this->to_hash(ui->passwdEdit->text());
           fout<<"\r\n";
            User.close();
        }
        QMessageBox::information(this,"Success","Registration was successfull");
        Bergamot *bg = new Bergamot;
        bg->show();
        this->close();
    }
}

void Registration::on_passwdEdit_textChanged(const QString &arg1)
{
    ui->nameEdit->setStyleSheet("border-color: black");
    ui->passwdEdit->setStyleSheet("border-color: black");
    ui->reppassEdit->setStyleSheet("border-color: black");
}

void Registration::on_reppassEdit_textChanged(const QString &arg1)
{
    ui->nameEdit->setStyleSheet("border-color: black");
    ui->passwdEdit->setStyleSheet("border-color: black");
    ui->reppassEdit->setStyleSheet("border-color: black");
}

void Registration::on_nameEdit_textChanged(const QString &arg1)
{
    ui->nameEdit->setStyleSheet("border-color: black");
    ui->passwdEdit->setStyleSheet("border-color: black");
    ui->reppassEdit->setStyleSheet("border-color: black");
}

QString Registration::to_hash(QString passwd)
{
        QByteArray ba = passwd.toUtf8();
        QString hash = QCryptographicHash::hash(ba, QCryptographicHash::Md5).toHex();
        return hash;
}
