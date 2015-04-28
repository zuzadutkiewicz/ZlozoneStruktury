#ifndef ALGROTYMBST_HPP_INCLUDED
#define ALGROTYMBST_HPP_INCLUDED
#include "ZbierajDane.hpp"
#include "Algorytm.hpp"


class AlgorytmBST: public Algorytm
{
public:
    AlgorytmBST(ZbierajDane *zbierajDane);
    void dodajEle(int key);
    bool szukajEle(int key);
    bool usunEle(int key);
    void dodajElementy(int tab[],int liczbaElem);
    void usunElementy(int tab[], int liczbaEle);
};


#endif // ALGROTYMBST_HPP_INCLUDED
