#include "connection.h"
Connection::Connection()
{
}
bool Connection::createconnect()
{
bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("PROJET_2A21");
db.setUserName("AMIRAA");//inserer nom de l'utilisateur
db.setPassword("AMI123RA");//inserer mot de passe de cet utilisateur
if (db.open())
test=true;
    return  test;
}
void Connection::closeConnection()
{
    db.close();
}

