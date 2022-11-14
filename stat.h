#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
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


QT_CHARTS_USE_NAMESPACE//defenir la porte de nos variable
namespace Ui {
class Statistique;
}

class Statistique : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique(QWidget *parent = nullptr);
    ~Statistique();
    QChartView *chartView ;
void statistique();
private slots:
private:
    Ui::Statistique *ui;
};

#endif // STATISTIQUE_H
