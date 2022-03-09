#include "connection.h"

Connection::Connection()
{

}
bool Connection::createconnect()
{
db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("fares");//inserer le nom de la source de données ODBC
db.setUserName("fares");//inserer nom de l'utilisateur
db.setPassword("fares");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
void Connection::closeconnect(){db.close();}
