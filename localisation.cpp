#include "localisation.h"
#include "ui_localisation.h"

Localisation::Localisation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Localisation)
{
    ui->setupUi(this);
}

Localisation::~Localisation()
{
    delete ui;
}
