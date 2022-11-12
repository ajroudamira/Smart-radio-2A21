#ifndef CRUD_H
#define CRUD_H
#include<QString>
#include<QSqlQueryModel>
#include<QTime>
class CRUD
{
public:

    CRUD();
    void setname(QString n);
    void setid(QString n);
    void setdifname(QString n);
    QString getname();
    QString getid();
    QString getdifname();
    bool ajouter();
    QSqlQueryModel* afficher();

    bool supprimer(QString id);
    bool modifier();
    bool controlnumber(QString);
    bool controlstring(QString);
    void setjourdiff(QString n);
    QString getjourdiff();
    CRUD(QString id,QString name ,QString difname,QDateTime);

   private:
    QString name,difname,id;
    QDateTime time;

};

#endif // CRUD_H
