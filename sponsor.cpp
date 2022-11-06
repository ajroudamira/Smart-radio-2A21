#include "sponsor.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<iostream>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
using namespace std;
Sponsor::Sponsor()
{
matri=0,montant=0;
nom=" ";ad=" ";email=" ",duree=" ";
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
int Sponsor::verifieremail(QString email)
{
 int temail=email.length(),iAT=0;

 for (int i=0;i<(temail-3);i++)
  {
      if (email[i]=='@' and iAT==0)
        iAT=1;//vrai
  }
 if ((email[temail-4]=='.' or email[temail-3]=='.') and iAT==1 )
     return 1;//vrai

return 0;//faux
}
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
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Nom de l'Entreprise"));
    model->setHeaderData(0, Qt::Horizontal, QObject:: tr("Matricule Fiscal"));
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
QSqlQueryModel * Sponsor::trienom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSOR ORDER BY NOM");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Nom de l'Entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Matricule Fiscal"));
    model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject:: tr("Montant"));
    model->setHeaderData(5, Qt::Horizontal, QObject:: tr("durée"));

    return model;
}
QSqlQueryModel * Sponsor::triead()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSOR ORDER BY AD");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Nom de l'Entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Matricule Fiscal"));
    model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject:: tr("Montant"));
    model->setHeaderData(5, Qt::Horizontal, QObject:: tr("durée"));

    return model;
}
QSqlQueryModel * Sponsor::triemontant()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSOR ORDER BY MONTANT");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Nom de l'Entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Matricule Fiscal"));
    model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject:: tr("Montant"));
    model->setHeaderData(5, Qt::Horizontal, QObject:: tr("durée"));

    return model;
}
void Sponsor::recherche(QTableView * table, QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QString matri_string=QString::number(matri);
    QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from sponsor where nom like '%"+rech+"%' or email like '%"+rech+"%' or ad like '%"+rech+"%' or matri like '%"+rech+"%';");
        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();
}
void  Sponsor::telechargerPDF(){


                     // QPdfWriter pdf("C:\\Users\\21699\\Desktop\\export_pdf\\export_pdf");
                    QPdfWriter pdf("C:/Users/Jammoussi Yasmine/Desktop/export_pdf/liste des sponso");

                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::blue);
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(1100,1200,"LISTES DES SPONSORS");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial",14));
                          painter.drawRect(100,100,7300,2600);
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial",11));
                          painter.drawText(200,3300,"Nom De L'Entreprise");
                          painter.drawText(1300,3300,"Matricule fiscale");
                          painter.drawText(2200,3300,"Adresse");
                          painter.drawText(3200,3300,"Email");
                          painter.drawText(3200,3300,"Montant");
                          painter.drawText(3200,3300,"Durée");



                          QSqlQuery query;
                          query.prepare("select * from sponsor");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2200,i,query.value(2).toString());
                              painter.drawText(3200,i,query.value(3).toString());
                              painter.drawText(5300,i,query.value(4).toString());
                              painter.drawText(6700,i,query.value(5).toString());


                             i = i + 500;
                          }}
