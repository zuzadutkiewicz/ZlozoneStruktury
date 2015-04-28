#include <stdlib.h>
#include <random>

#include "GenerujDane.hpp"

using namespace std;

void GenerujDane::dajDane(int tab[], int liczbaElem)
{
        uniform_int_distribution<int> distribution(0, 4000000);
    mt19937 engine;
    for(int i = 0; i < liczbaElem; i++)
    {
        int liczba = distribution(engine);

        while(jestWTablicy(tab, i-1, liczba))
        {
            liczba = distribution(engine);
        }
        tab[i] = liczba;
    }

}

void GenerujDane::dajDanePermutowane(int tab[], int liczbaElem)
{
        uniform_int_distribution<int> distribution(0, liczbaElem);
    mt19937 engine;

    for(int i = 0; i < liczbaElem; i++)
    {
        tab[i] = -1;
    }

    for(int i = 0; i < liczbaElem; i++)
    {
        int liczba = distribution(engine);

        while(tab[liczba] != -1)
        {
            liczba = distribution(engine);
        }
        tab[liczba] = i;
    }

}


void GenerujDane::dajDane(int tab[], int liczbaElem, int tab1[], int liczElem1)
{
    uniform_int_distribution<int> distribution(0, 4000000);
    mt19937 engine;
    for(int i = 0; i < liczbaElem; i++)
    {
        int liczba = distribution(engine);

        while(jestWTablicy(tab, i-1, liczba) || jestWTablicy(tab1, liczElem1, liczba))
        {
            liczba = distribution(engine);
        }
        tab[i] = liczba;
    }

}

bool GenerujDane::jestWTablicy(int tab[], int licznik, int value)
{
    for(int i = 0; i < licznik; i++)
    {
        if(tab[i] == value)
            return true;
    }
    return false;
}

