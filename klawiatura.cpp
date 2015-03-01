#include "klawiatura.h"
#include "ui_klawiatura.h"

#include <QApplication>


//konstruktor
klawiatura::klawiatura(QWidget *parent) :

   QDialog(parent),
   ui(new Ui::klawiatura)
   {
       ui->setupUi(this);
   }

//destruktor
klawiatura::~klawiatura()
{
    delete ui;
}

