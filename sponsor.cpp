#include "sponsor.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
Sponsor::Sponsor()
{
matri=0;
nom=" ";ad=" ";email=" ",duree=" ",montant=0;
}

Sponsor::Sponsor(int matri,int montant,QString duree,QString nom,QString ad,QString email)
{this->matri=matri;this->duree=duree,this->montant=montant;this->nom=nom;this->ad=ad;this->email=email ;}
int Sponsor::getmatri(){return matri;}
QString Sponsor::getduree(){return duree ;}
int Sponsor::getmontant(){return montant ;}
QString Sponsor::getnom(){return nom;}
QString Sponsor::getad(){return ad;}
QString Sponsor::getemail(){return email;}
void Sponsor::setmatri(int matri){this->matri=matri;}
void Sponsor::setduree(QString duree){this->duree=duree;}
void Sponsor:: setmontant(int montant){this->montant=montant;}
void Sponsor::setnom(QString nom){this->nom=nom;}
void Sponsor::setad(QString ad){this->ad=ad;}
void Sponsor::setemail(QString email){this->email=email;}
bool Sponsor::ajouter()
{
            QSqlQuery query;
            QString matri_string = QString::number(matri);
            QString montant_string = QString::number(montant);
                 query.prepare("INSERT INTO sponsor (matri,nom,ad,email,montant,duree ) "
                               "VALUES (:matri, :nom, :ad,:email,:montant,:duree)");
                 query.bindValue(":nom", nom);query.bindValue(":nom", nom);
                 query.bindValue(":matri", matri_string);
                 query.bindValue(":ad", ad);
                 query.bindValue(":email", email);
                 query.bindValue(":montant", montant_string);
                 query.bindValue(":duree", duree);


    return   query.exec();
}
bool Sponsor::supprimer(int matri)
{
     QSqlQuery query;
     query.prepare("Delete from sponsor where matri=:matri");
     query.bindValue(":matri", matri);

return   query.exec();

}
QSqlQueryModel* Sponsor::afficher()
{
      QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM sponsor");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Nom de l'Entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Matricule Fiscal"));
    model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject:: tr("Montant"));
    model->setHeaderData(5, Qt::Horizontal, QObject:: tr("durée"));

    return  model;
}
bool Sponsor ::modifier()
{
                       QSqlQuery query;
                        QString matri_string=QString ::number (matri);
                        QString montant_string = QString::number(montant);
    query.prepare("UPDATE sponsor SET matri=:matri,nom=:nom,ad=:ad,email=:email,montant=:montant,duree=:duree WHERE matri=:matri ");
                         query.bindValue(":matri",matri_string);
                         query.bindValue(":nom", nom);
                         query.bindValue(":ad", ad);
                         query.bindValue(":email", email);
                         query.bindValue(":montant", montant);
                         query.bindValue(":duree", duree);

                     return query.exec();}
