#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "AlgorytmPOL.hpp"
#include "Algorytm.hpp"

using namespace std;

AlgorytmPOL::AlgorytmPOL()
{
    this->NazwaAlgorytmu = "POL";
    this->LiczbaInitEle = 0;
    root = NULL;
}

AlgorytmPOL::~AlgorytmPOL()
{
    usunWszystko();
}

void AlgorytmPOL::dodajElementy(int tab[],int liczbaElem)
{
    if(this->LiczbaInitEle == 0)
    {
        this->LiczbaInitEle = liczbaElem;
    }

    for(int i = 0; i < liczbaElem; i++)
    {
        dodajEle(tab[i]);
    }
    rownowazPOL();
}

void AlgorytmPOL::dodajEle(int p_key)
{
    Node *nodeOtrzym = nowyNode(p_key);
    // pierwszy element
    if ((root)==NULL)
    {
        root=nodeOtrzym;
    }
    else
    {
        Node *nodePrzegl = root;

        while(true)
        {
            if (nodeOtrzym->key < nodePrzegl->key)
            {
                if (nodePrzegl->left == NULL)
                {
                    nodePrzegl->left = nodeOtrzym;
                    break;
                }
                else
                {
                    nodePrzegl = nodePrzegl->left;
                }
            }
            else if (nodeOtrzym->key > nodePrzegl->key)
            {
                if (nodePrzegl->right == NULL)
                {
                    nodePrzegl->right = nodeOtrzym;
                    break;
                }
                else
                {
                    nodePrzegl = nodePrzegl->right;
                }
            }
            else
            {
                printf("AlgorytmPOL::dodajEle Istnieje już taki element.\n");
                return;
            }
        }
    }

}


Algorytm::Node* AlgorytmPOL::szukajEle(int p_key)
{
    if ((root)==NULL)
    {
        printf("AlgorytmPOL::szukajEle Drzewo POL jest puste.\n");
        return NULL;
    }
    else
    {
        Node *nodePrzegl = root;

        while(true)
        {
            if (p_key < nodePrzegl->key)
            {
                if (nodePrzegl->left == NULL)
                {
                    printf("AlgorytmPOL::szukajEle Nie ma takiego elementu.\n");
                    return NULL;
                }
                else
                {
                    nodePrzegl = nodePrzegl->left;
                }
            }
            else if (p_key > nodePrzegl->key)
            {
                if (nodePrzegl->right == NULL)
                {
                    printf("AlgorytmPOL::szukajEle Nie ma takiego elementu.\n");
                    return NULL;
                }
                else
                {
                    nodePrzegl = nodePrzegl->right;
                }
            }
            else
            {
                return nodePrzegl;
            }
        }
    }
}


void AlgorytmPOL::usunEle(int val)
{
    Node* p = szukajEle(val);
    if(p!=NULL)
    {
        //if both of child of node are null(leaf node)
        if(p->left==NULL&&p->right==NULL)
        {
            if(p!=root)
            {
                Node* parent= findparentforNode(val);
                if(val < parent->key)
                    parent->left=NULL;
                else
                    parent->right=NULL;
            }
            else root=NULL;
            delete (p);
        }
        //if only left child is not null
        else if(p->left!=NULL&&p->right==NULL)
        {
            if(p!=root)
            {
                Node* parent=findparentforNode(val);
                if(val < parent->key)
                    parent->left = p->left;
                else
                    parent->right=p->left;
            }
            else root=NULL;
            delete (p);
        }
        //if only right child is not null
        else if(p->left==NULL&&p->right!=NULL)
        {
            if(p!=root)
            {
                Node* parent=findparentforNode(val);
                if(val<parent->key) parent->left=p->right;
                else parent->right=p->right;
            }
            else root=NULL;
            delete (p);
        }
        //if both child are not null
        else
        {
            Node* righty=findrightnode(p->left);
            Node* parent=findparentforNode(righty->key);
            p->key=righty->key;
            if(parent!=p) parent->right=righty->left;
            else p->left=righty->left;
        }
    }
}



//find parent of a node with value key
Algorytm::Node* AlgorytmPOL::findparentforNode(int p_key)
{
    Node* p = root;
    Node* q = NULL;
    while((p != NULL) && (p->key != p_key))
    {
        q = p;
        if(p_key < p->key)
        {
            p = p->left;
        }
        else
        {
            p=p->right;
        }

    }
    return q;
}
//finds the most right of a node p(means immediate succesor of p in inorder representation)
Algorytm::Node* AlgorytmPOL::findrightnode(Node* p)
{
    Node* righty=p;
    while(righty->right!=NULL)
        righty=righty->right;
    return righty;
}


void AlgorytmPOL::usunElementy(int tab[], int liczbaEle)
{
    for (int i=0; i<liczbaEle; i++)
    {
        usunEle(tab[i]);
    }

}


void AlgorytmPOL::wyswietlPosortowane()
{
    Node* p = root;
    if(p == NULL)
    {
        cout << "Drzewo jest puste" << endl;
    }
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->key<<endl;
        inorder(p->right);
    }
}

void AlgorytmPOL::inorder(Node* p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->key<<endl;
        inorder(p->right);
    }
}


//postorder
void AlgorytmPOL::usunWszystko()
{
    Node* p = root;
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        delete(p);
    }
    root = NULL;
    LiczbaInitEle = 0;

}

void AlgorytmPOL::postorder(Node* p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        delete(p);
    }
}


void AlgorytmPOL::rownowazPOL()
{
    int liczbaElem2 = 0;

    liczbaElem2 = policzElementy();
    int *tab1 = new int[liczbaElem2];
    dajTablice(tab1);
    int liczbaElementow = this->LiczbaInitEle;
    usunWszystko();
    this->LiczbaInitEle = liczbaElementow;
    drzewoPOL(tab1, 0, liczbaElem2-1);
    delete(tab1);

}

void AlgorytmPOL::drzewoPOL(int tab[], int mini, int maxi)
{
    int sr = 0;
    sr = srodek(mini, maxi);
    if (mini>maxi)
    {
        return;
    }
    dodajEle(tab[sr]);
    drzewoPOL(tab, mini, sr-1);
    drzewoPOL(tab, sr+1, maxi);

}

//WYBIERANIE SRODKA
int AlgorytmPOL::srodek(int mini, int maxi)
{
    int srodek;
    srodek=(maxi-mini)/2 + mini;
    return srodek;
}
