#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sponsor.h"
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

    void on_pb_recher_clicked();

    void on_recher_edit_textChanged(const QString &arg1);

    void on_pb_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Sponsor S;
};

#endif // MAINWINDOW_H
