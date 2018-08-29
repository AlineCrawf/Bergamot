#include "bergamot.h"
#include "ui_bergamot.h"
#include "registration.h"
#include "shop.h"
#include <QMessageBox>
#include <QFile>
#include <QRegExpValidator>
#include <QTextStream>
#

Bergamot::Bergamot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bergamot)
{
    ui->setupUi(this);
    QIcon icon("E:\\Programming\\Bergamot\\Bergamot\\bergamot-2.jpg");
    this->setWindowIcon(icon);
    this->setWindowTitle("Bergamot");
    QRegExp log_exp("^[a-zA-Z][a-zA-Z0-9-_\\.]{1,20}$");
    QRegExp passwd_exp ("^[a-zA-Z0-9]{1,20}$");
    QRegExpValidator *logval = new QRegExpValidator(log_exp,this);
    QRegExpValidator *passval = new QRegExpValidator(passwd_exp,this);
    ui->loginEdit->setValidator(logval);
    ui->passwordEdit->setValidator(passval);
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
    Registration *rg = new Registration();
    if(ui->loginEdit->text()==""||ui->passwordEdit->text()=="")
        QMessageBox::warning(this,"Error","Please enter all data");
    else
    {
        QFile users("E:\\Programming\\Bergamot\\Bergamot\\Users.txt");
        if(!users.open(QFile::ReadOnly|QFile::Text)/*||!user.open(QFile::ReadOnly|QFile::Text)*/)
        {
            QMessageBox::information(this,"Error","No such file");
        }
        else
        {
            QTextStream stream(&users);
            bool login = false;
            int a=1000000;
            while(a--)
            {
                QString buffer = stream.readLine();
                QStringList strl = buffer.split(" ");

                if(buffer=="") break;
                if(strl.at(0)==ui->loginEdit->text()&&strl.at(1)==rg->to_hash(ui->passwordEdit->text()))
                {
                    login=1;
                }
                 strl.clear();
            }
            users.close();
            if(login)
            {
                User *user = new User(ui->loginEdit->text(),0);
                Shop *shop = new Shop(nullptr,user);
                shop->show();
                this->close();
            }

            else
            {
                QMessageBox::warning(this,"Error","No such user");
            }
         }

    }
}

