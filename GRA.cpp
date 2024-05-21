#include "naglowek.hpp"
#include <conio.h>

void start()
{
    Tekran *gra1 = new Tekran;
    while (true)
    {
        gra1->zbadaj_gdzie_co_i_jak();
    }
}
