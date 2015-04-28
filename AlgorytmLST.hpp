#ifndef ALGORYTMLST_HPP_INCLUDED
#define ALGORYTMLST_HPP_INCLUDED
#include "Algorytm.hpp"

class AlgorytmLST: public Algorytm
{
public:
    AlgorytmLST();
    ~AlgorytmLST();
    void dodajEle(int key);
    void dodajElementy(int tab[],int liczbaElem);
    Node* szukajEle(int dana);
    void wyswietlPosortowane();
    void usunEle(int element);
    void usunElementy(int tab[], int liczbaEle);
    void usunWszystko();

private:
    void postorder(Node* p);
};

#endif // ALGORYTMLST_HPP_INCLUDED
