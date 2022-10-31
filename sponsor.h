#ifndef SPONSOR_H
#define SPONSOR_H
#include <QString>
#include<QSqlQueryModel>

class Sponsor
{
public:
    Sponsor();
    Sponsor(int,int,QString,QString,QString,QString);
    int getmatri();
    int getmontant();
    QString getduree();
    QString getnom();
    QString getad();
    QString getemail();
    void setmatri(int);
    void setmontant(int);
    void setduree(QString);
    void setnom(QString);
    void setad(QString);
    void setemail(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();




private:
    int matri,montant;
    QString nom,ad,email,duree;
};

#endif // SPONSOR_H

