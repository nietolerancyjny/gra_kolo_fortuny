#include "hasla.h"
#include "ui_hasla.h"

//konstruktor
hasla::hasla(QWidget *parent) :

   QDialog(parent),
   ui(new Ui::hasla)
   {
       ui->setupUi(this);
   }

//destruktor
hasla::~hasla()
{
    delete ui;
}

//otwarcie pliku i przekazanie do zmiennej globalnej haslaPliku
void hasla::otworzPlik(bool decyzja)
{
    if(decyzja == 1)
        MainWindow::sciezkaPliku = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/", tr("Pliki txt (*.txt)"));
    QFile plik(MainWindow::sciezkaPliku);
    MainWindow::haslaPliku.clear();
    if(!plik.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream stream(&plik);
    MainWindow::haslaPliku = stream.readAll();
    ui->podglad->setText(MainWindow::haslaPliku);
    plik.close();

}

//Zapisanie pliku z haslami
void hasla::zapiszPlik()
{
    QFile plik(MainWindow::sciezkaPliku);
    plik.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&plik);
    stream << ui->podglad->toPlainText();
    plik.close();
    MainWindow::haslaPliku = ui->podglad->toPlainText();
}

void hasla::on_pushButtonOtworz_clicked()
{
   otworzPlik(1);
}

void hasla::on_pushButtonZapisz_clicked()
{
    zapiszPlik();
    this->close();
}


