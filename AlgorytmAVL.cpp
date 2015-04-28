#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "AlgorytmAVL.hpp"
#include "Algorytm.hpp"


AlgorytmAVL::AlgorytmAVL()
{
    this->NazwaAlgorytmu = "AVL";
    this->LiczbaInitEle = 0;
    root = NULL;
}

AlgorytmAVL::~AlgorytmAVL()
{
    usunWszystko();
}

void AlgorytmAVL::dodajElementy(int tab[],int liczbaElem)
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


void AlgorytmAVL::dodajEle(int p_key)
{
    if(root == NULL)
    {
        root = nowyNode(p_key);
    }
    else
    {
        insert(root, p_key);
    }
}


Algorytm::Node* AlgorytmAVL::insert(Node* node, int key)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(nowyNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}


void AlgorytmAVL::usunElementy(int tab[], int liczbaEle)
{
    for (int i=0; i<liczbaEle; i++)
    {
        usunEle(tab[i]);
    }

}

void AlgorytmAVL::usunEle(int p_key)
{
    deleteNode(this->root, p_key);
}


Algorytm::Node* AlgorytmAVL::deleteNode(Node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(height(root->left), height(root->right)) + 1;

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Algorytm::Node* AlgorytmAVL::szukajEle(int p_key)
{
    if ((root)==NULL)
    {
        printf("AlgorytmAVL::szukajEle Drzewo AVL jest puste.\n");
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
                    printf("AlgorytmAVL::szukajEle Nie ma takiego elementu.\n");
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
                    printf("AlgorytmAVL::szukajEle Nie ma takiego elementu.\n");
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

void AlgorytmAVL::wyswietlPosortowane()
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

void AlgorytmAVL::inorder(Node* p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->key<<endl;
        inorder(p->right);
    }
}


void AlgorytmAVL::usunWszystko()
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

void AlgorytmAVL::postorder(Node* p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        delete(p);
    }
}


// A utility function to get height of the tree
int AlgorytmAVL::height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int AlgorytmAVL::max(int a, int b)
{
    return (a > b)? a : b;
}


// A utility function to right rotate subtree rooted with y
// See the diagram given above.
Algorytm::Node* AlgorytmAVL::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Algorytm::Node* AlgorytmAVL::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int AlgorytmAVL::getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
Algorytm::Node * AlgorytmAVL::minValueNode(Node* node)
{
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

