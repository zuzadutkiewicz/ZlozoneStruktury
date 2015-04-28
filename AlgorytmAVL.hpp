#ifndef ALGORTYMAVL_HPP_INCLUDED
#define ALGORTYMAVL_HPP_INCLUDED
#include "ZbierajDane.hpp"
#include "Algorytm.hpp"


class AlgorytmAVL: public Algorytm
{
public:
    AlgorytmAVL();
    ~AlgorytmAVL();
    void dodajEle(int key);
    Node* szukajEle(int key);
    void usunEle(int key);
    void dodajElementy(int tab[],int liczbaElem);
    void usunElementy(int tab[], int liczbaEle);
    void wyswietlPosortowane();
    void usunWszystko();

private:
    int height(Node *N);
    int max(int a, int b);
    Node* rightRotate(Node *y);
    Node* leftRotate(Node *x);
    int getBalance(Node *N);
    Node* deleteNode(Node* root, int key);
    Node* insert(Node* node, int key);
    Node* minValueNode(Node* node);
    void inorder(Node* p);
    void postorder(Node* p);
};

#endif // ALGORTYMAVL_HPP_INCLUDED
