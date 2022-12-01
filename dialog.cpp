#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>
#include "smtp.h"
#include "sponsor.h"
#include<QSqlQuery>
#include <QSqlDatabase>
dialog::dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
}

dialog::~dialog()
{
    delete ui;
}

void dialog::on_pb_send_clicked()
{   QString to = ui->textEdit->toPlainText();
    QString from = ui->le_from->text();
    QString subject = ui->le_subject->text();
    QString password =ui->le_password->text();
    QString email_text = ui->textEdit_email->toPlainText();
    int matri = ui->le_to->text().toInt();
    QString id_string= QString::number(matri);
           QSqlQuery query;
          query.prepare("select * from sponsor where matri='"+id_string+"'");
           if(query.exec()){

           while(query.next())
           {
       ui->textEdit->setText(query.value(3).toString());
     }}

      Smtp* smtp = new Smtp(from, password, "smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        smtp->sendMail(to, from, subject, email_text);
}

void   dialog::mailSent(QString nettoyer)
{

    if(nettoyer == "Message sent")
        QMessageBox::information( nullptr, tr( "email" ), tr( "Message sent.\n\n" ) );
    ui->le_to->clear();
    ui->le_from->clear();
    ui->le_subject->clear();
    ui->textEdit_email->clear();
    ui->le_password->clear();
     ui->textEdit->clear();
}




