#ifndef ALGORYTM_HPP_INCLUDED
#define ALGORYTM_HPP_INCLUDED

#include <string>

class Algorytm
{

public:

    struct Node
    {
        int key;
        Node *left;
        Node *right;
        int height;
    };
    Node *root;
    virtual ~Algorytm();
    virtual void dodajEle(int key);
    virtual Node* szukajEle(int key);
    virtual void usunEle(int key);
    virtual void dodajElementy(int tab[],int liczbaElem);
    virtual void usunElementy(int tab[], int liczbaEle);
    virtual void wyswietlPosortowane();
    virtual void usunWszystko();
    virtual int wysokoscDrzewa();
    virtual int policzElementy();
    virtual std::string dajNazwaAlgorytmu();
    virtual int dajLiczbaInitEle();
    virtual int dajTablice(int tab[]);


protected:
    std::string NazwaAlgorytmu;
    int LiczbaInitEle;
    virtual Node* nowyNode(int p_key);

private:
    int rekuDrzewo(Node* p,int wysokosc);
    int policzDrzewo(Node* p, int liczbaElementow);
    int wstawDoTab(Node* p, int liczbaElementow, int tab[]);

};



#endif // ALGORYTM_HPP_INCLUDED
