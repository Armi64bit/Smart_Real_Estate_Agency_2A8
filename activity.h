#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <iostream>
#include <QDate>
#include <QString>
#include <QDebug>
#include "subactivity.h"



class Activity{

public:
    Activity();
    Activity(QString name, QString author, QDate date, bool imp);
    bool setDate(QDate d); //Setter methods
    void setName(QString name);
    void setAuthor(QString author);
    void setImp(bool imp);
    void setDone(bool done);
    QString getName(); //Getter methods
    QString getAuthor();
    QDate getDate();
    int getImp();
    std::vector<Subactivity> getSub(){
        return sottoattivita;
    }
    bool isDone();
    bool important();
    void setSubactivities(std::vector<Subactivity> s);
    bool removeSubactivity(int i);
    QString printSubactivities();
    bool isEmpty();
    QString descriptor(); //Contient le nom, la date et bool imp à ajouter à l'élément de tâche dans mainwindow.cpp


private:
    QString name;
    QString author;
    QDate dateActivity;
    bool imp;
    bool done;
    std::vector<Subactivity> sottoattivita; //vecteur de sous-tâche
};

#endif // ACTIVITY_H
