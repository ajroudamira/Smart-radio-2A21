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
    QRegularExpression rx("^[A-Za-z]+$");//controle de saisie.

    QValidator *validator = new QRegularExpressionValidator(rx, this);
            ui->le_nom->setValidator(validator);
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
  QString fonction=ui->le_fonction->currentText();
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
    QString fonction=ui->le_fonction->currentText();
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





void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    ui->le_id->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),0)).toString());
        ui->le_nom->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),1)).toString());
         ui->le_prenom->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),2)).toString());
       //  ui->le_fonction->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),3)).toString());
          ui->le_lieu->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),4)).toString());
}
