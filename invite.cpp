#include "invite.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QPagedPaintDevice>
#include<QPainter>
#include<QPdfWriter>
#include<iostream>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>
/*#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <qdebug.h>
QT_CHARTS_USE_NAMESPACE*/
using namespace std;
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
 bool  invite::telechargerPDF()
 {
                      QPdfWriter pdf("C:/amira ajroud/file pdf");
                      QPainter painter(&pdf);
                      int i = 4000;
                          painter.setPen(Qt::blue);
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(1100,1200,"LISTES DES invites");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial",14));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial",11));
                          painter.drawText(200,3300,"CIN");
                          painter.drawText(1300,3300,"Num_tel");
                          painter.drawText(2700,3300,"nom");
                          painter.drawText(4000,3300,"prenom");
                          painter.drawText(6500,3300,"date_de_naissance");
                          painter.drawText(7700,3300,"etat_civil");
                          painter.drawText(8800,3300,"duree");

                          QSqlQuery query;
                          query.prepare("select * from invites");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2700,i,query.value(2).toString());
                              painter.drawText(4000,i,query.value(3).toString());
                              painter.drawText(6500,i,query.value(4).toString());
                              painter.drawText(7700,i,query.value(5).toString());
                              i = i + 500;
                              painter.end();
                          }
                          return query.exec();

 }

 bool invite::rechercher(int CIN)
 {
     QSqlQuery query;
     query.prepare("SELECT * from invite where CIN= :id");
     query.bindValue(":id",CIN);
     query.exec();
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num_tel"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat_civil"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
     return model ;
 }


