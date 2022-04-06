#include "dialog.h"
#include "ui_dialog.h"
#include "listmanager.h"
#include "list.h"
#include "activity.h"
#include "activityinfo.h"
#include <QDate>
#include <QErrorMessage>
#include <QMessageBox>
#include "mainwindow.h"
dialog::dialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dialog)
{
    ui->setupUi(this);
    listModel = new QStandardItemModel();
        this->setWindowTitle("ToDo List");
        lastRowSelectedList = 0;
        lastRowSelectedActivities = 0;
    }


dialog::~dialog()
{
    delete ui;
}

void dialog::on_newList_clicked(){ // cliquez sur le bouton "Create new list"
    lastRowSelectedList = arrayListe.size();
    newList = new newListWindow();
    QObject::connect(newList, SIGNAL(accepted()), this, SLOT(createItemList()));
        if(newList->exec() != 0){
        QString s = QString(newList->getName());  // Zone de nom
        QString r = QString(newList->getType()); // Zone de type
        arrayListe.push_back(List(s, r));
        updateListView();
        updateActivityView();
        }
}
void dialog::on_newAct_clicked(){ // cliquez sur button "Add new activity"
    lastRowSelectedActivities = arrayListe[lastRowSelectedList].size();
    newActivity = new newActivityWindow();
    newActivity->setDate();
    QObject::connect(newActivity,SIGNAL(accepted()), this, SLOT(createItemList()));
    if (arrayListe.size() == 0){
        QMessageBox::information(
            this,
            tr("Application Name"),
            tr("Insert a list first") );
    }
    else{
    if(newActivity->exec()!=0){
        int currentRow = ui->liste->currentRow(); // dans currentRow nous avons le numéro de liste
        QString n = QString(newActivity->getName()); // met en n le nom de la nouvelle activité
        QString a = QString(newActivity->getAuthor()); // insère l'auteur de la nouvelle activité
        QDate d = QDate(newActivity->getDate()); // met la date de création en d
        bool c = bool(newActivity->isImp()); // met en c imp
        Activity b(n, a, d, c); // Je crée une nouvelle entreprise qui prend s au nom
        if(b.setDate(d)==false){
            QMessageBox::information(
                this,
                tr("Application Name"),
                tr("Mauvaise date") );
            return;
        }
        arrayListe[currentRow].addActivity(b);
        updateActivityView();
        updateListView();
    }
    }
}

void dialog::updateActivityView(){
    ui->vistaLista->clear();
    int currentRow = ui->liste->currentRow();
    if(currentRow >= 0 && currentRow < arrayListe.size() ){
        for (int i=0;i<arrayListe[currentRow].size();i++){
            if ( arrayListe[currentRow].getActivity(i)->isDone() ){
            ui->vistaLista->addItem(arrayListe[currentRow].getActivity(i)->descriptor() + " " + "Done:☑️");
            updateListView();

            }else{
                   ui->vistaLista->addItem(arrayListe[currentRow].getActivity(i)->descriptor());
                 }
        }
    }
    ui->vistaLista->setCurrentRow( lastRowSelectedActivities );
}

void dialog::updateListView(){
    ui->liste->clear();
    for (int i=0;i<arrayListe.size();i++){
        List currentList = arrayListe.at(i);
        ui->liste->addItem( QString( currentList.getName() + "-" + currentList.getType() +" \t " + QVariant(currentList.size()).toString()));
    }
        ui->liste->setCurrentRow(lastRowSelectedList);
}

void dialog::on_liste_clicked(const QModelIndex &index){
    lastRowSelectedList = ui->liste->currentRow();
    lastRowSelectedActivities = 0;
    updateActivityView();
}

void dialog::on_vistaLista_itemDoubleClicked(QListWidgetItem *item){
    lastRowSelectedActivities = ui->vistaLista->currentRow();
    windowActivity = new activityinfo();
    QObject::connect(windowActivity, SIGNAL(accepted()), this, SLOT(updateListView()));

    int currentActivityRow = ui->vistaLista->currentRow();
    int currentListRow = ui->liste->currentRow();

    windowActivity->setName(arrayListe[currentListRow].getNameAct(currentActivityRow));
    windowActivity->setAutore(arrayListe[currentListRow].getAuthorAct(currentActivityRow));
    windowActivity->setSubactivities(arrayListe[currentListRow].getActivity(currentActivityRow)->getSub());
    QDate d = arrayListe[currentListRow].getDateAct(currentActivityRow);
    windowActivity->setDate(d);
    windowActivity->updateSubactivitiesView();
    windowActivity->setDone( arrayListe[currentListRow].getActivity(currentActivityRow)->isDone() );

    if (arrayListe[currentListRow].getImpAct(currentActivityRow)==true){
        windowActivity->isImp();
    }
    windowActivity->exec();
        arrayListe[currentListRow].getActivity(currentActivityRow)->setName(windowActivity->getName());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setAuthor(windowActivity->getAuthor());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setDate(windowActivity->getDate());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setImp(windowActivity->getImp());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setSubactivities(windowActivity->getSub());
        arrayListe[currentListRow].getActivity(currentActivityRow)->setDone(windowActivity->Done());
        updateActivityView();
}

void dialog::on_deleteActivity_clicked(){
    lastRowSelectedActivities = arrayListe[lastRowSelectedList].size()-1;
    int currentActivityRow = ui->vistaLista->currentRow();
    int currentListRow = ui->liste->currentRow();
    if( arrayListe[currentListRow].size() <= 0){
        return;
    }
    arrayListe[currentListRow].removeActivity(currentActivityRow);
    updateActivityView();
    updateListView();
    ui->vistaLista->setCurrentRow( arrayListe[currentListRow].size()-1 );
}
void dialog::on_deleteList_clicked(){
    if( arrayListe.size() > 0 ){
        int currentListRow = ui->liste->currentRow();
        arrayListe.erase(arrayListe.begin() + currentListRow);
        updateListView();
        updateActivityView();
        ui->liste->setCurrentRow(arrayListe.size()-1);
    }
}

void dialog::on_liste_itemDoubleClicked(QListWidgetItem *item){
    newActivity = new newActivityWindow();
    newActivity->setDate();
    QObject::connect(newActivity,SIGNAL(accepted()), this, SLOT(createItemList()));
    if (arrayListe.size() == 0){
        QMessageBox::information(
            this,
            tr("Application Name"),
            tr("Insert a list first") );
    }
    else{
    if(newActivity->exec()!=0){
        int currentRow = ui->liste->currentRow(); // in currentRow we have the list number
        QString n = QString(newActivity->getName()); // puts in n the name of the new activity
        QString a = QString(newActivity->getAuthor()); // puts in the author of the new activity
        QDate d = QDate(newActivity->getDate()); // puts the created date in d
        bool c = bool(newActivity->isImp()); // puts in c imp
        Activity b(n, a, d, c); // I create a new business that takes s to the name
        if(b.setDate(d)==false){
            QMessageBox::information(
                this,
                tr("Application Name"),
                tr("Mauvaise Date") );
            return;
        }
        arrayListe[currentRow].addActivity(b);
        updateActivityView();
        updateListView();
    }
    }
}

void dialog::on_return_2_clicked()
{
    this->hide();
    MainWindow * newmain = new MainWindow();
    newmain->show();
}
