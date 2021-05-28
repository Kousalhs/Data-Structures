#ifndef DATA_STRUCTURES_PROJECT_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_PROJECT_BINARYSEARCHTREE_H

#include <iostream>
#include <string.h>
using namespace std;

class BinarySearchTree
{

private:
    struct node
    {
        int counter = 1;
        string data;
        node* left;
        node* right;
    };
    node* root;

    node* insertLeaf(string, node *); // βάζει έναν κόμβο στο δέντρο
    node* removeLeaf(string, node*); // αφαιρεί έναν κόμβο από το δέντρο
    node* deleteTree(node *); // καταστρέφει το δέντρο
    node* findMin(node*); // βρίσκει την ελάχιστη τιμη

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

    node* getNode(); // getter
    void inorder(node *); // inorder
    void preorder(node *); // preoder
    void postorder(node *); // postorder
    void insertLeaf(string); // καλεί την insertLeaf που είναι private
    void removeLeaf(string); // καλεί την removeLeaf που είναι private
    bool search(node *, string); // επιστρέφει true αν υπάρχει αλλιώς false

};

#endif //DATA_STRUCTURES_PROJECT_BINARYSEARCHTREE_H
