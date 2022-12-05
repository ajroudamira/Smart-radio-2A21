#ifndef INVITE_H
#define INVITE_H
#include <QString>
#include <QSqlQueryModel>
#include<QWidget>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>
#include <QRegularExpression>
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
class invite
{
public:
    invite();
    invite(int,int,QString,QString,QString,QString,QString,QString);
    int getCIN();
    int getNum_tel();
    QString getnom();
    QString getprenom();
    QString getdate_de_naissance();
    QString getetat_civil();
    QString getadresse();
    void setCIN(int);
    void  setNum_tel( int);
    void setnom(QString);
    void setprenom(QString);
    void setdate_de_naissance(QString);
    void  setetat_civil(QString);
    void  setadresse(QString);
    bool Ajouter();
    QSqlQueryModel*afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercherii(QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel*triCIN();
    QSqlQueryModel*triAdresse();
    int CIN,Num_tel;
    QString nom,prenom,date_de_naissance,etat_civil,adresse,date_event;
private:
};
#endif // INVITE_H
