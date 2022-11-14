#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H
#include <mainwindow.h>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include <QMainWindow>
#include <QMessageBox>
#include <employe.h>
#include <QFileInfo>
class authentification
{
private:
    QString NOM_UTILI;
   QString MOT_DE_PASSE;
public:
    authentification();
   authentification(QString,QString);

QString get_NOM_UTILI(){return NOM_UTILI;}
 QString get_MOT_DE_PASSE(){return MOT_DE_PASSE;}


 QSqlQueryModel * afficher();
 bool ajouter();
 bool supprimer(QString NOM_UTILI);
 bool modifier(QString, QString);

 QSqlQueryModel *mot_de_passe(const QString &aux1);


};

#endif // AUTHENTIFICATION_H
