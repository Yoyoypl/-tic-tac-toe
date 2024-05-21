#include <iostream>
#include <conio.h>
#include "class/Tekran.hpp"

using namespace ::std;

Tekran::Tekran(/* args */) : kolka{new vector<Tkolko>}, krzyzyki{new vector<Tkrzyzyk>}
{
}

Tekran::~Tekran()
{
}

void Tekran::pokaz_plansza()
{
    cout << plansza << endl;
}

char Tekran::pobierz_znak()
{
    char a = getch();
    return a;
}

void Tekran::zrob_klatke()
{
    system("cls");
    // czyscimy ekran robiac tz. klatke(fps)
    pokaz_plansza();
    // pokazujemy plansze
}

void Tekran::umiesc_znacznik(int dawna_pozycja, int aktualna_pozycja)
{
    string co_umiescic = "set here?";
    // usuwanie elementu stringu "set here"

    int gdzie_wstwawic_puste_miejsce;
    int ktory_wiersz_usuwanie = dawna_pozycja / 3;
    int ktory_rzad_usuwanie = dawna_pozycja % 3;

    // zmienne do dawnej pozycji

    gdzie_wstwawic_puste_miejsce = plansza.find('|') + (2 * ile_z_enterem) + (ktory_wiersz_usuwanie * (ile_z_enterem * (5 + 1))) + 4 + (ile_o_pole_w_poziomie_bez_entera * ktory_rzad_usuwanie);
    //                    znajdz pierwsze wystwpowanie | /// pozycja wysrodkuwojaca /// jaki wiersz(zeby przeskakiwalo odpowiednia ilosc) /// pozycja wysrodkuwajaca w polu /// ktory rzad
    for (int i = gdzie_wstwawic_puste_miejsce, j = 0; j < 9; i++, j++)
    {
        plansza[i] = ' ';
    }

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------

    // wstawianie stringu "set here"

    int gdzie_wstawic_string;
    int ktory_wiersz_wstawienie = aktualna_pozycja / 3;
    int ktory_rzad_wstawienie = aktualna_pozycja % 3;

    // zmienne do aktualnej pozycji

    gdzie_wstawic_string = plansza.find('|') + (2 * ile_z_enterem) + (ktory_wiersz_wstawienie * (ile_z_enterem * (5 + 1))) + 4 + (ile_o_pole_w_poziomie_bez_entera * ktory_rzad_wstawienie);
    //                    znajdz pierwsze wystwpowanie | /// pozycja wysrodkuwojaca /// jaki wiersz(zeby przeskakiwalo odpowiednia ilosc) /// pozycja wysrodkuwajaca w polu /// ktory rzad
    for (int i = gdzie_wstawic_string, j = 0; j < 9; i++, j++)
    {
        plansza[i] = co_umiescic[j];
    }
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------
}

void Tekran::umiesc_kolko()
{
}

void Tekran::umiesc_krzyzyk()
{
}

void Tekran::nakieruj_znacznik(char znaczek)
{

    switch (znaczek)
    {
    case 'w':
        if (dana_pozycja > 2)
        {
            dana_pozycja -= 3;
            umiesc_znacznik(dana_pozycja + 3, dana_pozycja);
            zrob_klatke();
        }
        break;
    case 's':
        if (dana_pozycja < 6)
        {
            dana_pozycja += 3;
            umiesc_znacznik(dana_pozycja - 3, dana_pozycja);
            zrob_klatke();
        }
        break;
    case 'a':
        if (dana_pozycja != 0 and dana_pozycja != 3 and dana_pozycja != 6)
        {
            dana_pozycja -= 1;
            umiesc_znacznik(dana_pozycja + 1, dana_pozycja);
            zrob_klatke();
        }
        break;
    case 'd':
        if (dana_pozycja != 2 and dana_pozycja != 5 and dana_pozycja != 8)
        {
            dana_pozycja += 1;
            umiesc_znacznik(dana_pozycja - 1, dana_pozycja);
            zrob_klatke();
        }
        break;
    case '\r':
        //! tu rob dalej
        break;
    case '0':
        exit(0);
        break;
        // wybranie opcji zaleznej od wejscia

    default:
        return; // przy blednym wejsciu funkcja konczy prace i nie robi klatki
        break;
    }

    //! zastanawisz sie pewnie dlaczego jest to w tej funkvji jest zrob_klatke() a no dlatego ze inaczej pry blednym wejsciu bedzie ona robila klatkea a chcemy uniknac niepotzrenych przejsc
}

void Tekran::zbadaj_gdzie_co_i_jak()
{
    pokaz_plansza();
    char current_charachter;
    while (true)
    {

        current_charachter = pobierz_znak();
        // pobieramy znak i zapisujemy go w obecnej zmiennej

        nakieruj_znacznik(current_charachter);
        // wysylamy znak aby wyswietlic przesuniecie
    }
}
