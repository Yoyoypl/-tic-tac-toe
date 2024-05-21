#ifndef TEKRAN_HPP
#define TEKRAN_HPP

#include <string>
#include <vector>

class Tkolko;
class Tkrzyzyk;

class Tekran
{
private:
    std::string plansza = R"(
                    +-----------------------------------------------+
                    |               |               |               |
                    |               |               |               |
                    |               |               |               |
                    |               |               |               |
                    |               |               |               |
                    -------------------------------------------------
                    |               |               |               |
                    |               |               |               |
                    |               |               |               |
                    |               |               |               |
                    |               |               |               |
                    -------------------------------------------------
                    |               |               |               |
                    |               |               |               |
                    |               |               |               |
                    |               |               |               |
                    |               |               |               |
                    +-----------------------------------------------+)";

    int ile_o_pole_w_poziomie_bez_entera = 16; // tyle ma okienko dlugosci + 1 zeby przechodzilo jeszce jeden znak |
    int ile_z_enterem = 70;                    // tyle ma cala linijka
    int dana_pozycja = 0;                      // pozycja znaczka

    char znaczek = char(254); // jakim znakiek ma być znaczek

    std::vector<Tkolko> *kolka;
    std::vector<Tkrzyzyk> *krzyzyki;

public:
    Tekran(/* args */);
    ~Tekran();

    //--------------------------
    void pokaz_plansza();
    // pokaz plansze

    void zbadaj_gdzie_co_i_jak();
    // glowna funkcja koordynujaca

    void nakieruj_znacznik(char);
    // przy przesunieciu zmien pozycje znacznik

    void umiesc_znacznik(int, int);
    // umieszcza w stringu znacznik

    char pobierz_znak();
    // pobiera znak( no myslales ze inaczej cn)

    void zrob_klatke();
    // robi klatke

    void umiesc_kolko();
    // umieszcza kolko

    void umiesc_krzyzyk();
    // umieszcza krzyzyk

    void dodaj_kolko();
    // dodajesz kolko do vector kolek

    void dodaj_krzyzk();
    // dodajesz krzyzyk do vecotra krzrzykow

    // trzeba by bylo jakis silnik wymyslec cn?   -"narazie robie dwuosobowa gre aby pokazac grzesiowi ale pewnie i tak nie pokaze"
};

#endif