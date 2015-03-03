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
       katKola=0;
       stanKola=0;
       wartosciNaKole<<"425"<<"225"<<"375"<<"STOP"<<"25"<<"275"<<"400"<<"325"<<"100"<<"Bankrut"<<"200"<<"50"<<"350"<<"Nagroda"<<"175"<<"475"<<"300"<<"125"<<"75"<<"1400";
       stylPrzyciskow();
   }

//destruktor
oknoGry::~oknoGry()
{
    delete ui;
}
//************************************************
//rozpoczecie nowej gry
//************************************************
void oknoGry::nowaGra()
{
    wczytajKolo();
    wylosujHaslo();
    wyczyscEkran();
    wstawHaslo();
    ukryjHaslo();


}

//************************************************
//wczytanie grafiki kola
//************************************************
void oknoGry::wczytajKolo()
{
    QGraphicsScene *scena = new QGraphicsScene(this);
    QPixmap *obrazek = new QPixmap("kolo.jpg");
    //*obrazek=obrazek->scaled(380,380, Qt::KeepAspectRatio); //obrazek=obrazek.scaled(300,300, Qt::KeepAspectRatio);
    scena->addPixmap(*obrazek);
    ui->graphicsView->setScene(scena);
    ui->graphicsView->setAlignment(Qt::AlignHCenter);
    ui->graphicsView->setAlignment(Qt::AlignVCenter);
    ui->TextEditKwota->setText(wartosciNaKole[0]);
    delete obrazek;
}

//************************************************
//Zakrecenie kołem przycisk
//************************************************
void oknoGry::on_pbZakrecKolem_clicked()
{
    pokazPrzyciski(false);
    srand(time(0));
    obrot = rand()%360;
    spowolnienie = ( rand()%30 ) + 30;
    timer = new QTimer(this);
    timer->connect(timer,SIGNAL(timeout()),this,SLOT(obroc()));
    timer->start(5);
}

//************************************************
//obrot kołem
//************************************************
void oknoGry::obroc()
{
    int static j = 0 ;

    if(j==obrot+360)
    {
        timer->stop();
        j=0;

        if(wartosciNaKole[stanKola]=="Bankrut")
        {

            //suma_gracze[stan_gry]=0;
            //Plansza::Kolejny_stan_gry();
            //Plansza::Wyswietl_komunikat(bankrut);

        }else if(wartosciNaKole[stanKola]=="Nagroda")
        {
            //Plansza::Wyswietl_komunikat(nagroda);


        }else if(wartosciNaKole[stanKola]=="STOP")
        {
            //Plansza::Kolejny_stan_gry();
            //Plansza::Wyswietl_komunikat(stop);

        }else
        {
            //Plansza::Wyswietl_klawiature();
        }
        pokazPrzyciski(true);
        //Plansza::Zablokuj_Odblokuj_przyciski(false);
        //ui->pbZakrecKolem->blockSignals(true);

    }
    ++katKola;
    katKola = katKola%360;
    stanKola = (katKola/18);
    stanKola %= 20;
    ui->TextEditKwota->setText(wartosciNaKole[stanKola]);

    if(j<obrot+300)
    {
        ui->graphicsView->rotate(1);
    }else if(j<spowolnienie+300+obrot){
        for(int i=0;i<1000;i++){
            ui->graphicsView->rotate(0.001);
        }
    }else{
        for(int i=0;i<5000;i++){
            ui->graphicsView->rotate(0.0002);
        }
    }
    j++;
}


//************************************************
//losowanie hasla i zmiana na duze litery
//************************************************
void oknoGry::wylosujHaslo()
{
    QStringList listaZHaslami = MainWindow::haslaPliku.split("\n");  //tworzenie listy z haslami
    srand(time(0));
    wylosowaneHaslo = listaZHaslami[rand()%listaZHaslami.size()].toUpper();
}

//************************************************
//ustawienie stylu przyciskow
//************************************************
void oknoGry::stylPrzyciskow()
{
   qApp->setStyleSheet("QToolButton {  border: 1px solid #000000; border-radius: 0px; background-color: #ece9d8; color: black; }");
   ui->TextEditKwota->setStyleSheet("background-color: #ece9d8; color: black;");
}
//************************************************
//czyszczenie ekranu z liter
//************************************************
void oknoGry::wyczyscEkran()
{
    for (int i=0; i<60; i++)
    {
       tablica[i]->setText("");
    }
}
//************************************************
//odgadywanie litery
//************************************************
int oknoGry::odgadujeLitere(QString znak)
{
    int licznik = 0;
    for (int i=0; i<60; i++)
    {
        if (tablica[i]->text() == znak or tablica[i]->text().toLower() == znak)
        {
            tablica[i]->setStyleSheet("color: black;");
            licznik++;
        }
    }
    return licznik;
}
//************************************************
//zakrywanie pustych znakow zmiana koloru buttona
//************************************************
void oknoGry::kolorujPusteZnaki()
{
    for (int i=0; i<60; i++)
    {
       if (tablica[i]->text().isEmpty() or tablica[i]->text() == "," or tablica[i]->text() == "." or tablica[i]->text() == "-")
       {
            tablica[i]->setStyleSheet("background-color: gray;");
       }
    }
}
//************************************************
//ukrywa haslo (zmienia kolor czcionki na kolor tła)
//************************************************
void oknoGry::ukryjHaslo()
{
    for (int i=0; i<60; i++)
    {
       if (tablica[i]->text().isEmpty() or tablica[i]->text() == "," or tablica[i]->text() == "." or tablica[i]->text() == "-"){}
       else
           tablica[i]->setStyleSheet("color: #ece9d8;");
    }
}
//************************************************
//wyswietla haslo
//************************************************
void oknoGry::wyswietlHaslo()
{
    for (int i=0; i<60; i++)
    {
       if (tablica[i]->text().isEmpty() == false)
       {
            tablica[i]->setStyleSheet("color: black;");
            if( tablica[i]->text() == "," or tablica[i]->text() == "." or tablica[i]->text() == "-")
                tablica[i]->setStyleSheet("background-color: gray;");
       }
    }
}
//************************************************
//wstawianie hasla do ekranu
//************************************************
void oknoGry::wstawHaslo()
{
    QStringList wyrazyHasla = wylosowaneHaslo.split(" ", QString::SkipEmptyParts);
    int iloscLiter = 0;
    int numerWiersza = 0;
    int iloscLiterDoWykorzystania = 15;

    for (int i=0; i<wyrazyHasla.size(); i++)
    {
        if (iloscLiterDoWykorzystania - ( wyrazyHasla[i].size() + 1 ) >= 0 ) //sprawdzam czy zmiesci sie na ekranie
        {
            iloscLiterDoWykorzystania -= ( wyrazyHasla[i].size() + 1 ); //jesli tak to odejmuje i czekam na kolejny wyraz
        }
        else //jesli sie nie miesci to przejdz do kolejnego wiersza
        {
            numerWiersza++;
            iloscLiter = 0;
            iloscLiterDoWykorzystania = 15 - (wyrazyHasla[i].size() );
        }
        if (wyrazyHasla[i].size() + iloscLiter + numerWiersza * 15 <= 60) //sprawdzam czy haslo zmiesci sie na ekranie
        {
            for (int j=0; j<wyrazyHasla[i].size(); j++)
            {
                tablica[j + iloscLiter + numerWiersza * 15]->setText(wyrazyHasla[i].at(j)); //wypisywanie na ekran
            }
        iloscLiter += wyrazyHasla[i].size() + 1;
        }
        else //jesli haslo nie miesci sie na ekranie to zacznij od poczatku
        {
            nowaGra();
            break;
        }
    }
    kolorujPusteZnaki();
}
//************************************************
//pokaz samogloski
//************************************************
void oknoGry::pokazSamogloski(bool decyzja)
{
    ui->klaw_a->setEnabled(decyzja);
    ui->klaw_aPL->setEnabled(decyzja);
    ui->klaw_e->setEnabled(decyzja);
    ui->klaw_ePL->setEnabled(decyzja);
    ui->klaw_i->setEnabled(decyzja);
    ui->klaw_o->setEnabled(decyzja);
    ui->klaw_oPL->setEnabled(decyzja);
    ui->klaw_u->setEnabled(decyzja);
    ui->klaw_y->setEnabled(decyzja);
}

//************************************************
//pokaz spółgłoski
//************************************************
void oknoGry::pokazSpolgloski(bool decyzja)
{
    ui->klaw_b->setEnabled(decyzja); ui->klaw_c->setEnabled(decyzja); ui->klaw_cPL->setEnabled(decyzja);
    ui->klaw_d->setEnabled(decyzja); ui->klaw_f->setEnabled(decyzja); ui->klaw_g->setEnabled(decyzja);
    ui->klaw_h->setEnabled(decyzja); ui->klaw_j->setEnabled(decyzja); ui->klaw_k->setEnabled(decyzja);
    ui->klaw_l->setEnabled(decyzja); ui->klaw_lPL->setEnabled(decyzja); ui->klaw_m->setEnabled(decyzja);
    ui->klaw_n->setEnabled(decyzja); ui->klaw_nPL->setEnabled(decyzja); ui->klaw_p->setEnabled(decyzja);
    ui->klaw_q->setEnabled(decyzja); ui->klaw_r->setEnabled(decyzja); ui->klaw_s->setEnabled(decyzja);
    ui->klaw_sPL->setEnabled(decyzja); ui->klaw_t->setEnabled(decyzja); ui->klaw_v->setEnabled(decyzja);
    ui->klaw_w->setEnabled(decyzja); ui->klaw_x->setEnabled(decyzja); ui->klaw_z->setEnabled(decyzja);
    ui->klaw_zPL->setEnabled(decyzja); ui->klaw_zPL2->setEnabled(decyzja);
}

//************************************************
//blokowanie / odblokowywanie przycisków
//************************************************
void oknoGry::pokazPrzyciski(bool decyzja)
{
   pokazSamogloski(decyzja);
   pokazSpolgloski(decyzja);
   ui->pbZakrecKolem->setEnabled(decyzja);
   ui->pbWyswietl->setEnabled(decyzja);
   ui->pbKlawiatura->setEnabled(decyzja);
   ui->pbLitera->setEnabled(decyzja);
   ui->pbNowe->setEnabled(decyzja);
   ui->pbOdgadnijHaslo->setEnabled(decyzja);
   ui->pbUkryj->setEnabled(decyzja);
}

//************************************************
// PushButtony
//************************************************
void oknoGry::on_pbUkryj_clicked()
{
    ukryjHaslo();
}

void oknoGry::on_pbWyswietl_clicked()
{
    wyswietlHaslo();
}

void oknoGry::on_pbLitera_clicked()
{
   pokazSamogloski(false);
   pokazSpolgloski(true);
}

void oknoGry::on_pbKlawiatura_clicked()
{
    pokazSamogloski(true);
    pokazSpolgloski(false);
}

//button nowaGra
void oknoGry::on_pbNowe_clicked()
{
    nowaGra();
}

//przycisk odgaduje haslo
void oknoGry::on_pbOdgadnijHaslo_clicked()
{

    bool czyOk;

    QString hasloGracza = QInputDialog::getText(this,"Zgaduj","Podaj hasło",QLineEdit::Normal,"",&czyOk);
    if(czyOk == true and QString::compare(hasloGracza, wylosowaneHaslo, Qt::CaseInsensitive) == 0)
    {
        ui->lineEdit->setText("Wygrałeś!!!");
        wyswietlHaslo();
    }


}

//************************************************
//Klawiatura
//************************************************
void oknoGry::on_klaw_y_clicked()
{
    odgadujeLitere("y");
}

void oknoGry::on_klaw_u_clicked()
{
    odgadujeLitere("u");
}

void oknoGry::on_klaw_oPL_clicked()
{
    odgadujeLitere("ó");
}

void oknoGry::on_klaw_o_clicked()
{
    odgadujeLitere("o");
}

void oknoGry::on_klaw_i_clicked()
{
    odgadujeLitere("i");
}

void oknoGry::on_klaw_ePL_clicked()
{
    odgadujeLitere("ę");
}

void oknoGry::on_klaw_e_clicked()
{
    odgadujeLitere("e");
}

void oknoGry::on_klaw_aPL_clicked()
{
    odgadujeLitere("ą");
}

void oknoGry::on_klaw_a_clicked()
{
   //ui->TextEditHaslo->setText(QString::number(odgadujeLitere("a")));
    odgadujeLitere("a");
}

void oknoGry::on_klaw_zPL_clicked()
{
    odgadujeLitere("ż");
}

void oknoGry::on_klaw_zPL2_clicked()
{
    odgadujeLitere("ź");
}

void oknoGry::on_klaw_z_clicked()
{
    odgadujeLitere("z");
}

void oknoGry::on_klaw_w_clicked()
{
    odgadujeLitere("w");
}

void oknoGry::on_klaw_x_clicked()
{
    odgadujeLitere("x");
}

void oknoGry::on_klaw_v_clicked()
{
    odgadujeLitere("v");
}

void oknoGry::on_klaw_t_clicked()
{
    odgadujeLitere("t");
}

void oknoGry::on_klaw_sPL_clicked()
{
    odgadujeLitere("ś");
}

void oknoGry::on_klaw_s_clicked()
{
    odgadujeLitere("s");
}

void oknoGry::on_klaw_r_clicked()
{
    odgadujeLitere("r");
}

void oknoGry::on_klaw_q_clicked()
{
    odgadujeLitere("q");
}

void oknoGry::on_klaw_p_clicked()
{
    odgadujeLitere("p");
}

void oknoGry::on_klaw_nPL_clicked()
{
    odgadujeLitere("ń");
}

void oknoGry::on_klaw_n_clicked()
{
    odgadujeLitere("n");
}

void oknoGry::on_klaw_m_clicked()
{
    odgadujeLitere("m");
}

void oknoGry::on_klaw_lPL_clicked()
{
    odgadujeLitere("ł");
}

void oknoGry::on_klaw_l_clicked()
{
    odgadujeLitere("l");
}

void oknoGry::on_klaw_k_clicked()
{
    odgadujeLitere("k");
}

void oknoGry::on_klaw_j_clicked()
{
    odgadujeLitere("j");
}

void oknoGry::on_klaw_h_clicked()
{
    odgadujeLitere("h");
}

void oknoGry::on_klaw_g_clicked()
{
    odgadujeLitere("g");
}

void oknoGry::on_klaw_f_clicked()
{
    odgadujeLitere("f");
}

void oknoGry::on_klaw_d_clicked()
{
    odgadujeLitere("d");
}

void oknoGry::on_klaw_cPL_clicked()
{
    odgadujeLitere("ć");
}

void oknoGry::on_klaw_c_clicked()
{
    odgadujeLitere("c");
}

void oknoGry::on_klaw_b_clicked()
{
    odgadujeLitere("b");
}



