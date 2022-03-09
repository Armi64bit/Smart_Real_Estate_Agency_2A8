#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subscriptions.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    subscriptions Sub;
    ui->setupUi(this);
    ui->le_num_2->setValidator(new QIntValidator(100, 9999, this));
    ui->le_price->setValidator(new QIntValidator(100, 99999, this));
    ui->tab_subscriptions->setModel(Sub.read());
    ui->comboBox->setModel(Sub.read_id());
    ui->comboBox_2->setModel(Sub.read_buyer());

    QRegularExpression rx("\\b[1-9 A-Z]+[A-Z 1-9]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->le_type->setValidator(new QRegularExpressionValidator(rx, this));

    QRegularExpression rx1("\\b[1-9 A-Z]+[A-Z 1-9]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->le_durt->setValidator(new QRegularExpressionValidator(rx1, this));

    QRegularExpression rx2("\\b[0-9]+/[0-9]+/[0-9]+/[0-9]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->le_sdate->setValidator(new QRegularExpressionValidator(rx2, this));

    QRegularExpression rx3("\\b[0-9]+/[0-9]+/[0-9]+/[0-9]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->le_edate->setValidator(new QRegularExpressionValidator(rx3, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_add_clicked()
{
    int num_sub=ui->le_num_2->text().toInt();
    QString type_sub=ui->le_type->text();
    QString durat_sub=ui->le_durt->text();
    float price_sub=ui->le_price->text().toFloat();
    QString s_date=ui->le_sdate->text();
    QString e_date=ui->le_edate->text();
int idBuy= ui->comboBox_2->currentText().toInt();

    subscriptions Sub(num_sub,type_sub,durat_sub,price_sub,idBuy,s_date,e_date);
    bool tester=Sub.add();
    //verif:
     QMessageBox msgBox;
    if(tester)
    {
        msgBox.setText("Successfully added.");
        ui->tab_subscriptions->setModel(Sub.read());
        ui->comboBox->setModel(Sub.read_id());
        ui->comboBox_2->setModel(Sub.read_buyer());
    }
    else
        msgBox.setText("Failed to add.");
    msgBox.exec();
}

void MainWindow::on_pb_delete_clicked()
{
    subscriptions Sub1;
    Sub1.setnum(ui->comboBox->currentText().toInt());
    bool test=Sub1.deleteS(Sub1.getnum());
    //verif:
     QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Successfully deleted.");
        ui->tab_subscriptions->setModel(Sub1.read());
        ui->comboBox->setModel(Sub1.read_id());
    }
    else
        msgBox.setText("Failed to delete.");
    msgBox.exec();
}

void MainWindow::on_comboBox_currentIndexChanged(int id)
{
    id=ui->comboBox->currentText().toInt();
     QSqlQuery query;
    query.prepare("select * from subscriptions where num_sub=:id");
    query.bindValue(":id",id);
    if(query.exec())
    {
        while(query.next())
       {
       ui->le_num_modif->setText(query.value(0).toString());
       ui->le_type_modif->setText(query.value(1).toString());
       ui->le_duration_modif->setText(query.value(2).toString());
       ui->le_price_modif->setText(query.value(3).toString());
       ui->le_idBuy_modif->setText(query.value(4).toString());
       ui->le_sdate_modif->setText(query.value(5).toString());
       ui->le_edate_modif->setText(query.value(6).toString());
       }
    }
}

void MainWindow::on_pd_update_clicked()
{
        int num_sub=ui->le_num_modif->text().toInt();
        QString type_sub=ui->le_type_modif->text();
        QString durat_sub=ui->le_duration_modif->text();
        float price_sub=ui->le_price_modif->text().toFloat();
        int idBuy=ui->le_idBuy_modif->text().toInt();
        QString s_date=ui->le_sdate_modif->text();
        QString e_date=ui->le_edate_modif->text();

                 subscriptions Sub(num_sub,type_sub,durat_sub,price_sub,idBuy,s_date,e_date);
                 bool test2=Sub.update(Sub.getnum());
                 //verif:
                  QMessageBox msgBox;
                 if(test2)
                 {
                     msgBox.setText("Update successfully.");
                     ui->tab_subscriptions->setModel(Sub.read());
                     ui->comboBox->setModel(Sub.read_id());
                 }
                 else
                     msgBox.setText("Error ; can't update.");
                 msgBox.exec();
}


