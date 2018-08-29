#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_okButton_clicked();

    void on_passwdEdit_textChanged(const QString &arg1);

    void on_reppassEdit_textChanged(const QString &arg1);

    void on_nameEdit_textChanged(const QString &arg1);

private:
    Ui::Registration *ui;
    QString to_hash(QString passwd);
};

#endif // REGISTRATION_H
