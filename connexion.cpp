#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Programme");
db.setUserName("Malek");//inserer nom de l'utilisateur
db.setPassword("esprit23");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
