#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subscriptions.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QIntValidator>
#include "qcustomplot.h"
#include"exporttoexcelfile.h"
#include <iostream>
#include <QProgressBar>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    subscriptions Sub;
    ui->setupUi(this);
    ui->le_num_2->setValidator(new QIntValidator(0, 9999, this));
    ui->tab_subscriptions->setModel(Sub.read());
    ui->comboBox->setModel(Sub.read_id());
    ui->comboBox_2->setModel(Sub.read_buyer());

    QRegularExpression rx("\\b[1-9 A-Z]+[A-Z 1-9]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->le_type->setValidator(new QRegularExpressionValidator(rx, this));
    ui->le_type_modif->setValidator(new QRegularExpressionValidator(rx, this));
    QRegularExpression rx1("\\b[1-9 A-Z]+[A-Z 1-9]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->le_durt->setValidator(new QRegularExpressionValidator(rx1, this));
    ui->le_duration_modif->setValidator(new QRegularExpressionValidator(rx1, this));
    QRegularExpression rx2("\\b[0-9]+/[0-9]+/[0-9]+/[0-9]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->le_sdate->setValidator(new QRegularExpressionValidator(rx2, this));
    ui->le_sdate_modif->setValidator(new QRegularExpressionValidator(rx2, this));
    QRegularExpression rx3("\\b[0-9]+/[0-9]+/[0-9]+/[0-9]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->le_edate->setValidator(new QRegularExpressionValidator(rx3, this));
    ui->le_edate_modif->setValidator(new QRegularExpressionValidator(rx3, this));
    QRegularExpression rx4("\\b[0-9]+.+[0-9]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->le_price->setValidator(new QRegularExpressionValidator(rx4, this));
    ui->le_price_modif->setValidator(new QRegularExpressionValidator(rx4, this));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_add_clicked()
{
   // subscriptions Sub;
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
        //hist
        Sub.historique("A subscription is added : ",ui->le_num_2->text(),ui->le_type->text(),ui->le_durt->text(),ui->le_price->text(),ui->comboBox_2->currentText(),ui->le_sdate->text(),ui->le_edate->text());

}
    else
       {
        msgBox.setText("Failed to add.");
    Sub.historique2("Failed to add a subscription");
    }
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
        //hist
        QFile file("Historique.txt");
        if (file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream ecriture(&file);
            ecriture << "Subscription number "<< Sub1.getnum() << " is deleted" << endl;
            file.close();
        }
    }
    else
       {

        msgBox.setText("Failed to delete.");
    Sub1.historique2("Failed to delete a subscription");
    }
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
                     Sub.historique("A subscription is updated : ",ui->le_num_modif->text(),ui->le_type_modif->text(),ui->le_duration_modif->text(),ui->le_price_modif->text(),ui->le_idBuy_modif->text(),ui->le_sdate_modif->text(),ui->le_edate_modif->text());
                 }
                 else
                 {
                     msgBox.setText("Error ; can't update.");
                 Sub.historique2("Failed to update a subscription");
                 }
                 msgBox.exec();
}

void MainWindow::on_pb_read_clicked()
{
    subscriptions Sub1;
    ui->tab_subscriptions->setModel(Sub1.read());
    Sub1.historique2("List of subscriptions is displayed" );
}

//tris
void MainWindow::on_sortById_clicked()
{
    subscriptions Sub1;
    bool test=Sub1.sort_id();
    //verif:
     QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Successfully sorted.");
        ui->tab_subscriptions->setModel(Sub1.sort_id());
        Sub1.historique2("List of subscriptions is sorted by ID");
    }
    else
     {
        msgBox.setText("Failed to sort the list of subscriptions.");
        Sub1.historique2("Failed to sort the list of subscriptions");
    }
    msgBox.exec();
}

void MainWindow::on_sortByType_clicked()
{
    subscriptions Sub1;
    bool test=Sub1.sort_type();
    //verif:
     QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Successfully sorted.");
        ui->tab_subscriptions->setModel(Sub1.sort_type());
        Sub1.historique2("List of subscriptions is sorted by type");
    }
    else
    {
        msgBox.setText("Failed to sort the list of subscriptions.");
        Sub1.historique2("Failed to sort the list of subscriptions");
    }
    msgBox.exec();
}

void MainWindow::on_sortByPrice_clicked()
{
    subscriptions Sub1;
    bool test=Sub1.sort_price();
    //verif:
     QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Successfully sorted.");
        ui->tab_subscriptions->setModel(Sub1.sort_price());
        Sub1.historique2("List of subscriptions is sorted by price");
    }
    else
    {
        msgBox.setText("Failed to sort the list of subscriptions.");
        Sub1.historique2("Failed to sort the list of subscriptions");
    }
    msgBox.exec();
}

void MainWindow::on_numtosearch_textChanged(const QString &arg1)
{
    subscriptions Sub1;
    Sub1.cleartable(ui->tab_subscriptions);
    int num_sub=ui->numtosearch->text().toInt();
    Sub1.findNum(ui->tab_subscriptions, num_sub);
    QFile file("Historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream ecriture(&file);
        ecriture << "Search for subscription number "<< num_sub << endl;
        file.close();
    }
}

void MainWindow::on_typetosearch_textChanged(const QString &arg1)
{
    subscriptions Sub1;
    Sub1.cleartable(ui->tab_subscriptions);
    QString type_sub=ui->typetosearch->text();
    Sub1.findType(ui->tab_subscriptions, type_sub);
    QFile file("Historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream ecriture(&file);
        ecriture << "Search for subscription with type : "<< type_sub << endl;
        file.close();
    }
}

void MainWindow::on_startdatetosearch_textChanged(const QString &arg1)
{
    subscriptions Sub1;
    Sub1.cleartable(ui->tab_subscriptions);
    QString s_date_sub=ui->startdatetosearch->text();
    Sub1.findStartDate(ui->tab_subscriptions, s_date_sub);
    QFile file("Historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream ecriture(&file);
        ecriture << "Search for subscription with start date "<< s_date_sub << endl;
        file.close();
    }
}

//stats
void MainWindow::on_tabWidget_currentChanged(int index)
{
subscriptions Sub1;
                   // Background :
                  QLinearGradient gradient(0, 0, 0, 400);
                  gradient.setColorAt(0, QColor(90, 90, 90));
                  gradient.setColorAt(0.38, QColor(105, 105, 105));
                  gradient.setColorAt(1, QColor(70, 70, 70));
                  ui->plot->setBackground(QBrush(gradient));

                   // Bars:
                  QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
                  amande->setAntialiased(false);
                  amande->setStackingGap(1);

                   // Couleurs:
                  amande->setName("Repartition des types selon prix ");
                  amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
                  amande->setBrush(QColor(0, 168, 140));

                   // Axe des abscisses:
                  QVector<double> ticks;
                  QVector<QString> labels;
                  Sub1.statistique(&ticks,&labels);
                  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                  textTicker->addTicks(ticks, labels);
                  ui->plot->xAxis->setTicker(textTicker);
                  ui->plot->xAxis->setTickLabelRotation(60);
                  ui->plot->xAxis->setSubTicks(false);
                  ui->plot->xAxis->setTickLength(0, 4);
                  ui->plot->xAxis->setRange(0, 8);
                  ui->plot->xAxis->setBasePen(QPen(Qt::white));
                  ui->plot->xAxis->setTickPen(QPen(Qt::white));
                  ui->plot->xAxis->grid()->setVisible(true);
                  ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                  ui->plot->xAxis->setTickLabelColor(Qt::white);
                  ui->plot->xAxis->setLabelColor(Qt::white);
                  // Axe des ordonnées:
                  ui->plot->yAxis->setRange(0,500);
                  ui->plot->yAxis->setPadding(5);
                  ui->plot->yAxis->setLabel("Statistiques");
                  ui->plot->yAxis->setBasePen(QPen(Qt::white));
                  ui->plot->yAxis->setTickPen(QPen(Qt::white));
                  ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
                  ui->plot->yAxis->grid()->setSubGridVisible(true);
                  ui->plot->yAxis->setTickLabelColor(Qt::white);
                  ui->plot->yAxis->setLabelColor(Qt::white);
                  ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                  ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                  // Ajout des données:
                  QVector<double> PlaceData;
                  QSqlQuery q1("select SUM(price_sub) from SUBSCRIPTIONS where regexp_like(type_sub,'air conditioning');");
                  while (q1.next()) {
                                int  n = q1.value(0).toFloat();
                                PlaceData<< n;
                                QSqlQuery q2("select SUM(price_sub) from SUBSCRIPTIONS where regexp_like(type_sub,'electricity');");
                                while (q2.next()) {
                                              int  n = q2.value(0).toFloat();
                                              PlaceData<< n;
                                              QSqlQuery q3("select SUM(price_sub) from SUBSCRIPTIONS where regexp_like(type_sub,'plumbing');");
                                              while (q3.next()) {
                                                            int  n = q3.value(0).toFloat();
                                                            PlaceData<< n;
                                                              }
                                                }
                                  }
                  amande->setData(ticks, PlaceData);
                  // Legende:
                  ui->plot->legend->setVisible(true);
                  ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                  ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
                  ui->plot->legend->setBorderPen(Qt::NoPen);
                  QFont legendFont = font();
                  legendFont.setPointSize(10);
                  ui->plot->legend->setFont(legendFont);
                   // Interact:
                  ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

                  Sub1.historique2("Statistics is updated");

}

void MainWindow::on_pbExport_clicked()
{
    subscriptions Sub;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                            tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return ;
        QProgressBar progressBar;
            exportExcel  obj(fileName, "tabsub", ui->tab_subscriptions);

            // ordre des colonnes et la colonne à exporter
            obj.addField(0, "num", "char(20)") ;
            obj.addField(1, "type", "char(20)");
            obj.addField(2, "duration", "char(20)");
            obj.addField(3, "price", "char(20)");
            obj.addField(4, "idbuyer", "char(20)");
            obj.addField(5, "startdate", "char(20)");
            obj.addField(6, "enddate", "char(20)");

            int retVal = obj.export2Excel();
            if( retVal > 0)
            {
                QMessageBox::information(this, tr("Done"),
                                         QString( tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
                Sub.historique2("Export to Excel file");
            }
}

void MainWindow::on_pb_history_clicked()
{
    subscriptions Sub1;
    QFile file("Historique.txt");
    Sub1.historique2("Show Text History");
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::information(0,"info",file.errorString());
            QTextStream lecture(&file);
            ui->textBrowser->setText(lecture.readAll());
            QMessageBox::information(nullptr, QObject::tr("Text History is open"),
                        QObject::tr("Text History is successfully displayed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            file.close();
}



