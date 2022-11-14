#include "stat.h"
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
Statistique::Statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique)
{
    ui->setupUi(this);
}

Statistique::~Statistique()
{
    delete ui;
}
void Statistique::statistique()
{
    QSqlQuery query0,query1,query2;

    qreal tot=0,p1=0,p2=0;


    query0.prepare("SELECT * FROM PERSONNEL");
    query0.exec();


    query1.prepare("SELECT * FROM PERSONNEL WHERE GENDER='femme'");
    query1.exec();

    query2.prepare("SELECT * FROM PERSONNEL WHERE GENDER='homme' ");
    query2.exec();



    while (query0.next()){tot++;}
    while (query1.next()){p1++;}
    while (query2.next()){p2++;}


   tot=tot/2;



    // forme + pourcntage + chnia cercule
    QPieSeries *series = new QPieSeries();
    series->append("femme",p1);
    series->append("homme",p2);
    //

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
           chart->addSeries(series);
          chart->setTitle("statistique des personnels selon le gender");
          chart->legend()->show();


 //display
   QChartView *chartView=new QChartView(chart,ui->label_stat);
   chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setMinimumSize(400,400);
   chartView->show();

}


