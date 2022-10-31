#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sponsor.h>
#include <QIntValidator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_matri->setValidator (new QIntValidator(0, 99999, this));
    ui->le_nom->setMaxLength(15);
    ui->tabsponsor->setModel(S.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{   int matri=ui->le_matri->text().toInt();
     QString nom=ui->le_nom->text();
     QString ad=ui->le_ad->currentText();
      QString email=ui->le_email->text();
    int montant=ui->ds_montant->text().toInt();
    QString duree=ui->te_duree->text();
    //int montant_f=ui->ds_montant->value();
    //montant_f=montant_f*2;
    //int duree_f=ui->te_duree->value();
    //duree_f=duree_f*2;




    Sponsor S(matri,montant,duree,nom,ad,email);
bool test=S.ajouter();
 if(test)
 {    ui->tabsponsor->setModel(S.afficher());
     QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("ajout effectue.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

}
 else
     QMessageBox::critical(nullptr, QObject::tr("not ok"),
                 QObject::tr("ajout non effectue.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_supp_clicked()
{
    int matri=ui->le_matrisupp->text().toInt();
     bool test=S.supprimer(matri);

     if (test)
     {
         ui->tabsponsor->setModel(S.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("suppression effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
     QMessageBox::critical(nullptr, QObject::tr("not OK"),
                         QObject::tr("suppression failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pb_modif_clicked()
{
    int matri=ui->le_matri->text().toInt();
    QString nom=ui->le_nom->text();
   QString ad=ui->le_ad->currentText();
    QString email=ui->le_email->text();
    int montant=ui->ds_montant->text().toInt();
    QString duree=ui->te_duree->text();
      Sponsor S(matri,montant,duree,nom,ad,email);
    bool test=S.modifier();

        if(test){
            ui->tabsponsor->setModel(S.afficher());
                    QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("modification effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("modification failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
