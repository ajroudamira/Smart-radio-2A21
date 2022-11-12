#include "ui_mainwindow.h"
#include "invite.h"
#include "QIntValidator"
#include "QMainWindow"
#include "QObject"
#include "mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_CIN->setValidator(new QIntValidator(100, 99999999, this));
    ui->tab_invite->setModel(I.afficher());
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{
  int CIN=ui->le_CIN->text().toInt();
  int Num_tel=ui->le_Num_tel->text().toInt();
  QString nom=ui->le_nom->text();
  QString prenom=ui->le_nom->text();
  QString date_de_naissance=ui->le_date_de_naissance->text();
  QString etat_civil=ui->letat_civil->text();
  QString adresse=ui->ladresse->text();
  invite I(CIN,Num_tel,nom,prenom,date_de_naissance,etat_civil,adresse);
  bool test=I.Ajouter();
  QMessageBox msgBox;
  if(test)
     { msgBox.setText("Ajout avec succes.");
      ui->tab_invite->setModel(I.afficher());
}
  else
      msgBox.setText("Echec d'ajout");
  msgBox.exec();
}
void MainWindow::on_pb_supprimer_clicked()
{
invite I1;I1.setCIN(ui->le_id_supp->text().toInt());
bool test=I1.supprimer(I1.getCIN());
QMessageBox msgBox;
if(test)
   { msgBox.setText("Suppression avec succes.");
ui->tab_invite->setModel(I.afficher());
}
else
    msgBox.setText("Echec de Suppression");
msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int CIN=ui->le_CIN->text().toInt();
    int Num_tel=ui->le_Num_tel->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString date_de_naissance=ui->le_date_de_naissance->text();
    QString etat_civil=ui->letat_civil->text();
    QString adresse=ui->ladresse->text();
    invite I(CIN,Num_tel,nom,prenom,date_de_naissance,etat_civil,adresse);
    bool test=I.modifier();
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Modification avec succes.");
        ui->tab_invite->setModel(I.afficher());
  }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();
}
/*
void MainWindow::on_trieid_clicked()
{
     ui->tableView_2->setModel(E.trieid());
}

void MainWindow::on_trienom_clicked()
{
     ui->tableView_2->setModel(E.trienom());
}

*/
