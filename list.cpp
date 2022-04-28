#include "list.h"
#include "activity.h"
#include "listmanager.h"
#include <QDate>
#include <QString>
#include <QDebug>
#include <vector>

List::List(){
}

List::List(QString name, QString type){
    this->name = name;
    this->type = type;
}

//List::~List(){
//   delete v;
//}

void List::setName(QString name){
   this->name = name;
}

void List::setType(QString type){
    this->type = type;
}

QString List::getName(){
    return name;
}

QString List::getType(){ // renvoie le type d'activité, ex : "Loisir", "Ecole"
    return type;
}

bool List::isEmpty(){
   return !(v.size()); // pour vérifier si le vecteur liste est vide ou non

}

void List::addActivity(Activity a){ // ajoute une activité au vecteur Liste
    v.push_back(a);
}

bool List::removeActivity(Activity a){
    // de l'activité passée en entrée m'appelle la removeActivity (QString n), où n = a.getName()
    // (qui à son tour appelle le MAIN REMOVE avec l'index trouvé)
    return removeActivity(a.getName());
}

bool List::removeActivity(int i){ // MAIN REMOVE
    //  saisir l'index de l'activité à supprimer, vérifier qu'il n'est pas vide
    // et élimine ensuite l'activité à l'indice i
    if( !isEmpty() ){
        if(i >= v.size() && i<0){
            return false;
        }
        v.erase(v.begin() + i);
        qDebug() << "L'activité a été supprimée";
        return true;
    } else {
        return false;
    }
}

bool List::removeActivity(QString n){ // booléen qui renvoie la méthode REMOVE MAIN ci-dessus avec
    //l'index obtenu à partir de findIndex (n) en entrée
    return removeActivity(findIndex(n));
}

int List::findIndex(QString n){ // renvoie l'index d'une activité,
    //faites défiler le vecteur jusqu'à ce que vous trouviez le nom que vous recherchez
    int j = -1;
    for(int i = 0; i<v.size(); i++){
        if(v[i].getName() == n){
            j = i;
            break;
        }
    }
    return j;
}

QString List::getNameAct(int i){
    QString a = v[i].getName();
    return a;
}

QString List::getAuthorAct(int i){
    QString a = v[i].getAuthor();
    return a;
}

QDate List::getDateAct(int i){
    QDate d = v[i].getDate();
    return d;
}

bool List::getImpAct(int i){
    int s = v[i].getImp();
    if (s==1){
        return true;
    }else{
        return false;
    }
}

bool List::isDone(int i){
    if (v[i].isDone()==true){
        return true;
    }else{
        return false;
    }
}

std::vector<QString> List::getNameList(){
    for (int i=0; i<v.size();i++){
     nameList.push_back(v[i].getName());
    }
}

int List::size(){
    return v.size();
}

void List::printListActivities(){ // méthode provisoire pour voir comment le code fonctionne
    //qDebug() << "je suis sur la liste";
    for (int i=0; i<v.size();i++){

    }
}

Activity* List::getActivity(int i){
    return &v.at(i);
}


