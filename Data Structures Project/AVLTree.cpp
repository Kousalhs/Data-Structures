#include "AVLTree.h"

AVLTree::AVLTree()
{
    root = nullptr;
}

AVLTree::~AVLTree()
{
    root = deleteTree(root); // διαγράφουμε το δέντρο
}

void AVLTree::insertLeaf(string data)
{
    root = insertLeaf(data, root); // προσθέτουμε τον κόμβο στο δέντρο
}

void AVLTree::removeLeaf(string data)
{
    root = removeLeaf(data, root);
}

AVLTree::node * AVLTree::insertLeaf(string data, node *tree)
{
    if(tree == NULL) // άμα είναι άδειος τον δημιουργούμε
    {
        tree = new node;
        tree->data = data;
        tree->height = 0;
        tree->left = tree->right = NULL;
    }
    else if(data < tree->data) // μικρότερο
    {
        cout<<"mpike left to: "<<data<<" apo to: "<<tree->data<<endl;
        tree->left = insertLeaf(data, tree->left); // μπαίνει αριστερά
        if(height(tree->left) - height(tree->right) == 2) // ελέγχουμε το ύψος απο τους κόμβους του
        {
            cout<<"left side > right side "<<tree->data<<endl;
            if(data < tree->left->data) // αναλύουμε τις περιπτώσεις
                tree = RightRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }
    else if(data > tree->data) // μεγαλύτερο
    {
        cout<<"mpike right to: "<<data<<" apo to: "<<tree->data<<endl;
        tree->right = insertLeaf(data, tree->right); // μπαίνει δεξιά
        if(height(tree->right) - height(tree->left) == 2) // ελέγχουμε το ύψος απο τους κόμβους του
        {
            cout<<"right side > left side"<<endl;
            if(data > tree->right->data) // αναλύουμε τις περιπτώσεις
                tree = LeftRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }
    else // αν υπάρχει ήδη αυξάνουμε το πλήθος του
        tree->counter++;

    tree->height = max(height(tree->left), height(tree->right))+1; // καταχωρούμε το ύψος των κομβών του
    return tree;
}

AVLTree::node *AVLTree::removeLeaf(string dat, node *tree) {
    if (tree == NULL) // δεν βρέθηκε
        return NULL;
    else if (dat < tree->data) // ο κόμβος βρίσκεται αριστερά
        tree->left = removeLeaf(dat, tree->left);
    else if (dat > tree->data) // ο κόμβος βρίσκεται δεξιά
        tree->right = removeLeaf(dat, tree->right);
    else // βρήκαμε τον κόμβο
    {
        if (tree->counter > 1) // υπάρχει περισσότερες από 1 φορές άρα μειώνουμε counter
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
    if (tree == NULL)
        return NULL;

    tree->height = max(height(tree->left), height(tree->right)) + 1;

    // If node is unbalanced
    // If left node is deleted, right case
    if (height(tree->left) - height(tree->right) == 2) {
        // right right case
        if (tree->left->left != NULL)
            return RightRotation(tree);
            // right left case
        else
            return leftRightRotation(tree);
    }
        // If right node is deleted, left case
    else if (height(tree->right) - height(tree->left) == 2) {
        // left left case
        if (tree->right->right != NULL) {
            return LeftRotation(tree);
        }
            // left right case
        else
            return rightLeftRotation(tree);
    }
    return tree;
}

AVLTree::node* AVLTree::findMin(node *tree)
{
    if(tree == NULL)
        return NULL;
    else if(tree->left == NULL)
        return tree;
    else
        return findMin(tree->left);
}

bool AVLTree::search(node *n, string data)
{
    if(n == NULL) // δεν βρέθηκε
        return false;
    else if(n->data < data) // είναι μικρότερο άρα ψάχνουμε το δεξί υποδέντρο
        return search(n->right, data);
    else if(n->data > data) // είναι μεγαλύτερο άρα ψάχνουμε το αριστερό υποδέντρο
        return search(n->left, data);
    else // βρέθηκε
        return true;
}

AVLTree::node* AVLTree::deleteTree(node *tree) // private συνάρτηση που αφαιρεί το κόμβο από την μνήμη
{
    if(tree == NULL)
        return NULL;

    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;

    return NULL;
}

AVLTree::node* AVLTree::getNode() // getter
{
    return root;
}

int AVLTree::height(node *tree) // επιστρέφει το ύψος του κόμβου αν υπάρχει το δέντρο
{
    if(tree == NULL)
        return -1;
    return tree->height;
}

AVLTree::node* AVLTree::RightRotation(node* &tree) // δεξιά περιστροφή
{
    cout<<"right rotation"<<endl;
    node* a = tree->left;
    tree->left = a->right;
    a->right = tree;
    tree->height = max(height(tree->left), height(tree->right))+1;
    a->height = max(height(a->left), tree->height)+1;
    return a;
}

AVLTree::node* AVLTree::LeftRotation(node* &tree) // αριστερή περιστροφή
{
    cout<<"left rotation"<<endl;
    node* a = tree->right;
    tree->right = a->left;
    a ->left = tree;
    tree->height = max(height(tree->left), height(tree->right))+1;
    a ->height = max(height(tree->right), tree->height)+1 ;
    return a;
}

AVLTree::node* AVLTree::rightLeftRotation(node* &tree) // πρώτα δεξιά περιστροφή και μετά δεξιά
{
    cout<<"right left rotate"<<endl;
    tree->right = RightRotation(tree->right);
    return LeftRotation(tree);
}

AVLTree::node* AVLTree::leftRightRotation(node* &tree) // πρώτα αριστερή περιστροφή και μετά δεξιά
{
    cout<<"left right rotate"<<endl;
    tree->left = LeftRotation(tree->left);
    return RightRotation(tree);
}

void AVLTree::inorder(node* root) // inorder
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " " << root->counter << " ";
    inorder(root->right);
}

void AVLTree::preorder(node *root) // preorder
{
    if(root == NULL)
        return;
    cout << root->data << " " << root->counter << " ";
    preorder(root->left);
    preorder(root->right);
}

void AVLTree::postorder(node* root) // postorder
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " " << root->counter << " ";
}