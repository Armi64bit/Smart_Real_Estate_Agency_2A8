#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::setProperty(Property P)
{
    ui->lineEdit_ID->setText(P.get_ID());
    ui->lineEdit_type_prop->setText(P.get_Type());

}
