#ifndef CALENDRIER_H
#define CALENDRIER_H
#include <QMessageBox>
#include<QObject>
#include<QString>
#include<QSqlQuery>
#include <QDialog>
#include <QCalendarWidget>
namespace Ui {
class calendrier;
}

class calendrier : public QDialog
{
    Q_OBJECT

public:
    explicit calendrier(QWidget *parent = nullptr);
    ~calendrier();

private slots:


private:
    Ui::calendrier *ui;
};

#endif // CALENDRIER_H
