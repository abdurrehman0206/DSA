#include <iostream>
using namespace std;

struct leaf
{
    int data;
    leaf *left;
    leaf *right;
    leaf() : data(0), left(NULL), right(NULL){};
};

class TREE
{
    leaf *root;
    leaf *createLeaf(int key)
    {
        leaf *newLeaf = new leaf();
        newLeaf->data = key;
        return newLeaf;
    }

public:
    TREE() : root(NULL) {}
    bool isEmpty()
    {
        return root == NULL;
    }

    void insert(int key) { insert(root, key); }
    void insert(leaf *temp, int key)
    {
        if (isEmpty())
        {
            root = createLeaf(key);
            return;
        }
        if (key < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = createLeaf(key);
            }
            else
            {

                insert(temp->left, key);
            }
        }
        else if (key > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = createLeaf(key);
            }
            else
            {
                insert(temp->right, key);
            }
        }
    }
    void search(int key) { search(root, key); }
    void search(leaf *trav, int key)
    {
        if (!trav)
        {
            cout << "Key Not Found !" << endl;
            return;
        }
        if (trav->data == key)
        {
            cout << "Key Found !" << endl;
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
    leaf *deleteLeaf(int key)
    {
        root = deleteLeaf(root, key);
        return root;
    }
    leaf *deleteLeaf(leaf *node, int key)
    {
        if (node == NULL)
        {
            return NULL;
        }
        else if (key < node->data)
        {
            node->left = deleteLeaf(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = deleteLeaf(node->right, key);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                node = NULL;
            }
            else if (node->left == NULL)
            {
                leaf *temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == NULL)
            {
                leaf *temp = node;
                node = node->left;
                delete temp;
            }
            else
            {
                leaf *temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteLeaf(node->right, temp->data);
            }
        }
        return node;
    }
    leaf *findMin(leaf *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }
    void preOrder() { preOrder(root); }
    void preOrder(leaf *trav)
    {
        if (trav)
        {
            cout << trav->data << " ";
            preOrder(trav->left);
            preOrder(trav->right);
        }
    }
    void postOrder() { postOrder(root); }
    void postOrder(leaf *trav)
    {
        if (trav)
        {
            preOrder(trav->left);
            preOrder(trav->right);
            cout << trav->data << " ";
        }
    }
    void inOrder() { inOrder(root); }
    void inOrder(leaf *trav)
    {
        if (trav)
        {
            preOrder(trav->left);
            cout << trav->data << " ";
            preOrder(trav->right);
        }
    }
};

int main()
{
    TREE t;
    t.insert(3);
    t.insert(4);
    t.insert(7);
    t.insert(6);
    t.insert(0);
    cout << "In Order : ";
    t.inOrder();
    cout << endl;
    cout << "Pre Order : ";
    t.preOrder();
    cout << endl;
    cout << "Post Order : ";
    t.postOrder();
    cout << endl;
    cout << "Searching : " << endl;
    t.search(6);
    t.search(5);
    cout << "Deleting : " << endl;
    t.deleteLeaf(4);
    cout << "In Order : ";
    t.inOrder();
    cout << endl;
    cout << "Pre Order : ";
    t.preOrder();
    cout << endl;
    cout << "Post Order : ";
    t.postOrder();
    cout << endl;

    system("pause");
    return 0;
}