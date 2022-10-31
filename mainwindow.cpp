#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"employe.h"
#include<QIntValidator>
#include<QObject>
#include<QMainWindow>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 999999, this));
    ui->le_nom->setMaxLength(10);
    ui->le_prenom->setMaxLength(10);
    ui->tableView_2->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
   int id=ui->le_id->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   QString fonction=ui->le_fonction->text();
   QString lieu=ui->le_lieu->text();
   QString date_naissance=ui->la_date->text();
    Employe E(id,nom,prenom,fonction,lieu,date_naissance);
    bool test=E.ajouter();
    if (test)
    {
        ui->tableView_2->setModel(E.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("ajout effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_supprimer_clicked()
{
    int id=ui->le_id->text().toInt();
    bool test=E.supprimer(id);
    if (test)
    {
        ui->tableView_2->setModel(E.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("suppression effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("suppression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonction->text();
    QString lieu=ui->le_lieu->text();
    QString date_naissance=ui->la_date->text();
     Employe E(id,nom,prenom,fonction,lieu,date_naissance);
    bool test=E.modifier();

        if(test){
            ui->tableView_2->setModel(E.afficher());
                    QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("modification effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("modification failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
