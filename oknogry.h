#ifndef OKNOGRY_H
#define OKNOGRY_H

#include "mainwindow.h"
#include <QDialog>
#include <QStringList>
#include <QToolButton>
#include <ctime>

namespace Ui {
class oknoGry;
}

class oknoGry : public QDialog
{
Q_OBJECT

public:
     explicit oknoGry(QWidget *parent = 0);
     ~oknoGry();
     void nowaGra();

private:
    Ui::oknoGry *ui;

    void wylosujHaslo();
    void stylPrzyciskow();
    void wyswietl();

    QString wylosowaneHaslo;
    QToolButton* tablica[59];
};


#endif // OKNOGRY_H
