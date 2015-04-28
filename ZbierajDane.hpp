#ifndef ZBIERAJDANE_HPP_INCLUDED
#define ZBIERAJDANE_HPP_INCLUDED

#include <string>
#include <fstream>

using namespace std;

class ZbierajDane
{
public:
    typedef struct structElement
    {
        char dana[300];
        structElement *next;
    } Element;

    Element *first;
    Element *last;
    ZbierajDane();
    void dodajDoListy(string typOperacji,
                      string typStruktury,
                      int wysokoscDrzewa,
                      int liczbaPocz,
                      int liczbaZmien,
                      int czas);
    void zapisz(string file);
    void czysc();
    void wyswietl();
};



#endif // ZBIERAJDANE_HPP_INCLUDED
