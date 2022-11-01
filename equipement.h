#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQueryModel>
using namespace std;
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
class Equipement
{
public:
    Equipement();
    Equipement(QString,QString,QString,QString);
    QString id;
    QString nom;
    QString etat;
    QString date;

    bool Ajouter();
    bool Modifier(QString id);
    bool Suppression(QString id);
      QSqlQueryModel * afficher();
      QSqlQueryModel * rechercher(QString x);
      QSqlQueryModel * TrieID();
       QSqlQueryModel * TrieNom();
 QSqlQueryModel * TrieDate();
 void Excel();
QChart * Statistique();
 QSqlQueryModel * Mise_a_jour();
 QSqlQueryModel * afficher_r();
 bool reparer(QString x);
};

#endif // EQUIPEMENT_H
