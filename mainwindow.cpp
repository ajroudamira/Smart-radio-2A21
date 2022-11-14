#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include "invite.h"
#include "QIntValidator"
#include "QMainWindow"
#include "QObject"
#include <QPainter>
#include<QPdfWriter>
#include<QDesktopServices>
#include<QUrl>
#include<QWidget>
#include<QString>
#include <QPagedPaintDevice>
#include <QtCore>
#include<QtGui>
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->le_CIN->setValidator(new QIntValidator(100, 99999999, this));
  ui->le_Num_tel->setValidator(new QIntValidator(100, 99999999, this));
  QRegularExpression rx("^[A-Za-z]+$");
  QValidator *validator = new QRegularExpressionValidator(rx, this);
  ui->le_nom->setMaxLength(15);
  ui->le_prenom->setMaxLength(15);
  ui->le_nom->setValidator(validator);
  ui->le_prenom->setValidator(validator);
  ui->letat_civil->addItem("célibataire");
  ui->letat_civil->addItem("marié(e)");
  ui->letat_civil->addItem("divorcé(e)");
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
  QString prenom=ui->le_prenom->text();
  QString date_de_naissance=ui->le_date_de_naissance->text();
  QString etat_civil=ui->letat_civil->currentText();
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
    QString etat_civil=ui->letat_civil->currentText();
    QString adresse=ui->ladresse->text();
    invite I(CIN,Num_tel,nom,prenom,date_de_naissance,etat_civil,adresse);
    bool test=I.modifier();
    QMessageBox msgBox;
    if(test){
        ui->tab_invite->setModel(I.afficher());
        QMessageBox::information(nullptr, QObject::tr(" OK"),
                    QObject::tr("Ajout Effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();

}
   void MainWindow::on_pb_pdf_2_clicked()
{
    QSqlQuery query;
    query.prepare("select * from invite where CIN");
     I.telechargerPDF();
        if(query.exec()){

           while(query.next())
            {
            ui->le_CIN->setText(query.value(0).toString());
            ui->le_Num_tel->setText(query.value(1).toString());
            ui->le_nom->setText(query.value(2).toString());
            ui->le_prenom->setText(query.value(3).toString());
          //  ui->le_date_de_naissance->setText(query.value(4).toString());
            ui->letat_civil->setCurrentText(query.value(5).toString());
            ui->ladresse->setText(query.value(6).toString());
            }
        }
        else
            QMessageBox::information(nullptr,QObject::tr("OK"),
                       QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}
void MainWindow::on_pb_recherche_cin_clicked()
{
   I.setCIN(ui->pb_recherche_cin->text().toInt());
    bool test=I.rechercher(I.getCIN());
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Recherche avec succes.");
        ui->tab_invite->setModel(I.afficher());
       }
    else
    msgBox.setText("Not found");
    msgBox.exec();
}


