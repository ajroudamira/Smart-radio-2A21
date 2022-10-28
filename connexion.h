#ifndef CONNECXON_H
#define CONNECXON_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connexion
{
public:
    Connexion();
    bool createconnect();
};

#endif // CONNEXION_H
