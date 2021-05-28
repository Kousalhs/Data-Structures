#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}
BinarySearchTree::~BinarySearchTree()
{
    root = deleteTree(root); // διαγράφουμε το δέντρο
}

void BinarySearchTree::insertLeaf(string data)
{
    root = insertLeaf(data, root); // προσθέτουμε τον κόμβο στο δέντρο
}

void BinarySearchTree::removeLeaf(string data)
{
    root = removeLeaf(data, root); // αφαιρεί τον κόμβο από το δέντρο
}

BinarySearchTree::node* BinarySearchTree::insertLeaf(string dat, node* tree) // private συνάρτηση που βάζει ένα κόμβο στο δυαδικό δέντρο αναζήτησης
{
    if(tree == NULL) // άμα είναι άδειος τον δημιουργούμε
    {
        tree = new node;
        tree->data = dat;
        tree->left = tree->right = NULL;
    }
    else if(dat < tree->data) // μικρότερο άρα μπαίνει αριστερά
    {
        cout<<"mpike left to: "<<dat<<" apo to: "<<tree->data<<endl;
        tree->left = insertLeaf(dat, tree->left);
    }
    else if(dat > tree->data) // μεγαλύτερο άρα μπαίνει δεξιά
    {
        cout<<"mpike right to: "<<dat<<" apo to: "<<tree->data<<endl;
        tree->right = insertLeaf(dat, tree->right);
    }
    else // αν υπάρχει ήδη αυξάνουμε το πλήθος του
        tree->counter++;
    return tree;
}

BinarySearchTree::node *BinarySearchTree::removeLeaf(string dat, node *tree) // private συνάρτηση που αφαιρεί τον κόμβο απο το δυαδικό δέντρο αναζήτησης
{
    if (tree == NULL) // δεν βρέθηκε
        return NULL;
    else if (dat < tree->data) // ο κόμβος βρίσκεται αριστερά
        tree->left = removeLeaf(dat, tree->left);
    else if (dat > tree->data) // ο κόμβος βρίσκεται δεξιά
        tree->right = removeLeaf(dat, tree->right);
    else // βρήκαμε τον κόμβο
    {
        if (tree->counter > 1) // άμα υπάρχει παραπάνω από μια φορά μειώνουμε τον counter
            tree->counter--;
        else { // υπάρχει 1 φορά άρα σβήνουμε τον κόμβο
            if (tree->left == NULL && tree->right == NULL) // δεν έχει κανένα παιδί
            {
                delete tree;
                tree = NULL;
            } else if (tree->left == NULL) // έχει ένα παιδί και είναι στα αριστερά του
            {
                node *temp = tree;
                tree = tree->right;
                delete temp;
            } else if (tree->right == NULL) // έχει ένα παιδί και είναι στα δεξιά του
            {
                node *temp = tree;
                tree = tree->left;
                delete temp;
                cout << tree->data << endl;
            } else // έχει δύο παιδιά
            {
                node *temp = findMin(tree->right);
                tree->data = temp->data;
                tree->right = removeLeaf(tree->data, tree->right);
            }
        }
    }
    return tree;
}

BinarySearchTree::node* BinarySearchTree::findMin(node *tree)
{
    if(tree == NULL)
        return NULL;
    else if(tree->left == NULL)
        return tree;
    else
        return findMin(tree->left);
}

bool BinarySearchTree::search(node *n, string data)
{
    if(n == NULL) // δεν βρέθηκε
        return false;
    else if(n->data < data) // είναι μικρότερο άρα ψάχνουμε στο δεξί υποδέντρο
        return search(n->right, data);
    else if(n->data > data) // είναι μεγαλύτερο άρα ψάχνουμε στο αριστερό υποδέντρο
        return search(n->left, data);
    else // βρέθηκε
        return true;
}

BinarySearchTree::node* BinarySearchTree::deleteTree(node* tree) // private συνάρτηση που αφαιρεί το δέντρο από την μνήμη
{
    if(tree == NULL)
        return NULL;

    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;

    return NULL;
}

BinarySearchTree::node* BinarySearchTree::getNode() // getter
{
    return root;
}

void BinarySearchTree::inorder(node *n) // inorder
{
    if(n == NULL)
        return;
    inorder(n->left);
    cout << n->data << " " << n->counter << " ";
    inorder(n->right);
}

void BinarySearchTree::preorder(node *n) // preorder
{

    if(n == NULL)
        return;
    cout << n->data << " " << n->counter << " ";
    preorder(n->left);
    preorder(n->right);

}

void BinarySearchTree::postorder(node *n) // postorder
{

    if(n == NULL)
        return;
    postorder(n->left);
    postorder(n->right);
    cout << n->data << " " << n->counter << " ";
}
