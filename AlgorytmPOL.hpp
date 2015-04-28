#ifndef ALGORYTMPOL_HPP_INCLUDED
#define ALGORYTMPOL_HPP_INCLUDED

#include "Algorytm.hpp"

class AlgorytmPOL: public Algorytm
{
public:
    AlgorytmPOL();
    ~AlgorytmPOL();
    void dodajEle(int key);
    Node* szukajEle(int key);
    void usunEle(int key);
    void dodajElementy(int tab[],int liczbaElem);
    void usunElementy(int tab[], int liczbaEle);
    void wyswietlPosortowane();
    void usunWszystko();

private:
    Node* findrightnode(Node* p);
    Node* findparentforNode(int p_key);
    void inorder(Node* p);
    void postorder(Node* p);
    void rownowazPOL();
    void drzewoPOL(int tab[], int mini, int maxi);
    int srodek(int mini, int maxi);
};



#endif // ALGORYTMPOL_HPP_INCLUDED
