#ifndef ALGORYTMBST_HPP_INCLUDED
#define ALGORYTMBST_HPP_INCLUDED
#include "Algorytm.hpp"



class AlgorytmBST: public Algorytm
{
public:
    AlgorytmBST();
    ~AlgorytmBST();
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
};

#endif // ALGORYTMBST_HPP_INCLUDED
