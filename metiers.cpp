#include "metiers.h"
#include <QDebug>
#include <vector>

bool Metiers::stats(){
   /* QBarSet *set1 = new QBarSet("La Semaine 1");
    QBarSet *set2 = new QBarSet("La Semaine 2");
    QBarSet *set3 = new QBarSet("La Semaine 3");
    QBarSet *set4 = new QBarSet("La Semaine 4");
    QBarSet *set5 = new QBarSet("La Semaine 5");
    QBarSet *set6 = new QBarSet("La Semaine 6");
    QBarSet *set7 = new QBarSet("La Semaine 7");
    QBarSet *set8 = new QBarSet("La Semaine 8");

    // Assign values for each bar

    *set1 << c.getsem1() ;
    *set2 << c.getsem2() ;
    *set3 << c.getsem3() ;
    *set4 << c.getsem4() ;
    *set5 << c.getsem5() ;
    *set6 << c.getsem6() ;
    *set7 << c.getsem7() ;
    *set8 << c.getsem8() ;

    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();

    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);
    series->append(set6);
    series->append(set7);
    series->append(set8);

    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("STATISTIQUE D'ECOUTE");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    categories << "STATISTIQUE DE 2 MOIS ";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    // 2. Stacked Bar chart
    // chart->setAxisY(axis, series);

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
chartView->setParent(ui->tableau_2);
    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0x000000));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    // Apply palette changes to the application
    qApp->setPalette(pal);
*/
    return false;
}
QSqlQueryModel * Metiers::recherche(int i,QString s){

    QSqlQueryModel *  model=new QSqlQueryModel();
    switch(i){
    case 1: model->setQuery("select * from PROGRAMME where NAME like'"+s+"%'");
    break;
    case 2: model->setQuery("select * from PROGRAMME where ID like'"+s+"%'");
    break;
    case 3: model->setQuery("select * from PROGRAMME where DIFNAME like'"+s+"%'");
    break;   }
    return model;
}
QSqlQueryModel * Metiers::sort(int i){
    QSqlQueryModel *  model=new QSqlQueryModel();
    switch(i){
    case 1: model->setQuery("select * from PROGRAMME order by Name");
    break;
    case 2: model->setQuery("select * from PROGRAMME order by ID");
break;
    case 3: model->setQuery("select * from PROGRAMME order by DIFNAME");
    break;   }
    return model;
}
double Metiers::PREDICTION(  QString s){
    int i=0,n=0;
    QSqlQuery q1,q2,q3;
    QString s1="SELECT * FROM "+s;
    q1.prepare(s1);
if( q1.exec())
   {
    float a,b,x[100],y[100];

    while (q1.next()){n++;
        x[i]=(q1.value(0).toInt());
        y[i]=(q1.value(1).toInt());
        qDebug()<<y[i];
        i++;


    }



       double xsum=0,ysum=0,x2sum=0,xysum=0;
       for (i=0;i<n;i++)
       {
           xsum=xsum+x[i];                        //calculate sigma(xi)
           ysum=ysum+y[i];                        //calculate sigma(yi)
           x2sum=x2sum+pow(x[i],2);                //calculate sigma(x^2i)
           xysum=xysum+x[i]*y[i];
       }
       a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);            //calculate slope
       b=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);
qDebug()<<a;
return b+(a*(n+1));}
else
    return -1;

}
void Metiers::exportpdf(QString s){
    QString s1="C:/Users/essay/Desktop/lenna/"+s+".pdf";
    QPdfWriter pdf(s1);

                          QPainter painter(&pdf);

                          int i = 4000;


                          painter.drawText(4000,1500,"LISTE DES PROGRAMME");
                          painter.setPen(Qt::red);
                          painter.setFont(QFont("Century Gothic", 50));
                          painter.drawRect(3800,1200,1700,500);
                          painter.drawRect(0,3000,9600,500);
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Century Gothic", 9));
                          painter.drawText(500,3300,"ID");
                          painter.drawText(1500,3300,"NAME");
                          painter.drawText(3500,3300,"DIFNAME");
                          painter.drawText(5000,3300,"TIME");



                          QSqlQuery query;
                          query.prepare("select * from PROGRAMME");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(500,i,query.value(0).toString());
                              painter.drawText(1800,i,query.value(1).toString());
                              painter.drawText(3500,i,query.value(2).toString());
                              painter.drawText(5000,i,query.value(3).toString());



                              i = i +500;
                          }

                          }
QSqlQueryModel * Metiers::Affichage(QString s){
    QSqlQueryModel *  model=new QSqlQueryModel();
    QString s1="SELECT * FROM "+s;
    model->setQuery(s1);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero De Diffusion"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nombre D'Ecoute"));


    return model;
}

