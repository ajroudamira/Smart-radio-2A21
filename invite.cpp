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
invite::invite(int CIN,int Num_tel,QString nom,QString prenom,QString date_de_naissance,QString etat_civil,QString adresse,QString d)
{this->CIN=CIN;this->Num_tel=Num_tel;this->nom=nom;this->prenom=prenom;this->date_de_naissance=date_de_naissance;this->etat_civil=etat_civil;this->adresse=adresse; this->date_event=d;}
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
         query.prepare("INSERT INTO invite (CIN,Num_tel,nom,prenom,date_de_naissance,etat_civil,adresse,date_event)"
                       "VALUES (:id,:a,:forename,:surname,:b,:c,:d,to_date(:datee,'dd/MM/yyyy'))");
         query.bindValue(":id", CIN);
         query.bindValue(":a", Num_tel);
         query.bindValue(":forename", nom);
         query.bindValue(":surname", prenom);
         query.bindValue(":b", date_de_naissance);
         query.bindValue(":c", etat_civil);
         query.bindValue(":d", adresse);
         query.bindValue(":datee",date_event);
         return query.exec();
}
bool invite::supprimer(int CIN)
{
         QSqlQuery query;
         query.prepare("Delete from invite where CIN=:id"); //prepare the sql for execution
         query.bindValue(":id", CIN);//from qt to sql"base de données"
         return query.exec();
}
QSqlQueryModel*invite::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel(); //Creates an empty QSqlQueryModel

       model->setQuery("SELECT * FROM invite");//Réinitialise le modèle et définit le fournisseur de données comme étant la requête donnée
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));//pour la lecture horizental seulement de data
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
          query.prepare("UPDATE INVITE set num_tel = :a , nom =:forename , prenom = :surname , date_de_naissance = :b , etat_civil = :c ,adresse = :d, date_event = to_date(:datee,'dd/MM/yyyy') where CIN = :id");
          query.bindValue(":id", CIN);
          query.bindValue(":a", Num_tel);
          query.bindValue(":forename", nom);
          query.bindValue(":surname", prenom);
          query.bindValue(":b", date_de_naissance);
          query.bindValue(":c", etat_civil);
          query.bindValue(":d", adresse);
          query.bindValue(":datee", date_event);
          return query.exec();
 }
/*QSqlQueryModel * invite::rechercher(QString CIN)
 {

     QSqlQuery query;
     query.prepare("SELECT * from invite where prenom = :id ");
     query.bindValue(":id",CIN);
     query.exec();

     qDebug() << query.value(1).toString();
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
 */
QSqlQueryModel * invite::rechercherii(QString x)
{

    QString ch="%"+x+"%"; //chaine wrnumw chaine : un ou plusieurs caracteres
     QSqlQuery q;
     q.prepare("SELECT * FROM INVITE WHERE nom like :id or prenom like :id or etat_civil like :id or adresse like :id");//like pour rechercher un modèle spécifié dans une colonne
     q.bindValue(":id",ch);
     q.exec();
     QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery(q);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num_tel"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat_civil"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

QSqlQueryModel * invite::triCIN()
 {

     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM invite ORDER BY NOM");//order by selon
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num_tel"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat_civil"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
     return model;
 }
QSqlQueryModel * invite::triAdresse()
 {

     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM invite ORDER BY adresse"); //order by selon
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num_tel"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat_civil"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
     return model;
 }
