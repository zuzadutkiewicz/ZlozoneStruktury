#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "AlgorytmLST.hpp"
#include "Algorytm.hpp"

AlgorytmLST::AlgorytmLST()
{
    this->NazwaAlgorytmu = "LST";
    this->LiczbaInitEle = 0;
    root = NULL;
}

AlgorytmLST::~AlgorytmLST()
{
    usunWszystko();
}

void AlgorytmLST::dodajElementy(int tab[],int liczbaElem)
{
    if(this->LiczbaInitEle == 0)
    {
        this->LiczbaInitEle = liczbaElem;
    }
    for(int i = 0; i < liczbaElem; i++)
    {
        dodajEle(tab[i]);
    }
}

void AlgorytmLST::wyswietlPosortowane()
{
    Node *node = root;

    while(node != NULL)
    {
        printf("%d\n", node->key);
        node = node->left;
    }
    if(root == NULL)
    {
        printf("Brak elementow do wyswietlenia.\n");
    }
}

Algorytm::Node* AlgorytmLST::szukajEle(int p_key)
{
 if ((root)==NULL)
    {
        printf("AlgorytmLST::szukajEle Lista LST jest puste.\n");
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
                    printf("AlgorytmLST::szukajEle Nie ma takiego elementu.\n");
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
                    printf("AlgorytmLST::szukajEle Nie ma takiego elementu.\n");
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

void AlgorytmLST::usunEle(int p_key)
{
    Node *aktualny = root;
    Node *poprzedni = NULL;
    while(aktualny!= NULL)
    {
        if(aktualny->key == p_key)
        {
            if (poprzedni == NULL)
            {
                root = aktualny->left;
            }
            else
            {
                poprzedni->left= aktualny->left;
            }
            delete(aktualny);
            return;
        }
        poprzedni = aktualny;
        aktualny = aktualny->left;
    }
    printf("AlgorytmBST::usunEle Nie znaleziono elementu. \n");
   return;
}


void AlgorytmLST::usunElementy(int tab[], int liczbaEle)
{
    for (int i=0; i<liczbaEle; i++)
    {
        usunEle(tab[i]);
    }
}

void AlgorytmLST::dodajEle(int p_key)
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
        Node *nodePoprz = NULL;

        if( nodeOtrzym->key == nodePrzegl->key )
        {
            printf("Klucze rowne nie dodaje elementu\n");
            return;
        }
        while(nodePrzegl != NULL && nodeOtrzym->key > nodePrzegl->key)
        {
            nodePoprz = nodePrzegl;
            nodePrzegl = nodePrzegl->left;

            if(nodePrzegl != NULL && nodeOtrzym->key == nodePrzegl->key )
            {
                printf("Klucze rowne nie dodaje elementu\n");
                return;
            }

        }

        // wstawienie przed elementem - dana jest mniejsza na poczatku
        if(nodePoprz == NULL)
        {
            nodeOtrzym->left = root;
            root = nodeOtrzym;
        }
        // ostatni element - jest wiekszy od wszystkich znalezionych
        else if(nodePrzegl == NULL)
        {
            nodePoprz->left = nodeOtrzym;
        }
        // srodkowy element
        else
        {
            nodePoprz->left = nodeOtrzym;
            nodeOtrzym->left = nodePrzegl;
        }
    }
}

void AlgorytmLST::usunWszystko()
{
    Node* p = this->root;
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        delete(p);
    }
    this->root = NULL;
    this->LiczbaInitEle = 0;

}

void AlgorytmLST::postorder(Node* p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        delete(p);
    }
}

