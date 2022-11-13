#ifndef LOCALISATION_H
#define LOCALISATION_H

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

private:
    Ui::Localisation *ui;
};

#endif // LOCALISATION_H
