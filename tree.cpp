#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct leaf
{
    int data;
    leaf *left;
    leaf *right;
    leaf() : data(0), left(NULL), right(NULL){};
};
class Tree
{
    leaf *root;

public:
    Tree() : root(NULL){};

    bool isEmpty()
    {
        if (root == NULL)
        {
            cout << "Tree is Empty!" << endl;
            return true;
        }
        return false;
    }
    int treeHeight() { return treeHeight(root); }
    int treeHeight(leaf *trav)
    {
        if (trav == NULL)
        {
            return 0;
        }
        else
        {
            int leftHeight = treeHeight(trav->left);
            int rightHeight = treeHeight(trav->right);
            return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
        }
    }

    leaf *createLeaf(int key)
    {
        leaf *newLeaf = new leaf();
        newLeaf->data = key;
        newLeaf->left = newLeaf->right = NULL;
        return newLeaf;
    }
    void insert(int key) { insert(root, key); }
    void insert(leaf *n, int key)
    {

        if (root == NULL)
        {
            root = createLeaf(key);
        }
        else if (key < n->data)
        {
            if (n->left == NULL)
            {
                n->left = createLeaf(key);
            }
            insert(n->left, key);
        }
        else if (key > n->data)
        {
            if (n->right == NULL)
            {
                n->right = createLeaf(key);
            }
            insert(n->right, key);
        }
    }
    void search(int key) { search(root, key); }
    void search(leaf *trav, int key)
    {
        if (trav == NULL)
        {
            cout << "Key not found!" << endl;
            return;
        }
        else if (trav->data == key)
        {
            cout << "Key found!" << endl;
            return;
        }
        else if (key < trav->data)
        {
            search(trav->left, key);
        }
        else if (key > trav->data)
        {
            search(trav->right, key);
        }
    }
    leaf *findMin(leaf *trav)
    {
        if (trav == NULL)
        {
            return NULL;
        }
        else if (trav->left == NULL)
        {
            return trav;
        }
        else
        {
            return findMin(trav->left);
        }
    }

    void deleteLeaf(int key) { deleteLeaf(root, key); }
    void deleteLeaf(leaf *trav, int key)
    {
        if (trav == NULL)
        {
            cout << "Key not found!" << endl;
            return;
        }
        else if (key < trav->data)
        {
            deleteLeaf(trav->left, key);
        }
        else if (key > trav->data)
        {
            deleteLeaf(trav->right, key);
        }
        else
        {
            if (trav->left == NULL && trav->right == NULL)
            {
                delete trav;
                trav = NULL;
            }
            else if (trav->left == NULL)
            {
                leaf *temp = trav;
                trav = trav->right;
                delete temp;
            }
            else if (trav->right == NULL)
            {
                leaf *temp = trav;
                trav = trav->left;
                delete temp;
            }
            else
            {
                leaf *temp = findMin(trav->right);
                trav->data = temp->data;
                deleteLeaf(trav->right, temp->data);
            }
        }
    }

    void print_tree() { print_tree(root, 0); }
    void print_tree(leaf *node, int level)
    {
        if (node == nullptr)
        {
            return;
        }
        print_tree(node->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            for (int j = 0; j <= i; j++)
                cout << "  "; // print the spaces
            if (i != level - 1)
                cout << "/"; // if not last level print /
        }
        cout << "---" << node->data << endl;
        for (int i = 0; i < level; i++)
        {
            for (int j = 0; j <= i; j++)
                cout << "  "; // print the spaces
            if (i != level - 1)
                cout << "\\"; // if not last level print \
    }
            cout << endl;
            print_tree(node->left, level + 1);
        }
    }

    void displayTree() { displayTree(root, 0); }
    void displayTree(leaf *trav, int space)
    {
        if (trav == NULL)
        {
            return;
        }
        space += 10;
        displayTree(trav->right, space);
        cout << endl;
        cout << setw(space) << " ";
        cout << trav->data << endl;
        displayTree(trav->left, space);
    }

    void displayInOrder() { displayInOrder(root); }
    void displayInOrder(leaf *trav)
    {
        if (trav != NULL)
        {
            displayInOrder(trav->left);
            cout << trav->data << " ";
            displayInOrder(trav->right);
        }
    }
    void displayPreOrder() { displayPreOrder(root); }
    void displayPreOrder(leaf *trav)
    {
        if (trav != NULL)
        {
            cout << trav->data << " ";
            displayInOrder(trav->left);
            displayInOrder(trav->right);
        }
    }
    void displayPostOrder() { displayPostOrder(root); }
    void displayPostOrder(leaf *trav)
    {
        if (trav != NULL)
        {
            displayInOrder(trav->left);
            displayInOrder(trav->right);
            cout << trav->data << " ";
        }
    }

    void build2DTree() { build2DTree(root, 0, 0); }
    void build2DTree(leaf *trav, int space, int height)
    {
        if (trav == NULL)
        {
            return;
        }
        space += 10;
        build2DTree(trav->right, space + 5, height + 1);
        cout << endl;
        for (int i = 10; i < space; i++)
        {
            cout << " ";
        }
        cout << trav->data << endl;
        build2DTree(trav->left, space - 5, height + 1);
    }
};
int main()
{
    Tree t;

    t.insert(8);
    t.insert(12);
    t.insert(4);
    t.insert(2);
    t.insert(5);
    t.insert(15);
    // t.insert(4);
    // t.insert(9);
    // t.insert(3);
    // t.insert(7);

    cout << "Pre Order : ";
    t.displayPreOrder();
    cout << endl;
    cout << "In Order : ";
    t.displayInOrder();
    cout << endl;
    cout << "Post Order : ";
    t.displayPostOrder();
    cout << endl;
    t.search(5);
    cout << "Height of the tree : " << t.treeHeight() << endl;
    cout << "Horizonal Tree : " << endl;
    t.displayTree();
  
    system("pause");
    return 0;
}