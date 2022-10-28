#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"crud.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_supprimer_clicked();
    void on_tableau_activated(const QModelIndex &index);
    void on_pb_modif_clicked();


private:
    Ui::MainWindow *ui;
    CRUD c;

};
#endif // MAINWINDOW_H
