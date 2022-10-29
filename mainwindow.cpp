#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crud.h"
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableau->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    bool ok1,ok8,ok7,ok6,ok5,ok4,ok3,ok2;
int sem1=ui->sem1->text().toInt(&ok1);
int sem2=ui->sem2->text().toInt(&ok2);
int sem3=ui->sem3->text().toInt(&ok3);
int sem4=ui->sem4->text().toInt(&ok4);
int sem5=ui->sem5->text().toInt(&ok5);
int sem6=ui->sem6->text().toInt(&ok6);
int sem7=ui->sem7->text().toInt(&ok7);
int sem8=ui->sem8->text().toInt(&ok8);

QString jourdiff=ui->jourdiff->text();
QString name=ui->le_nom->text();
QString id=ui->le_nom_2->text();
QString difname=ui->le_nom_3->text();
if(!jourdiff.isEmpty()&&!name.isEmpty()&&!id.isEmpty()&&!difname.isEmpty()){
if(ok1&ok2&ok3&ok4&ok5&ok6&ok7&ok8){
CRUD C(name,id,difname,jourdiff,sem1,sem2,sem3,sem4,sem5,sem6,sem7,sem8);
bool test=C.ajouter();
if(test){
    ui->tableau->setModel(c.afficher());

    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué: L'ID existe deja.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué : les cases de nombre d'écoute sont vide ou le type de données ajouter est incompatible avec la case  .\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué: Un ou plusieurs cases sont vide.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);



}




void MainWindow::on_supprimer_clicked()
{       QString id=ui->Supression->text();
        if(!id.isEmpty()){
bool test=c.supprimer(id);
if(test){
    ui->tableau->setModel(c.afficher());
    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Suppression Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                QObject::tr("Suppression Non Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("Suppression Non Effectué : La case de suppression est vide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tableau_activated(const QModelIndex &index)
{
    QString id=ui->tableau->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from PROGRAMME where ID='"+id+"'");
    if(query.exec()){
        while(query.next())
        {
            ui->sem1->setText(query.value(4).toString());
            ui->sem2->setText(query.value(5).toString());
            ui->sem3->setText(query.value(6).toString());
            ui->sem4->setText(query.value(7).toString());
            ui->sem5->setText(query.value(8).toString());
            ui->sem6->setText(query.value(9).toString());
            ui->sem7->setText(query.value(10).toString());
            ui->sem8->setText(query.value(11).toString());
            ui->jourdiff->setText(query.value(3).toString());
            ui->le_nom-> setText(query.value(0).toString());
            ui->Supression ->setText(query.value(0).toString());
            ui->le_nom_2->setText(query.value(1).toString());
            ui->le_nom_3->setText(query.value(2).toString());
        }

    }

}

void MainWindow::on_pb_modif_clicked()
{ bool ok1,ok8,ok7,ok6,ok5,ok4,ok3,ok2;
    int sem1=ui->sem1->text().toInt(&ok1);
    int sem2=ui->sem2->text().toInt(&ok2);
    int sem3=ui->sem3->text().toInt(&ok3);
    int sem4=ui->sem4->text().toInt(&ok4);
    int sem5=ui->sem5->text().toInt(&ok5);
    int sem6=ui->sem6->text().toInt(&ok6);
    int sem7=ui->sem7->text().toInt(&ok7);
    int sem8=ui->sem8->text().toInt(&ok8);
QString jourdiff=ui->jourdiff->text();
QString name=ui->le_nom->text();
QString id=ui->le_nom_2->text();
QString difname=ui->le_nom_3->text();
if(!jourdiff.isEmpty()&&!name.isEmpty()&&!id.isEmpty()&&!difname.isEmpty()){
if(ok1&ok2&ok3&ok4&ok5&ok6&ok7&ok8){
CRUD C(name,id,difname,jourdiff,sem1,sem2,sem3,sem4,sem5,sem6,sem7,sem8);
bool test=C.modifier();
if(test){
    ui->tableau->setModel(c.afficher());

    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué: L'ID existe deja.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué : les cases de nombre d'écoute sont vide ou le type de données ajouter est incompatible avec la case  .\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué: Un ou plusieurs cases sont vide.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);



}



