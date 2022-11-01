#include "equipement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <excelexporthelper.h>
#include <QMessageBox>
#include <exception>
#include <QtCharts/QPieSlice>
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
#include <QDebug>
#include <qdebug.h>
QT_CHARTS_USE_NAMESPACE
using namespace std;
Equipement::Equipement()
{

}
Equipement::Equipement(QString id ,QString nom,QString etat,QString date){
    this->id=id;
    this->nom=nom;
    this->etat=etat;
    this->date=date;



}
bool Equipement::Ajouter(){
    QSqlQuery b;

    b.prepare("Insert into equipement(ID,NOM,ETAT,DATEE) values (:id,:nom,:etat,to_date(:datee,'dd/mm/yyyy'))");
    b.bindValue(":id",id);
    b.bindValue(":nom",nom);
    b.bindValue(":etat",etat);
    b.bindValue(":datee",date);

    return b.exec();

}
bool Equipement::Modifier(QString idd){

    QSqlQuery b;

    b.prepare("update equipement set id = :id , nom= :nom , etat= :etat , datee=to_date(:datee,'dd/mm/yyyy')  where id = :id");
    b.bindValue(":id",idd);
    b.bindValue(":nom",nom);
    b.bindValue(":etat",etat);
    b.bindValue(":datee",date);

    return b.exec();




}
bool Equipement::Suppression(QString idd){


    QSqlQuery b;

    b.prepare("Delete from equipement where id= :id");
    b.bindValue(":id",idd);
    return b.exec();



}

QSqlQueryModel * Equipement::afficher(){
    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM EQUIPEMENT");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));


    return mod ;


}
QSqlQueryModel * Equipement::rechercher(QString x){


    QSqlQuery b;

    b.prepare("SELECT * from equipement where id= :ch OR nom = :ch OR etat = :ch ");
    b.bindValue(":ch",x);



b.exec();

    QSqlQueryModel  * mod=new QSqlQueryModel();
  mod->setQuery(b);
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));


    return mod ;





}
QSqlQueryModel * Equipement::TrieID(){

    QSqlQuery b;

    b.prepare("SELECT * from equipement ORDER BY id ");

b.exec();

    QSqlQueryModel  * mod=new QSqlQueryModel();
  mod->setQuery(b);
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));


    return mod ;








}
QSqlQueryModel * Equipement::TrieNom(){

    QSqlQuery b;

    b.prepare("SELECT * from equipement ORDER BY nom ");

b.exec();

    QSqlQueryModel  * mod=new QSqlQueryModel();
  mod->setQuery(b);
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));


    return mod ;








}
QSqlQueryModel * Equipement::TrieDate(){

    QSqlQuery b;

    b.prepare("SELECT * from equipement ORDER BY Datee ");

b.exec();

    QSqlQueryModel  * mod=new QSqlQueryModel();
  mod->setQuery(b);
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));


    return mod ;


}
void Equipement::Excel(){

    try
        {
            const QString fileName = "c:\test.xlsx";

            ExcelExportHelper helper;
int l=2;
            QSqlQuery q;
            if(q.exec("SELECT * FROM equipement"))
            {
helper.SetCellValue(1,1,"ID");
helper.SetCellValue(1,2,"NOM");
helper.SetCellValue(1,3,"ETAT");
helper.SetCellValue(1,4,"DATE");

                while (q.next())
                {

            helper.SetCellValue(l,1,q.value(0).toString());
            helper.SetCellValue(l,2,q.value(1).toString());
            helper.SetCellValue(l,3,q.value(2).toString());
            helper.SetCellValue(l,4,q.value(3).toString());

l++;

                }
            helper.SaveAs(fileName);
        }}
        catch (const exception& e)
        {

        }




}
QChart * Equipement::Statistique(){


    QSqlQuery q,q1,q2;
    q.exec("Select * from equipement");
    int tot=0;
    while (q.next())
        tot++;
    q1.prepare("Select * from Equipement where etat = :nom ");
    q1.bindValue(":nom","En panne");
    q1.exec();

    int tot_panne=0;
    while (q1.next())
        tot_panne++;

    qreal pour_panne=(tot_panne*100)/tot;

    q2.prepare("Select * from Equipement where etat = :nom ");
    q2.bindValue(":nom","Actif");
    q2.exec();
    int tot_act=0;
    while (q2.next())
        tot_act++;

    qreal pour_act=(tot_act*100)/tot;



    QPieSeries *series = new QPieSeries();
     series->append("En panne",pour_panne);
     series->append("Actif",pour_act);
     QPieSlice *slice0= series->slices().at(0);
     slice0->setLabelVisible();
     QPieSlice *slice1 = series->slices().at(1);
     slice1->setLabelVisible();
     slice1->setBrush(Qt::green);

     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Etat de les equipements");
     chart->legend()->hide();


    return chart;

}
QSqlQueryModel * Equipement::Mise_a_jour(){

    QSqlQuery b,b1,b3,b4;

    b.prepare("SELECT * FROM EQUIPEMENT WHERE DATEE < sysdate");

b.exec();

while (b.next())
{
    b1.prepare("Insert into hist_equip (ID,NOM,Etat,Datee) values (:id,:nom,:etat,:date)");
    b1.bindValue(":id",b.value(0).toString());
    b1.bindValue(":nom",b.value(1).toString());
    b1.bindValue(":etat",b.value(2).toString());
    b1.bindValue(":date",b.value(3).toString());
    b1.exec();
}
b3.prepare("DELETE from equipement where DATEE < sysdate");

    b3.exec();
b4.prepare("select * from hist_equip");
b4.exec();
QSqlQueryModel * m=new QSqlQueryModel();
m->setQuery(b4);
m->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
m->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
m->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
m->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
return m;
}
QSqlQueryModel * Equipement::afficher_r(){


    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM EQUIPEMENT where etat = 'En panne'");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));


    return mod ;










}
bool Equipement::reparer(QString x){

    QSqlQuery b;

    b.prepare("update equipement set etat = 'Actif' where id = :id");
    b.bindValue(":id",x);


    return b.exec();





}
