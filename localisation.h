#ifndef LOCALISATION_H
#define LOCALISATION_H
#include <QMainWindow>
#include <QDialog>

namespace Ui {
class Localisation;
}

class Localisation : public QDialog
{
    Q_OBJECT

public:
    explicit Localisation(QWidget *parent = nullptr);
    ~Localisation();

private slots:
    void on_pb_maps_clicked();

private:
    Ui::Localisation *ui;
};

#endif // LOCALISATION_H
