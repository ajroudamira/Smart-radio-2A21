#include "statistique.h"
#include "ui_statistique.h"
#include <QApplication>
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


void statistique::choix_bar()
{
    QSqlQuery q0,q1
            ,q2
            ,q3;

    qreal tot=0,c1=0
            ,c2=0
            ,c3=0 ;


    q0.prepare("SELECT * FROM EMPLOYE");
    q0.exec();

    //Les classes de type
    q1.prepare("SELECT * FROM EMPLOYE WHERE FONCTION='ingenieur'");
    q1.exec();


    //Les classes de type Maison d'Hote
    q2.prepare("SELECT * FROM EMPLOYE WHERE FONCTION='journaliste'");
    q2.exec();


    //Les classes de type AirBnb
    q3.prepare("SELECT * FROM EMPLOYE WHERE FONCTION='technicien' ");
    q3.exec();


    while (q0.next()){tot++;}
    //total des classes par rapport au type Hotel
    while (q1.next()){c1++;}
    //total des classes par rapport au type Maison d'Hote
    while (q2.next()){c2++;}
    //total des classes par rapport au type AirBnb
    while (q3.next()){c3++;}



    tot=tot/2;


    // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("ingenieur");
            QBarSet *set1 = new QBarSet("journaliste");
            QBarSet *set2 = new QBarSet("technicien");


            // Assign values for each bar
            *set0 <<c1;
            *set1 <<c2;
            *set2 <<c3;



            // Add all sets of data to the chart as a whole
            // 1. Bar Chart
            QBarSeries *series = new QBarSeries();

            // 2. Stacked bar chart
            series->append(set0);
            series->append(set1);
            series->append(set2);


            // Used to define the bar chart to display, title
            // legend,
            QChart *chart = new QChart();

            // Add the chart
            chart->addSeries(series);
            chart->setTitle("Total des classes par rapport au types");
            chart->setAnimationOptions(QChart::SeriesAnimations);

            /*QStringList categories;
                categories << "ingenieur" << "journaliste" << "technicien" ;*/
            // Adds categories to the axes
                   QBarCategoryAxis *axisX = new QBarCategoryAxis();

                    chart->addAxis(axisX, Qt::AlignBottom);
                    series->attachAxis(axisX);

                    QValueAxis *axisY = new QValueAxis();
                    axisY->setRange(0,tot);
                    chart->addAxis(axisY, Qt::AlignLeft);
                    series->attachAxis(axisY);


            // 1. Bar chart
           // chart->setAxisX(axis, series);

            // Used to change the palette
            QPalette pal = qApp->palette();

            // Change the color around the chart widget and text
            pal.setColor(QPalette::Window, QRgb(0xffffff));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));

            // Apply palette changes to the application
            qApp->setPalette(pal);


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_ls);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(500,380);
    chartView->show();
}
