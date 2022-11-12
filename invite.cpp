#include "invite.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
invite::invite()
{
CIN=0;Num_tel=0;
nom="";prenom="";date_de_naissance="";etat_civil="";adresse="";
}
invite::invite(int CIN,int Num_tel,QString nom,QString prenom,QString date_de_naissance,QString etat_civil,QString adresse)
{this->CIN=CIN;this->Num_tel=Num_tel;this->nom=nom;this->prenom=prenom;this->date_de_naissance=date_de_naissance;this->etat_civil=etat_civil;this->adresse=adresse;}
int invite::getCIN(){return CIN;}
int invite::getNum_tel(){return CIN;}
QString invite::getnom(){return nom;}
QString invite::getprenom(){return prenom;}
QString invite::getdate_de_naissance(){return date_de_naissance;}
QString invite::getetat_civil(){return etat_civil;}
QString invite::getadresse(){return adresse;}

void invite::setCIN(int CIN){this->CIN=CIN;}
void invite::setNum_tel(int Num_tel){this->Num_tel=Num_tel;}
void invite::setnom(QString nom){this->nom=nom;}
void invite::setprenom(QString prenom){this->prenom=prenom;}
void invite::setdate_de_naissance(QString date_de_naissance){this->date_de_naissance=date_de_naissance;}
void invite::setetat_civil(QString etat_civil){this->etat_civil=etat_civil;}
void invite::setadresse(QString adresse){this->adresse=adresse;}

bool invite::Ajouter()
{
    QString CIN_string= QString::number(CIN);
    QString Num_tel_string= QString::number(Num_tel);
    QSqlQuery query;
         query.prepare("INSERT INTO invite (CIN,Num_tel,nom,prenom,date_de_naissance,etat_civil,adresse)"
                       "VALUES (:id,:a,:forename,:surname,:b,:c,:d)");
         query.bindValue(":id", CIN);
         query.bindValue(":a", Num_tel);
         query.bindValue(":forename", nom);
         query.bindValue(":surname", prenom);
         query.bindValue(":b", date_de_naissance);
         query.bindValue(":c", etat_civil);
         query.bindValue(":d", adresse);
         return query.exec();
}
bool invite::supprimer(int CIN)
{
    QSqlQuery query;
         query.prepare("Delete from invite where CIN=:id");
         query.bindValue(":id", CIN);
         return query.exec();
}
QSqlQueryModel*invite::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT * FROM invite");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num_tel"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat_civil"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));

 return model;
}
 bool invite::modifier()
 {
     QString CIN_string= QString::number(CIN);
     QString Num_tel_string= QString::number(Num_tel);
     QSqlQuery query;
          query.prepare("INSERT INTO invite (CIN,Num_tel,nom,prenom,date_de_naissance,etat_civil,adresse)"
                        "VALUES (:id,:a,:forename,:surname,:b,:c,:d)");
          query.bindValue(":id", CIN);
          query.bindValue(":a", Num_tel);
          query.bindValue(":forename", nom);
          query.bindValue(":surname", prenom);
          query.bindValue(":b", date_de_naissance);
          query.bindValue(":c", etat_civil);
          query.bindValue(":d", adresse);
          return query.exec();
 }

 /*QSqlQueryModel *invite::trienom()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM invite ORDER BY NOM");
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
     model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Num_tel"));
     model->setHeaderData(2, Qt::Horizontal,QObject:: tr("nom"));
     model->setHeaderData(3, Qt::Horizontal,QObject:: tr("prenom"));
     model->setHeaderData(4, Qt::Horizontal,QObject:: tr("date_de_naissance"));
     model->setHeaderData(5, Qt::Horizontal,QObject:: tr("etat_civil"));
     model->setHeaderData(5, Qt::Horizontal,QObject:: tr("adresse"));
 return model;
 }
 QSqlQueryModel *invite::trieid()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM invite ORDER BY ID");
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Num_tel"));
     model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
     model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal,QObject:: tr("date_de_naissance"));
     model->setHeaderData(4, Qt::Horizontal,QObject:: tr("etat_civil"));
     model->setHeaderData(5, Qt::Horizontal,QObject:: tr("adresse"));
 return model;
 }
}*/

