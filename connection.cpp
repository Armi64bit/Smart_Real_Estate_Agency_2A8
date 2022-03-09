#include "connection.h"

Connection::Connection()
{}

bool Connection::createconnect()
{
db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("realestate");//inserer le nom de la source de données ODBC
db.setUserName("aziz");//inserer nom de l'utilisateur
db.setPassword("aziz");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
void Connection::closeconnect(){db.close();}
