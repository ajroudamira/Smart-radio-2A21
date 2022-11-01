#ifndef INVITE_H
#define INVITE_H

#include <QString>
#include <QSqlQueryModel>
class invite
{
public:
    invite();
    invite(int,int,QString,QString,QString,QString,QString);
    int getCIN();
    int getNum_tel();
    QString getnom();
    QString getprenom();
    QString getdate_de_naissance();
    QString getetat_civil();
    QString getadresse();
    void setCIN(int);
    void  setNum_tel( int);
    void setnom(QString);
    void setprenom(QString);
    void setdate_de_naissance(QString);
    void  setetat_civil(QString);
    void  setadresse(QString);
    bool Ajouter();
    QSqlQueryModel*afficher();
    bool supprimer(int);
private:
    int CIN,Num_tel;
    QString nom,prenom,date_de_naissance,etat_civil,adresse;

};

#endif // INVITE_H
