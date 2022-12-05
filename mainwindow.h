#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow> 
#include"invite.h"
#include<QtCharts>
#include<QChartView>
#include<QBarSet>
#include<QBarSeries>
#include<QPieSeries>
#include<QPieSlice>
#include "arduino.h"
QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow;}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

  ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_pdf_clicked();

    //void on_pb_recherche_cin_clicked();

    void on_pb_recherche_clicked();

    void on_pb_tri_cin_clicked();

    void on_pb_tri_adresse_clicked();

    void on_pb_qr_code_clicked();

    void on_pb_historique_clicked();

    void on_pb_arret_clicked();

private:

    Ui::MainWindow *ui;
    invite I;
    Arduino A;
    QByteArray data;
};

#endif // MAINWINDOW_H
