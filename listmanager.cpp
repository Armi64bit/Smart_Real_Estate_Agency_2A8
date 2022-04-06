#include "listmanager.h"
#include "list.h"
#include "activity.h"
#include <QDate>
#include <vector>
#include <QString>
#include <iostream>

ListManager::ListManager(){
}

//ListManager::~ListManager(){
//    delete u;
//}

void ListManager::printLists(){ // méthode provisoire de vérification
    for (int i=0; i<u.size();i++){
            qDebug() << u[i].getName() << " " << u[i].getType();
    }
}

bool ListManager::isEmpty(){ // pour vérifier si le vecteur ListManager est vide ou non
    return !(u.size()>0);
}

List ListManager::getActivitiesFromIndex(int i){
    return u[i];
}

std::vector<QString> ListManager::getListNameFromIndex(int i){
    tm = u[i].getNameList();
    return tm;
}

void ListManager::createList(QString name, QString type ){
    List nuovaLista(name, type);
    u.push_back(nuovaLista);
}

bool ListManager::removeList(QString n){ // supprime la liste à l'index i de même nom que celle passée avec le paramètre n
   if( !isEmpty() ){
       int j = -1;
       for(int i = 0; i<u.size(); i++){
           if(u[i].getName() == n){
               j = i;
                u.erase(u.begin() + i);
                qDebug() << "La liste a été supprimée";
            }else
                return false;
       }
    }
}

bool ListManager::removeList(int i){ // MAIN REMOVE
    if( !isEmpty() ){
        if(i >= u.size() && i<0){
            return false;
        }
        u.erase(u.begin() + i);
        qDebug() << "La liste a été supprimée";
        return true;
    } else {
        return false;
    }
}

int ListManager::returnSize(){
    return u.size();
}

QString ListManager::getNameAct(int i){
    QString a = u[i].getName();
    return a;
}
