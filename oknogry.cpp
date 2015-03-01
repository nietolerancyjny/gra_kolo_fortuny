#include "oknogry.h"
#include "ui_oknogry.h"



//konstruktor
oknoGry::oknoGry(QWidget *parent) :

   QDialog(parent),
   ui(new Ui::oknoGry)
   {
       ui->setupUi(this);
       tablica[0]=ui->litera_1; tablica[1]=ui->litera_2; tablica[2]=ui->litera_3; tablica[3]=ui->litera_4; tablica[4]=ui->litera_5; tablica[5]=ui->litera_6; tablica[6]=ui->litera_7; tablica[7]=ui->litera_8; tablica[8]=ui->litera_9; tablica[9]=ui->litera_10; tablica[10]=ui->litera_11; tablica[11]=ui->litera_12; tablica[12]=ui->litera_13; tablica[13]=ui->litera_14; tablica[14]=ui->litera_15; tablica[15]=ui->litera_16;
       tablica[16]=ui->litera_17; tablica[17]=ui->litera_18; tablica[18]=ui->litera_19; tablica[19]=ui->litera_20; tablica[20]=ui->litera_21; tablica[21]=ui->litera_22; tablica[22]=ui->litera_23; tablica[23]=ui->litera_24; tablica[24]=ui->litera_25; tablica[25]=ui->litera_26; tablica[26]=ui->litera_27; tablica[27]=ui->litera_28; tablica[28]=ui->litera_29; tablica[29]=ui->litera_30; tablica[30]=ui->litera_31; tablica[31]=ui->litera_32;
       tablica[32]=ui->litera_33; tablica[33]=ui->litera_34; tablica[34]=ui->litera_35; tablica[35]=ui->litera_36; tablica[36]=ui->litera_37; tablica[37]=ui->litera_38; tablica[38]=ui->litera_39; tablica[39]=ui->litera_40; tablica[40]=ui->litera_41; tablica[41]=ui->litera_42; tablica[42]=ui->litera_43; tablica[43]=ui->litera_44; tablica[44]=ui->litera_45; tablica[45]=ui->litera_46; tablica[46]=ui->litera_47; tablica[47]=ui->litera_48; tablica[48]=ui->litera_49;
       tablica[49]=ui->litera_50; tablica[50]=ui->litera_51; tablica[51]=ui->litera_52; tablica[52]=ui->litera_53; tablica[53]=ui->litera_54; tablica[54]=ui->litera_55; tablica[55]=ui->litera_56; tablica[56]=ui->litera_57; tablica[57]=ui->litera_58; tablica[58]=ui->litera_59; tablica[59]=ui->litera_60;
   }

//destruktor
oknoGry::~oknoGry()
{
    delete ui;
}

//rozpoczecie nowej gry
void oknoGry::nowaGra()
{
    stylPrzyciskow();
    wylosujHaslo();
    wyswietl();
}

//losowanie hasla
void oknoGry::wylosujHaslo()
{
    QStringList listaZHaslami = MainWindow::haslaPliku.split("\n");  //tworzenie listy z haslami
    srand(time(0));
    wylosowaneHaslo = listaZHaslami[rand()%listaZHaslami.size()];
}

void oknoGry::stylPrzyciskow()
{
   qApp->setStyleSheet("QToolButton {  border: 1px solid #000000; border-radius: 0px; background-color: grey; color: black; }");
}

void oknoGry::wyswietl()
{
    QStringList wyrazyHasla = wylosowaneHaslo.split(" ", QString::SkipEmptyParts);
    int iloscLiter = 0;
    int iloscLiterDoWykorzystania = 15;
    int iloscLiterDoDodania = 0;

    for (int i=0; i<wyrazyHasla.size(); i++)
    {
        //iloscLiterDoDodania = 0;

        if (iloscLiterDoWykorzystania - wyrazyHasla[i].size() + 1 >= 0) // tu jeszcze cos musi byc ale nie wiem co
        {
            iloscLiterDoWykorzystania = iloscLiterDoWykorzystania - wyrazyHasla[i].size() + 1;
            //iloscLiterDoDodania = 0;


        }
        else
        {
            iloscLiterDoDodania += iloscLiterDoWykorzystania;
            iloscLiterDoWykorzystania = 15;
        }

        for (int j=0; j<wyrazyHasla[i].size(); j++)
        {
            tablica[j + iloscLiter + iloscLiterDoDodania]->setText(wyrazyHasla[i].at(j));
        }
        iloscLiter += wyrazyHasla[i].size() + 1;

    }

   /* for (int i=0; i<wylosowaneHaslo.size(); i++)
    {

        tablica[i]->setText(wylosowaneHaslo.at(i));


        //ui->litera_10->setText("A");

       // ui->TextEditHaslo->setText(tablicaHasla[i]);
    }
    */

}
