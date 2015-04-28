#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "AlgorytmBST.hpp"
#include "Algorytm.hpp"

using namespace std;

AlgorytmBST::AlgorytmBST()
{
    this->NazwaAlgorytmu = "BST";
    this->LiczbaInitEle = 0;
    root = NULL;
}

AlgorytmBST::~AlgorytmBST()
{
    usunWszystko();
}

void AlgorytmBST::dodajElementy(int tab[],int liczbaElem)
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

void AlgorytmBST::dodajEle(int p_key)
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
                printf("AlgorytmBST::dodajEle Istnieje już taki element.\n");
                return;
            }
        }
    }

}


Algorytm::Node* AlgorytmBST::szukajEle(int p_key)
{
    if ((root)==NULL)
    {
        printf("AlgorytmBST::szukajEle Drzewo BST jest puste.\n");
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
                    printf("AlgorytmBST::szukajEle Nie ma takiego elementu.\n");
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
                    printf("AlgorytmBST::szukajEle Nie ma takiego elementu.\n");
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


void AlgorytmBST::usunEle(int val)
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
                if(val < parent->key) parent->left=NULL;
                else parent->right=NULL;
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
Algorytm::Node* AlgorytmBST::findparentforNode(int p_key)
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
Algorytm::Node* AlgorytmBST::findrightnode(Node* p)
{
    Node* righty=p;
    while(righty->right!=NULL)
        righty=righty->right;
    return righty;
}


void AlgorytmBST::usunElementy(int tab[], int liczbaEle)
{
    for (int i=0; i<liczbaEle; i++)
    {
        usunEle(tab[i]);
    }

}


void AlgorytmBST::wyswietlPosortowane()
{
    Node* p = root;
    if(p == NULL)
    {
        cout << "Drzewo jest puste" << endl;
    }
    if(p!=NULL)
    {
        inorder(p->left);
        cout << p->key << endl;
        inorder(p->right);
    }
}

void AlgorytmBST::inorder(Node* p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout << p->key << endl;
        inorder(p->right);
    }
}


//postorder
void AlgorytmBST::usunWszystko()
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

void AlgorytmBST::postorder(Node* p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        delete(p);
    }
}

