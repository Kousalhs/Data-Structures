#ifndef DATA_STRUCTURES_PROJECT_AVLTREE_H
#define DATA_STRUCTURES_PROJECT_AVLTREE_H


#include <iostream>
#include <cstring>
using namespace std;

class AVLTree {

private:
    struct node{
        string data;
        node* left;
        node* right;
        int height;
        int counter = 1;
    };
    node* root;

    node* insertLeaf(string, node *); // βάζει έναν κόμβο στο δέντρο
    node* removeLeaf(string, node*); // βγάζει τον κόμβο από το δέντρο
    node* deleteTree(node *); // καταστρέφει το δέντρο
    int height(node*); // μετράει το ύψος του κόμβου
    node* RightRotation(node* &); // κάνει περιστροφή προς τα δεξιά
    node* LeftRotation(node* &);  // κάνει περιστροφή προς τα αριστερά
    node* rightLeftRotation(node* &); // κάνει περιστροφή προς τα δεξιά και μετά αριστερά
    node* leftRightRotation(node* &); // κάνει περιστροφή προς τα αριστερά και μετά δεξιά
    node* findMin(node*);

public:
    AVLTree();
    ~AVLTree();

    node* getNode(); // getter
    void inorder(node *); // inorder
    void preorder(node *); // preorder
    void postorder(node *); // postorder
    void insertLeaf(string); // καλεί την insertLeaf που είναι private
    void removeLeaf(string); // καλεί την removeLeaf που είναι private
    bool search(node *, string); // επιστρέφει true αν υπάρχει αλλιώς false

};

#endif //DATA_STRUCTURES_PROJECT_AVLTREE_H
