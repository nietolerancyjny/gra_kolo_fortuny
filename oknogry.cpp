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
       wartosciNaKole<<"425$"<<"225$"<<"375$"<<"STOP"<<"25$"<<"275$"<<"400$"<<"325$"<<"100$"<<"Bankrut"<<"200$"<<"50$"<<"350$"<<"Nagroda"<<"175$"<<"475$"<<"300$"<<"125$"<<"75$"<<"1400$";
       stanGry = KRECENIE_KOLEM;
       katKola=0;
       stanKola=0;
       pozostaloLiterDoOdgadniecia = 0;
       kolejkaGracza = 0;
       wynikGracza[0] = 0;
       wynikGracza[1] = 0;
       wynikGracza[2] = 0;
       wynikGracza[3] = 0;
       stylPrzyciskow();
       nowaGra();
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
    sprawdzIloscLiterHasla();
    wylosujGracza();
    rozgrywka();
}

//************************************************
//rozgrywka własciwa
//************************************************
void oknoGry::rozgrywka()
{
    if (pozostaloLiterDoOdgadniecia <= 0) //sprawdzam czy koniec gry
        stanGry = KONIEC_GRY;

    switch(stanGry)
    {
        case KRECENIE_KOLEM:
             pokazPrzyciski(false);
             pokazKlawiature(false);
             pokazZakrecKolem(true);
             wyswietlKomunikat(WYSWIETL_WYNIK);
             wyswietlKomunikat(CZYJA_KOLEJKA);
             wyswietlKomunikat(ZAKREC_KOLEM);
             break;

        case ODGADUJE_LITERE:
             pokazSpolgloski(true);
             wyswietlKomunikat(ODGADNIJ_SAMOGLOSKE);
             break;

        case ODGADL_LITERE:
             wyswietlKomunikat(ZAKREC_KOLEM_LUB_KUP_SAMOGLOSKE);
             pokazKupSamogloski(true);
             pokazZakrecKolem(true);
             pokazOdgadujeHaslo(true);
             wyswietlKomunikat(WYSWIETL_WYNIK);
             break;

        case NIE_ODGADL_LITERY:
             nastepnyGracz();
             nastepnyStanGry(); //krecenie kolem
             break;

        case KUPUJE_SAMOGLOSKE:
             wynikGracza[kolejkaGracza] = wynikGracza[kolejkaGracza] - 200;
             wyswietlKomunikat(KUPIL_SAMOGLOSKE);
             wyswietlKomunikat(WYSWIETL_WYNIK);
             break;

        case BANKRUT:
             wyswietlKomunikatMsgBox(MainWindow::imionaGraczy[kolejkaGracza] + " twoj wynik wynosi 0 $ \nPrzy okazji tracisz kolejkę :P");
             wynikGracza[kolejkaGracza] = 0;
             nastepnyGracz();
             nastepnyStanGry();
             break;

        case NAGRODA:
             wylosujNagrode();
             break;

        case STOP:
             wyswietlKomunikatMsgBox(MainWindow::imionaGraczy[kolejkaGracza] + " tracisz kolejkę!");
             nastepnyGracz();
             nastepnyStanGry();
             break;

        case KONIEC_GRY:
             koniecGry();
             break;

    }
}
//************************************************
//nastepny stan gry
//************************************************
void oknoGry::nastepnyStanGry()
{
    switch(stanGry)
    {
       case KRECENIE_KOLEM:
            stanGry = ODGADL_LITERE;
            break;
       case ODGADL_LITERE:
            stanGry = KRECENIE_KOLEM;
            break;
       case NIE_ODGADL_LITERY:
            stanGry = KRECENIE_KOLEM;
            break;
       case KUPUJE_SAMOGLOSKE:
            stanGry = KRECENIE_KOLEM;
            break;
       default:
            stanGry = KRECENIE_KOLEM;
            break;
    }
    rozgrywka();
}

//************************************************
//koniec gry - wyswietlam msgbox z informacja o koncu i zamykam oknoGry
//************************************************
void oknoGry::koniecGry()
{
   switch(MainWindow::liczbaGraczy)
   {
       case 4:
            wyswietlKomunikatMsgBox("Wygrana!\n\n"
                                    + MainWindow::imionaGraczy.at(0) + " = " + QString::number(wynikGracza[0]) + " $\n"
                                    + MainWindow::imionaGraczy.at(1) + " = " + QString::number(wynikGracza[1]) + " $\n"
                                    + MainWindow::imionaGraczy.at(2) + " = " + QString::number(wynikGracza[2]) + " $\n"
                                    + MainWindow::imionaGraczy.at(3) + " = " + QString::number(wynikGracza[3]) + " $"
                                    + "\n\nKliknij ok by powrócić do menu!");
            break;
       case 3:
            wyswietlKomunikatMsgBox("Wygrana!\n\n"
                                    + MainWindow::imionaGraczy.at(0) + " = " + QString::number(wynikGracza[0]) + " $\n"
                                    + MainWindow::imionaGraczy.at(1) + " = " + QString::number(wynikGracza[1]) + " $\n"
                                    + MainWindow::imionaGraczy.at(2) + " = " + QString::number(wynikGracza[2]) + " $"
                                    + "\n\nKliknij ok by powrócić do menu!");
            break;
       default:
            wyswietlKomunikatMsgBox("Wygrana!\n\n"
                                    + MainWindow::imionaGraczy.at(0) + " = " + QString::number(wynikGracza[0]) + " $\n"
                                    + MainWindow::imionaGraczy.at(1) + " = " + QString::number(wynikGracza[1]) + " $"
                                    + "\n\nKliknij ok by powrócić do menu!");
   }
   this->close();
}

//************************************************
//losowanie nagrody
//************************************************
void oknoGry::wylosujNagrode()
{
    srand(time(0));
    int nagroda;
    nagroda = ( rand()%1500 ) + 1000;
    wynikGracza[kolejkaGracza] += nagroda;
    wyswietlKomunikat(WYSWIETL_WYNIK);
    wyswietlKomunikatMsgBox("Gratulacje!\n"
                            + MainWindow::imionaGraczy[kolejkaGracza]
                            + " wygrałeś hajs!\n"
                            + QString::number(nagroda)
                            + "$ !!!");
    nastepnyStanGry();
}

//====================================================================================================================
//======Gracze======Gracze======Gracze======Gracze======Gracze======Gracze======Gracze======Gracze======Gracze========
//====================================================================================================================

//************************************************
//wylosuj gracza ktory zaczyna
//************************************************
void oknoGry::wylosujGracza()
{
    srand(time(0));
    kolejkaGracza = rand()%MainWindow::liczbaGraczy;
}

//************************************************
//ustawia nastepnego gracza
//************************************************
void oknoGry::nastepnyGracz()
{
   if (MainWindow::liczbaGraczy - 1 == kolejkaGracza)
       kolejkaGracza = 0;
   else
       kolejkaGracza++;
}
//====================================================================================================================
//======Koło======Koło======Koło======Koło======Koło======Koło======Koło======Koło======Koło======Koło======Koło======
//====================================================================================================================

//************************************************
//wczytanie grafiki kola
//************************************************
void oknoGry::wczytajKolo()
{
    QGraphicsScene *scena = new QGraphicsScene(this);
    QPixmap *obrazek = new QPixmap("kolo.jpg");
    *obrazek=obrazek->scaled(380,380, Qt::KeepAspectRatio); //obrazek=obrazek.scaled(300,300, Qt::KeepAspectRatio);
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
    obroc();

    if(wartosciNaKole[stanKola] == "Bankrut")
    {
        stanGry = BANKRUT;
        rozgrywka();
    }
    else if(wartosciNaKole[stanKola] == "Nagroda")
    {
        stanGry = NAGRODA;
        rozgrywka();
    }
    else if(wartosciNaKole[stanKola] == "STOP")
    {
        stanGry = STOP;
        rozgrywka();
    }
    else //jakas tam kwota
    {
        stanGry = ODGADUJE_LITERE;
        rozgrywka();
    }
}

//************************************************
//obrot kołem
//************************************************
void oknoGry::obroc()
{
    srand(time(0));
    obrot = rand()%360;

    for(unsigned i=0; i <= obrot+300;i++)
    {
        ui->graphicsView->rotate(1);
        ui->graphicsView->repaint();
        katKola++;
        stanKola = (katKola%360)/18;
        stanKola %= 20;
        ui->TextEditKwota->setText(wartosciNaKole[stanKola]);
        //zabezpieczenie przed zapelnieniem zmiennnej
        if (katKola==360)
            katKola=0;
        Sleep(2 + (i * i/10000) );
    }
}

//====================================================================================================================
//======Hasło======Hasło======Hasło======Hasło======Hasło======Hasło======Hasło======Hasło======Hasło======Hasło======
//====================================================================================================================

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
//odgadywanie litery
//************************************************
void oknoGry::odgadujeLitere(QString znak, bool spolgloska)
{
    pokazKlawiature(false);
    int licznik = 0;
    bool czyWystapila = false;

    for (int i=0; i<60; i++)
    {
        if ( tablica[i]->text() == znak or tablica[i]->text().toLower() == znak )
        {
            tablica[i]->setStyleSheet("color: black;");
            licznik++;
            //pozostaloLiterDoOdgadniecia--;
        }
    }
    //jesli juz taka litera byla podana wczesniej
    for (int i=0; i<odgadywaneLitery.size(); i++)
    {
        if (QString::compare(znak, odgadywaneLitery.at(i), Qt::CaseInsensitive) == 0)
        {
           czyWystapila = true;
           wyswietlKomunikatMsgBox("Litera " + znak + " została juz sprawdzona, " + MainWindow::imionaGraczy[kolejkaGracza] + " tracisz kolejkę!");
           break;
        }
    }
    //zwiekszam wynik jesli odgadnieto litere
    if (licznik > 0 and !czyWystapila)
    {
        if (spolgloska)
            wynikGracza[kolejkaGracza] += licznik *  wartosciNaKole[stanKola].toInt();
        pozostaloLiterDoOdgadniecia -= licznik;
        stanGry = ODGADL_LITERE;
        rozgrywka();
    }
    else
    {
        stanGry = NIE_ODGADL_LITERY;
        rozgrywka();
    }

    ui->labelInformacjaLitery->setText("Litera '" + znak.toUpper() + "' wystąpiła " + QString::number(licznik) + "x");
    odgadywaneLitery << znak;
    czyWystapila = false;
    ui->lineEditDevPodglad->setText(QString::number(pozostaloLiterDoOdgadniecia));


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
//sprawdza ile liter wystepuje w hasle, z pominieciem spacji, kropki i przecinka
//************************************************

void oknoGry::sprawdzIloscLiterHasla()
{
    pozostaloLiterDoOdgadniecia = 0;
    for (int i=0; i < wylosowaneHaslo.size(); i++)
    {
        if (wylosowaneHaslo.at(i) == ',' or wylosowaneHaslo.at(i) == '.' or wylosowaneHaslo.at(i) == '-' or wylosowaneHaslo.at(i) == ' ')
        {}else
            pozostaloLiterDoOdgadniecia++;
    }
}

//====================================================================================================================
//======Wyswietlacz/Okno======Wyswietlacz/Okno======Wyswietlacz/Okno======Wyswietlacz/Okno======Wyswietlacz/Okno======
//====================================================================================================================

//************************************************
//wyswietla msgBox'a
//************************************************
void oknoGry::wyswietlKomunikatMsgBox(QString komunikat)
{
   QMessageBox msgBox;
   msgBox.setText(komunikat);
   msgBox.exec();
}

//************************************************
//wyswietla komunikaty (OknoGry)
//************************************************
void oknoGry::wyswietlKomunikat(int komunikat)
{
    switch(komunikat)
    {
        case CZYJA_KOLEJKA:
            ui->labelKolejkaGracza->setText("Gra " + MainWindow::imionaGraczy[kolejkaGracza]);
            break;
        case ZAKREC_KOLEM:
            ui->labelInformacja->setText(MainWindow::imionaGraczy[kolejkaGracza] + " zakręc kołem");
            break;
        case ZAKREC_KOLEM_LUB_KUP_SAMOGLOSKE:
            ui->labelInformacja->setText(MainWindow::imionaGraczy[kolejkaGracza] + " zakręc kołem, kup samogłoskę lub odgadnij hasło");
            break;
        case ODGADNIJ_SAMOGLOSKE:
            ui->labelInformacja->setText(MainWindow::imionaGraczy[kolejkaGracza] + " odgadnij samogłoskę");
            break;
        case KUPIL_SAMOGLOSKE:
            ui->labelInformacja->setText(MainWindow::imionaGraczy[kolejkaGracza] + " wybierz samogłoskę");
            break;
        case WYSWIETL_WYNIK:
            ui->labelWynikGracza1->setText(MainWindow::imionaGraczy[0] + " = " + QString::number(wynikGracza[0]) + " $");
            ui->labelWynikGracza2->setText(MainWindow::imionaGraczy[1] + " = " + QString::number(wynikGracza[1]) + " $");
            ui->labelWynikGracza3->setText(MainWindow::imionaGraczy[2] + " = " + QString::number(wynikGracza[2]) + " $");
            ui->labelWynikGracza4->setText(MainWindow::imionaGraczy[3] + " = " + QString::number(wynikGracza[3]) + " $");
            break;
    }
}

//************************************************
//odgaduje haslo
//************************************************
void oknoGry::odgadujeHaslo()
{
    bool czyOk;

    QString hasloGracza = QInputDialog::getText(this,"Zgaduj","Podaj hasło",QLineEdit::Normal,"",&czyOk);
    if(czyOk == true and QString::compare(hasloGracza, wylosowaneHaslo, Qt::CaseInsensitive) == 0)
    {
        wyswietlHaslo();
        stanGry = KONIEC_GRY;
        rozgrywka();
    }
    else
    {
        wyswietlKomunikatMsgBox("Podane haslo jest nieprawidłowe");
        nastepnyGracz();
        nastepnyStanGry();
    }
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
//blokowanie / odblokowywanie wszystkich przycisków
//************************************************
void oknoGry::pokazPrzyciski(bool decyzja)
{

   ui->pbZakrecKolem->setEnabled(decyzja);
   ui->pbOdgadnijHaslo->setEnabled(decyzja);
  // ui->pbWyswietl->setEnabled(decyzja);
   ui->pbKupSamogloske->setEnabled(decyzja);
  // ui->pbUkryj->setEnabled(decyzja);
}

//************************************************
//blokowanie / odblokowywanie klawiatury
//************************************************
void oknoGry::pokazKlawiature(bool decyzja)
{
    pokazSamogloski(decyzja);
    pokazSpolgloski(decyzja);
}

//************************************************
//pokazuje pushbutton Odgadnij haslo
//************************************************
void oknoGry::pokazOdgadujeHaslo(bool decyzja)
{
    ui->pbOdgadnijHaslo->setEnabled(decyzja);
}

//************************************************
//style przyciskow, tekstu, formatowanie etc
//************************************************
void oknoGry::stylPrzyciskow()
{
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, "#ece9d8");
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    ui->graphicsView->setStyleSheet("background-color: #ece9d8;");
    qApp->setStyleSheet("QToolButton {  border: 1px solid #000000; border-radius: 0px; background-color: #ece9d8; color: black; }");
    ui->TextEditKwota->setStyleSheet("background-color: #ece9d8; color: black;");
    ui->labelInformacjaLitery->setText("");
    //wyniki graczy
    ui->labelWynikGracza3->hide();
    ui->labelWynikGracza4->hide();
    if (MainWindow::liczbaGraczy == 3)
    {
        ui->labelWynikGracza3->show();
    }
    if (MainWindow::liczbaGraczy == 4)
    {
        ui->labelWynikGracza3->show();
        ui->labelWynikGracza4->show();
    }
}

//************************************************
//pushbutton zakrec kolem
//************************************************
void oknoGry::pokazZakrecKolem(bool decyzja)
{
    ui->pbZakrecKolem->setEnabled(decyzja);
}

//************************************************
//pushbutton zakrec kup samogloski
//************************************************
void oknoGry::pokazKupSamogloski(bool decyzja)
{
    ui->pbKupSamogloske->setEnabled(decyzja);
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
//zakrywanie pustych znakow  zmiana koloru buttona
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

//====================================================================================================================
//======PushButtony======PushButtony======PushButtony======PushButtony======PushButtony======PushButtony==============
//====================================================================================================================

//************************************************
//przycisk odgaduje haslo
//************************************************
void oknoGry::on_pbOdgadnijHaslo_clicked()
{
    odgadujeHaslo();
}

void oknoGry::on_pbUkryj_clicked()
{
    ukryjHaslo();
}

void oknoGry::on_pbWyswietl_clicked()
{
    wyswietlHaslo();
}

void oknoGry::on_pbKupSamogloske_clicked()
{
    if ( wynikGracza[kolejkaGracza] >= 200)
    {
        pokazSamogloski(true);
        pokazSpolgloski(false);
        stanGry = KUPUJE_SAMOGLOSKE;
        rozgrywka();
    }
    else
        wyswietlKomunikatMsgBox(MainWindow::imionaGraczy[kolejkaGracza] + " nie masz wystarczającej ilości gotówki!!");
}

//************************************************
//Klawiatura
//************************************************
void oknoGry::on_klaw_y_clicked()
{
    odgadujeLitere("y", false);
}

void oknoGry::on_klaw_u_clicked()
{
    odgadujeLitere("u", false);
}

void oknoGry::on_klaw_oPL_clicked()
{
    odgadujeLitere("ó", false);
}

void oknoGry::on_klaw_o_clicked()
{
    odgadujeLitere("o", false);
}

void oknoGry::on_klaw_i_clicked()
{
    odgadujeLitere("i", false);
}

void oknoGry::on_klaw_ePL_clicked()
{
    odgadujeLitere("ę", false);
}

void oknoGry::on_klaw_e_clicked()
{
    odgadujeLitere("e", false);
}

void oknoGry::on_klaw_aPL_clicked()
{
    odgadujeLitere("ą", false);
}

void oknoGry::on_klaw_a_clicked()
{
    odgadujeLitere("a", false);
}

void oknoGry::on_klaw_zPL_clicked()
{
    odgadujeLitere("ż", true);
}

void oknoGry::on_klaw_zPL2_clicked()
{
    odgadujeLitere("ź", true);
}

void oknoGry::on_klaw_z_clicked()
{
    odgadujeLitere("z", true);
}

void oknoGry::on_klaw_w_clicked()
{
    odgadujeLitere("w", true);
}

void oknoGry::on_klaw_x_clicked()
{
    odgadujeLitere("x", true);
}

void oknoGry::on_klaw_v_clicked()
{
    odgadujeLitere("v", true);
}

void oknoGry::on_klaw_t_clicked()
{
    odgadujeLitere("t", true);
}

void oknoGry::on_klaw_sPL_clicked()
{
    odgadujeLitere("ś", true);
}

void oknoGry::on_klaw_s_clicked()
{
    odgadujeLitere("s", true);
}

void oknoGry::on_klaw_r_clicked()
{
    odgadujeLitere("r", true);
}

void oknoGry::on_klaw_q_clicked()
{
    odgadujeLitere("q", true);
}

void oknoGry::on_klaw_p_clicked()
{
    odgadujeLitere("p", true);
}

void oknoGry::on_klaw_nPL_clicked()
{
    odgadujeLitere("ń", true);
}

void oknoGry::on_klaw_n_clicked()
{
    odgadujeLitere("n", true);
}

void oknoGry::on_klaw_m_clicked()
{
    odgadujeLitere("m", true);
}

void oknoGry::on_klaw_lPL_clicked()
{
    odgadujeLitere("ł", true);
}

void oknoGry::on_klaw_l_clicked()
{
    odgadujeLitere("l", true);
}

void oknoGry::on_klaw_k_clicked()
{
    odgadujeLitere("k", true);
}

void oknoGry::on_klaw_j_clicked()
{
    odgadujeLitere("j", true);
}

void oknoGry::on_klaw_h_clicked()
{
    odgadujeLitere("h", true);
}

void oknoGry::on_klaw_g_clicked()
{
    odgadujeLitere("g", true);
}

void oknoGry::on_klaw_f_clicked()
{
    odgadujeLitere("f", true);
}

void oknoGry::on_klaw_d_clicked()
{
    odgadujeLitere("d", true);
}

void oknoGry::on_klaw_cPL_clicked()
{
    odgadujeLitere("ć", true);
}

void oknoGry::on_klaw_c_clicked()
{
    odgadujeLitere("c", true);
}

void oknoGry::on_klaw_b_clicked()
{
    odgadujeLitere("b", true);
}


