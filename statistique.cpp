#include "statistique.h"
#include "ui_statistique.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
void statistique::Statistique()
{
    QSqlQuery query0,query1,query2,query3,query4,query5,query6;

    qreal tot=0,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0;


    query0.prepare("SELECT * FROM EMPLOYE");
    query0.exec();




    query3.prepare("SELECT * FROM EMPLOYE  WHERE  lieu='beja' ");
    query3.exec();

    query4.prepare("SELECT * FROM EMPLOYE WHERE lieu='gabes' ");
    query4.exec();

    query5.prepare("SELECT * FROM EMPLOYE WHERE fonction='ingenieur' ");
    query5.exec();

    query6.prepare("SELECT * FROM EMPLOYE WHERE fonction='journaliste' ");
    query6.exec();

    while (query0.next()){tot++;}

  while (query3.next()){p3++;}
    while (query4.next()){p4++;}
    while (query5.next()){p5++;}
      while (query6.next()){p6++;}

   tot=tot/2;



    // forme + pourcntage + chnia cercule
    QPieSeries *series = new QPieSeries();

    series->append("lieu gabes",p3);
    series->append("lieu beja",p4);
    series->append("ingenieur",p3);
    series->append("journaliste",p4);
    //

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
           chart->addSeries(series);
        //  chart->setTitle("statistique des personnel
          chart->legend()->show();


 //display
   QChartView *chartView=new QChartView(chart,ui->label_ls);
   chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setMinimumSize(900,900);
   chartView->show();
}
