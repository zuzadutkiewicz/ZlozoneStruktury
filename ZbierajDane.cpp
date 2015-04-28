#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ZbierajDane.hpp"

using namespace std;

ZbierajDane::ZbierajDane()
{
    this->first = NULL;
    this->last = NULL;
}

void ZbierajDane::dodajDoListy(string typOperacji, string typStruktury, int wysokoscDrzewa, int liczbaPocz, int liczbaZmien, int czas)
{
    Element* elem = new Element;
    sprintf(elem->dana,"%s\t%s\t%d\t%d\t%d\t%d", typOperacji.c_str(), typStruktury.c_str(), wysokoscDrzewa, liczbaPocz, liczbaZmien, czas);
    if(this->first == NULL)
    {
        this->first = elem;
        this->last = elem;
        elem->next = NULL;
    }
    else
    {
        this->last->next = elem;
        this->last = elem;
        elem->next = NULL;
    }
}


void ZbierajDane::wyswietl()
{
    Element* aktualny = this->first;
    if (aktualny == NULL)
    {
        cout<<"Brak elementow do wyswietlenia";
    }
    fstream plik;
    plik.open("plik.csv", ios::out);
    while(aktualny != NULL)
    {
        printf("%s\t\n",aktualny->dana);
        plik <<aktualny->dana << endl;
        aktualny = aktualny->next;
    }
    plik.close();
}

void ZbierajDane::czysc()
{
    Element* aktualny = this->first;
    while (aktualny != NULL)
    {
        Element* nastelem = aktualny->next;
        free(aktualny);
        aktualny = nastelem;
    }
    this->first = NULL;
    this->last = NULL;
}
