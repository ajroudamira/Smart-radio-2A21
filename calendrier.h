#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <QDialog>

namespace Ui {
class calendrier;
}

class calendrier : public QDialog
{
    Q_OBJECT

public:
    explicit calendrier(QWidget *parent = nullptr);
    ~calendrier();

private:
    Ui::calendrier *ui;
};

#endif // CALENDRIER_H
