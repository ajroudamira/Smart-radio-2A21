#include "employe.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
Employe::Employe()
{id=0; nom=" "; prenom=" ";fonction=" ";lieu=" ";date_naissance=" ";}
Employe::Employe(int id,QString nom,QString prenom,QString fonction,QString lieu,QString date_naissance)
{this->id=id;
this->nom=nom;
this->prenom=prenom;
this->fonction=fonction;
this->lieu=lieu;
this->date_naissance=date_naissance;}
int Employe:: getid(){return id;};
QString Employe:: getnom(){return nom;};
QString Employe:: getprenom(){return prenom;};
QString Employe:: getfonction(){return fonction;};
QString Employe:: getlieu(){return lieu;};
QString Employe:: getdate_naissance(){return date_naissance;};
void Employe::setid(int id){this->id=id;};
void Employe::setnom(QString nom){this->nom=nom;};
void Employe::setprenom(QString prenom){this->prenom=prenom;};
void Employe::setfonction(QString fonction){this->fonction=fonction;};
void Employe::setlieu(QString lieu){this->lieu=lieu;};
void Employe::setdate_naissance(QString date_naissance){this->date_naissance=date_naissance;};
bool Employe ::ajouter()
{
    QSqlQuery query;
    QString id_string=QString ::number (id);
          query.prepare("INSERT INTO EMPLOYE (id,nom,prenom,fonction,lieu,date_naissance) "
                        "VALUES (:id, :nom, :prenom,:fonction,:lieu,:date_naissance)");
          query.bindValue(":id",id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":fonction", fonction);
         query.bindValue(":lieu", lieu);
        query.bindValue(":date_naissance", date_naissance);
           return query.exec();
}
bool Employe:: supprimer(int id)
{
    QSqlQuery query;

          query.prepare("DELETE FROM EMPLOYE WHERE id=:id");

          query.bindValue(":id",id);

           return query.exec();
}
QSqlQueryModel* Employe::afficher()
{
   QSqlQueryModel* Model=new QSqlQueryModel() ;
       Model->setQuery("SELECT*FROM employe");
       Model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
       Model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Nom"));
       Model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
       Model->setHeaderData(3, Qt::Horizontal,QObject:: tr("fonction"));
       Model->setHeaderData(4, Qt::Horizontal,QObject:: tr("lieu de travail"));
       Model->setHeaderData(5, Qt::Horizontal,QObject:: tr("date de naissance"));
   return Model;
}
bool Employe ::modifier()
{
                       QSqlQuery query;
                        QString id_string=QString ::number (id);

    query.prepare("UPDATE EMPLOYE SET id=:id,nom=:nom,prenom=:prenom,fonction=:fonction,lieu=:lieu,date_naissance=:date_naissance WHERE id=:id ");
                                          query.bindValue(":id",id_string);
                                          query.bindValue(":nom", nom);
                                          query.bindValue(":prenom", prenom);
                                          query.bindValue(":fonction", fonction);
                                          query.bindValue(":lieu", lieu);
                                          query.bindValue(":date_naissance", date_naissance);

                     return query.exec();}

