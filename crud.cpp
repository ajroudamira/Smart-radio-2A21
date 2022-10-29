#include "crud.h"
#include <QSqlQuery>
#include<QtDebug>
#include<qobject.h>
#include <ctype.h>

CRUD::CRUD()
{   id="";
name="";
difname="";
jourdiff="";
sem1=0;
sem2=0;
sem3=0;
sem4=0;
sem5=0;
sem6=0;
sem7=0;
sem8=0;

}

CRUD::CRUD(QString id,QString name ,QString difname,QString jourdiff,int sem1,int sem2,int sem3,int sem4,int sem5,int sem6,int sem7,int sem8)
                                                {this->name=name;
                                                 this->id=id;
                                                 this->difname=difname;
                                                 this->jourdiff=jourdiff;
                                                 this->sem1=sem1;
                                                 this->sem2=sem2;
                                                 this->sem3=sem3;
                                                 this->sem4=sem4;
                                                 this->sem5=sem5;
                                                 this->sem6=sem6;
                                                 this->sem7=sem7;
                                                 this->sem8=sem8;}
void CRUD::setname(QString n)    {name=n;}
void CRUD::setid(QString n)      {id=n;}
void CRUD::setdifname(QString n) {difname=n;}
void CRUD::setjourdiff(QString n){jourdiff=n;}
void CRUD::setsem1(int n){sem1=n;}
void CRUD::setsem2(int n){sem2=n;}
void CRUD::setsem3(int n){sem3=n;}
void CRUD::setsem4(int n){sem4=n;}
void CRUD::setsem5(int n){sem5=n;}
void CRUD::setsem6(int n){sem6=n;}
void CRUD::setsem7(int n){sem7=n;}
void CRUD::setsem8(int n){sem8=n;}

QString CRUD::getname(){return name;}
QString CRUD::getid(){return id;}
QString CRUD::getdifname(){return difname;}
QString CRUD::getjourdiff(){return jourdiff;}
int CRUD::getsem1(){return sem1;}
int CRUD::getsem2(){return sem2;}
int CRUD::getsem3(){return sem3;}
int CRUD::getsem4(){return sem4;}
int CRUD::getsem5(){return sem5;}
int CRUD::getsem6(){return sem6;}
int CRUD::getsem7(){return sem7;}
int CRUD::getsem8(){return sem8;}
bool CRUD::ajouter(){

                 QSqlQuery query;
                 QString Ssem1=QString::number(sem1);
                 QString Ssem2=QString::number(sem2);
                 QString Ssem3=QString::number(sem3);
                 QString Ssem4=QString::number(sem4);
                 QString Ssem5=QString::number(sem5);
                 QString Ssem6=QString::number(sem6);
                 QString Ssem7=QString::number(sem7);
                 QString Ssem8=QString::number(sem8);
                 if (controlnumber(Ssem1) &&controlnumber(Ssem2) &&controlnumber(Ssem3) &&controlnumber(Ssem4) &&controlnumber(Ssem5) &&controlnumber(Ssem6) &&controlnumber(Ssem7) &&controlnumber(Ssem8) )
                   {    query.prepare("INSERT INTO PROGRAMME (ID, NAME, DIFNAME,JOURDIFF,SEM1,SEM2,SEM3,SEM4,SEM5,SEM6,SEM7,SEM8) "
                                     "VALUES (:ID,:NAME,:DIFNAME,:JOURDIFF,:SEM1,:SEM2,:SEM3,:SEM4,:SEM5,:SEM6,:SEM7,:SEM8)");
                       query.bindValue(":ID", id);
                       query.bindValue(":NAME", name);
                       query.bindValue(":DIFNAME", difname);
                       query.bindValue(":JOURDIFF", jourdiff);
                       query.bindValue(":SEM1", Ssem1);
                       query.bindValue(":SEM2", Ssem2);
                       query.bindValue(":SEM3", Ssem3);
                       query.bindValue(":SEM4", Ssem4);
                       query.bindValue(":SEM5", Ssem5);
                       query.bindValue(":SEM6", Ssem6);
                       query.bindValue(":SEM7", Ssem7);
                       query.bindValue(":SEM8", Ssem8);
                 }return query.exec();
                }
QSqlQueryModel * CRUD::afficher(){
QSqlQueryModel *  model=new QSqlQueryModel();
      model->setQuery("select * from PROGRAMME");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("DiffNom"));

return model;
}
bool CRUD::supprimer(QString id){
QSqlQuery query;

query.prepare("Delete from PROGRAMME where ID=:ID");
query.bindValue(":ID",id);
return query.exec();
}
bool CRUD::modifier(){
                   QSqlQuery query;
                   QString Ssem1=QString::number(sem1);
                   QString Ssem2=QString::number(sem2);
                   QString Ssem3=QString::number(sem3);
                   QString Ssem4=QString::number(sem4);
                   QString Ssem5=QString::number(sem5);
                   QString Ssem6=QString::number(sem6);
                   QString Ssem7=QString::number(sem7);
                   QString Ssem8=QString::number(sem8);
                                      query.prepare("UPDATE PROGRAMME SET ID=:ID, NAME=:NAME, DIFNAME=:DIFNAME, JOURDIFF=:JOURDIFF,SEM1=:SEM1,SEM2=:SEM2,SEM3=:SEM3,SEM4=:SEM4,SEM5=:SEM5,SEM6=:SEM6,SEM7=:SEM7,SEM8=:SEM8 WHERE ID=:ID");
                         query.bindValue(":ID", id);
                         query.bindValue(":NAME", name);
                         query.bindValue(":DIFNAME", difname);
                         query.bindValue(":JOURDIFF", jourdiff);
                         query.bindValue(":SEM1", Ssem1);
                         query.bindValue(":SEM2", Ssem2);
                         query.bindValue(":SEM3", Ssem3);
                         query.bindValue(":SEM4", Ssem4);
                         query.bindValue(":SEM5", Ssem5);
                         query.bindValue(":SEM6", Ssem6);
                         query.bindValue(":SEM7", Ssem7);
                         query.bindValue(":SEM8", Ssem8);









                 return query.exec();}
bool CRUD::controlnumber(QString test){

    bool ok;

    int number =test.toInt(&ok);
    number++;// it's so that qt stops showing the warning that number isnt used
    return ok;

    }






