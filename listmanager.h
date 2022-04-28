#ifndef LISTMANAGER_H
#define LISTMANAGER_H
#include "list.h"
#include "activity.h"
#include <QDate>
#include <vector>
#include <QString>


class ListManager{

public:
    ListManager();
    //~ListManager();
    void createList(QString name , QString type); //créer une liste à partir de 0
    bool removeList(QString n);
    bool removeList(int i);
    void printLists();
    bool isEmpty();
    List getActivitiesFromIndex(int i);
    std::vector<QString> getListNameFromIndex(int i);
    int returnSize();
    QString getNameAct(int i);

private:
    std::vector<List> u; // vecteur contenant des listes
    std::vector<QString> tm;
};

#endif // LISTMANAGER_H
