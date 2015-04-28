#include <iostream>
#include "Algorytm.hpp"
#include <iostream>

using namespace std;
Algorytm::~Algorytm()
{

}

void Algorytm::dodajElementy(int tab[],int liczbaElem)
{

}

Algorytm::Node* Algorytm::szukajEle(int dana)
{
    return NULL;
}

void Algorytm::usunEle(int element)
{
    return;
}

void Algorytm::usunElementy(int tab[], int liczbaEle)
{

}

void Algorytm::dodajEle(int key)
{

}

void Algorytm::wyswietlPosortowane()
{

}

void Algorytm::usunWszystko()
{

}

Algorytm::Node* Algorytm::nowyNode(int key)
{
    Node* node = new Node();
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

int Algorytm::wysokoscDrzewa()
{
    int wysokosc = 1;
    int wys1 = 0;
    int wys2 = 0;
    Node* p = root;
    if (p == NULL)
    {
        return 0;
    }
    if(p!=NULL)
    {
        wys1 = rekuDrzewo(p->left, wysokosc);
        wys2 = rekuDrzewo(p->right, wysokosc);
    }
    return wys1>wys2?wys1:wys2;
}

int Algorytm::rekuDrzewo(Node* p,int wysokosc)
{
    int wys1 = 0;
    int wys2 = 0;

    if(p == NULL)
    {
        return wysokosc;
    }
    if(p!=NULL)
    {
        wysokosc += 1;
        wys1 = rekuDrzewo(p->left,wysokosc);
        wys2 = rekuDrzewo(p->right,wysokosc);
    }
    return wys1>wys2?wys1:wys2;
}

int Algorytm::policzElementy()
{
    int liczbaElementow = 0;
    liczbaElementow = policzDrzewo(root, liczbaElementow);
    return liczbaElementow;
}

int Algorytm::policzDrzewo(Node* p, int liczbaElementow)
{
    if(p!=NULL)
    {
        liczbaElementow = policzDrzewo(p->left, liczbaElementow);
        liczbaElementow++;
        liczbaElementow = policzDrzewo(p->right, liczbaElementow);
    }
    return liczbaElementow;
}

int Algorytm::dajTablice(int tab[])
{
    int liczbaElementow = 0;
    liczbaElementow = wstawDoTab(root, liczbaElementow, tab);
    return liczbaElementow;
}

int Algorytm::wstawDoTab(Node* p, int liczbaElementow, int tab[])
{
    if(p!=NULL)
    {
        liczbaElementow = wstawDoTab(p->left, liczbaElementow, tab);
        tab[liczbaElementow] = p->key;
        liczbaElementow++;
        liczbaElementow = wstawDoTab(p->right, liczbaElementow, tab);
    }
    return liczbaElementow;
}

string Algorytm::dajNazwaAlgorytmu()
{
    return this->NazwaAlgorytmu;
}

int Algorytm::dajLiczbaInitEle()
{
    return this->LiczbaInitEle;
}
