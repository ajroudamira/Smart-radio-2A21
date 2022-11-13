#include "calendrier.h"
#include "ui_calendrier.h"

calendrier::calendrier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendrier)
{
    ui->setupUi(this);
}

calendrier::~calendrier()
{
    delete ui;
}

