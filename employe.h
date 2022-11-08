#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQueryModel>
class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getfonction();
    QString getlieu();
    QString getdate_naissance();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setfonction(QString);
    void setlieu(QString);
    void setdate_naissance(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier ();
    QSqlQueryModel * trienom();
    QSqlQueryModel * trieid();
    QSqlQueryModel * trielieu(); 
   QSqlQueryModel* recherche(QString recherche);
   QSqlQueryModel* rechercheparprenom(QString cherche);
   void telechargerPDF();
private:
    int id;
    QString nom, prenom,fonction,lieu ,date_naissance;

};

#endif // EMPLOYE_H
