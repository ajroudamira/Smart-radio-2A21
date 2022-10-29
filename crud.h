#ifndef CRUD_H
#define CRUD_H
#include<QString>
#include<QSqlQueryModel>
class CRUD
{
public:
    CRUD(QString,QString,QString);
    CRUD();
    void setname(QString n);
    void setid(QString n);
    void setdifname(QString n);
    QString getname();
    QString getid();
    QString getdifname();
    bool ajouter();
    QSqlQueryModel* afficher();
    void setsem1(int n);
    void setsem2(int n);
    void setsem3(int n);
    void setsem4(int n);
    void setsem5(int n);
    void setsem6(int n);
    void setsem7(int n);
    void setsem8(int n);
    int getsem1();
    int getsem2();
    int getsem3();
    int getsem4();
    int getsem5();
    int getsem6();
    int getsem7();
    int getsem8();
    bool supprimer(QString id);
    bool modifier();
    bool controlnumber(QString);
    bool controlstring(QString);
    void setjourdiff(QString n);
    QString getjourdiff();
    CRUD(QString id,QString name ,QString difname,QString jourdiff,int sem1,int sem2,int sem3,int sem4,int sem5,int sem6,int sem7,int sem8);

   private:
    QString name,difname,id,jourdiff;
    int sem1,sem2,sem3,sem4,sem5,sem6,sem7,sem8;

};

#endif // CRUD_H
