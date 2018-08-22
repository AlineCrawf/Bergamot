#include "useracc.h"
#include "ui_useracc.h"
#include <QIcon>

UserAcc::UserAcc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserAcc)
{
    ui->setupUi(this);
    QIcon icon("E:\\Programming\\Bergamot\\Bergamot\\bergamot-2.jpg");
    this->setWindowIcon(icon);
    this->setWindowTitle("Bergamot");
}

UserAcc::~UserAcc()
{
    delete ui;
}
