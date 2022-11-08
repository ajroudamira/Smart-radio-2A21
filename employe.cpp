#include "employe.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QPainter>
#include<QPagedPaintDevice>
#include<QPdfWriter>
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
QSqlQueryModel *Employe::trienom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY NOM");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("fonction"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("lieu de travail"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("date de naissance"));
return model;
}
QSqlQueryModel *Employe::trieid()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY ID");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("fonction"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("lieu de travail"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("date de naissance"));
return model;

}
QSqlQueryModel *Employe::trielieu()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY LIEU");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("fonction"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("lieu de travail"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("date de naissance"));

    return model;
}
QSqlQueryModel*Employe::recherche(QString recherche)
{
QSqlQueryModel *model = new QSqlQueryModel();
model->setQuery("SELECT* FROM EMPLOYE where nom like '"+recherche+"%'");
model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Nom"));
model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject:: tr("fonction"));
model->setHeaderData(4, Qt::Horizontal,QObject:: tr("lieu de travail"));
model->setHeaderData(5, Qt::Horizontal,QObject:: tr("date de naissance"));
return model;
}
QSqlQueryModel*Employe::rechercheparprenom(QString cherhce)
{
QSqlQueryModel *model = new QSqlQueryModel();
model->setQuery("SELECT* FROM EMPLOYE where prenom like '"+cherhce+"%'");
model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Nom"));
model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject:: tr("fonction"));
model->setHeaderData(4, Qt::Horizontal,QObject:: tr("lieu de travail"));
model->setHeaderData(5, Qt::Horizontal,QObject:: tr("date de naissance"));
return model;
}
void  Employe::telechargerPDF(){


                     QPdfWriter pdf("C:/User/user/Desktop/gestion_employe/generer pdf/pdf.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"LISTES DES EMPLOYES");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial",14));
                        // painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial",11));
                         painter.drawText(200,3300,"identifiant");
                         painter.drawText(1300,3300,"Nom");
                         painter.drawText(2700,3300,"prenom");
                         painter.drawText(4000,3300,"fonction");
                         painter.drawText(6500,3300,"lieu de travail");
                         painter.drawText(7700,3300,"date de naissance");


                         QSqlQuery query;

                         query.prepare("select * from employe");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(1).toString());
                             painter.drawText(1300,i,query.value(0).toString());
                             painter.drawText(2700,i,query.value(2).toString());
                             painter.drawText(4000,i,query.value(3).toString());
                             painter.drawText(6500,i,query.value(4).toString());
                             painter.drawText(7700,i,query.value(5).toString());



                            i = i + 500;
                         }}
