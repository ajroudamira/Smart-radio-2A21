#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>//afficher les graphe
#include <QtCharts/QBarSeries>//dessigner les barre
#include <QtCharts/QBarSet>//ensemble des barre
#include <QtCharts/QLegend>//couleur
#include <QtCharts/QBarCategoryAxis>//ajouter des catego au axes
#include <QtCharts/QHorizontalStackedBarSeries>//type de graphe
#include <QtCharts/QLineSeries>//designer des graphe linaire
#include <QtCharts/QCategoryAxis>//change name of axes
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <QDialog>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:

    explicit statistique(QWidget *parent = nullptr);
    ~statistique();
    QChartView *chartView ;
    void Statistique();
private:
    Ui::statistique *ui;
};

#endif // STATISTIQUE_H
