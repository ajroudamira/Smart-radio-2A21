#ifndef METIERS_H
#define METIERS_H
#include<QApplication>
#include<QtWidgets/QMainWindow>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include"crud.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QVariant>
#include <QPainter>
#include <QDesktopServices>
#include <QPdfWriter>
#include <QModelIndex>
#include <QUrl>
#include <vector>
#include <QMessageBox>
#include <QMediaRecorder>
#include <QAudioRecorder>
#include <QAudioInput>
QT_CHARTS_USE_NAMESPACE
class Metiers
{private:
    CRUD c;
    QMainWindow u;
public:
    bool stats();
    double PREDICTION(QString);
 QSqlQueryModel * recherche(int i,QString s);
 QSqlQueryModel * sort(int);
 QSqlQueryModel * Affichage(QString);
 void exportpdf(QString s);



};

#endif // METIERS_H
