#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "sponsor.h"
#include "dialog.h"
#include "localisation.h"
#include "ui_localisation.h"
#include "locawifi.h"
#include "calendrier.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modif_clicked();

    void on_tabsponsor_clicked(const QModelIndex &index);

    void on_trienom_clicked();

    void on_triead_clicked();

    void on_triemontant_clicked();

    void on_recher_edit_textChanged(const QString &arg1);

    void on_pb_pdf_clicked();

    void on_pb_mail_clicked();

    void on_checkBoxnom_clicked();

    void on_checkBoxmontant_clicked();

    void on_checkBoxad_clicked();

    void on_pb_geo_clicked();

    void on_pb_geo_2_clicked();

    void on_pb_calend_clicked();

private:
    Ui::MainWindow *ui;
    Sponsor S;
    dialog *Di ;
    Localisation *Li;
    locawifi *l;
calendrier *ca;

};

#endif // MAINWINDOW_H
