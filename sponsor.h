#ifndef SPONSOR_H
#define SPONSOR_H
#include <QString>
#include<QSqlQueryModel>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>
#include <QRegularExpression>
#include "dialog.h"
#include  <qstring.h>
#include<QDate>
#include<QPixmap>

class Sponsor
{
public:
    Sponsor();
    Sponsor(int,int,QString,QString,QString,QString);
    int getmatri();
    int getmontant();
    QString getduree();
    QString getnom();
    QString getad();
    QString getemail();
    void setmatri(int);
    void setmontant(int);
    void setduree(QString);
    void setnom(QString);
    void setad(QString);
    void setemail(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
bool modifier();
    QSqlQueryModel * trienom();
    QSqlQueryModel * triead();
    QSqlQueryModel * triemontant();
    void recherche(QTableView * table, QString);
    int verifieremail(QString);
void telechargerPDF();

private:
    int matri,montant;
    QString nom,ad,email,duree;
};

#endif // SPONSOR_H

