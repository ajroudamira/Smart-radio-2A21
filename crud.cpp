#include "crud.h"
#include <QSqlQuery>
#include<QtDebug>
#include<qobject.h>
#include <ctype.h>

CRUD::CRUD()
{   id="";
name="";
difname="";



}

CRUD::CRUD(QString id,QString name ,QString difname,QDateTime time)
                                                {this->name=name;
                                                 this->id=id;
                                                 this->difname=difname;

                                                 this->time=time;
                                                }
void CRUD::setname(QString n)    {name=n;}
void CRUD::setid(QString n)      {id=n;}
void CRUD::setdifname(QString n) {difname=n;}



QString CRUD::getname(){return name;}
QString CRUD::getid(){return id;}
QString CRUD::getdifname(){return difname;}


bool CRUD::ajouter(){

                 QSqlQuery query;

                   query.prepare("INSERT INTO PROGRAMME (ID, NAME, DIFNAME,TIME) "
                                     "VALUES (:ID,:NAME,:DIFNAME,:TIME)");
                       query.bindValue(":ID", id);
                       query.bindValue(":NAME", name);
                       query.bindValue(":DIFNAME", difname);
                       query.bindValue(":TIME", time);

                 return query.exec();
                }
QSqlQueryModel * CRUD::afficher(){
QSqlQueryModel *  model=new QSqlQueryModel();
      model->setQuery("select * from PROGRAMME");


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

                                      query.prepare("UPDATE PROGRAMME SET ID=:ID, NAME=:NAME,TIME=:TIME,DIFNAME=:DIFNAME WHERE ID=:ID" );
                         query.bindValue(":ID", id);
                         query.bindValue(":NAME", name);
                         query.bindValue(":DIFNAME", difname);
                         query.bindValue(":TIME", time);










                 return query.exec();}






