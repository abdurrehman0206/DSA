#include <iostream>
using namespace std;

struct leaf
{
    int data;
    leaf *left;
    leaf *right;
    leaf() : data(0), left(NULL), right(NULL){};
};
class tree
{
    leaf *root;

public:
    tree() : root(NULL){};
    bool isEmpty() { return root == NULL; }
    leaf *createLeaf(int key)
    {
        leaf *newLeaf = new leaf();
        newLeaf->data = key;
        return newLeaf;
    }
    void insert(int key) { insert(root, key); }
    void insert(leaf *temp, int key)
    {
        if (isEmpty())
        {
            root = createLeaf(key);
        }
        else if (key < temp->data)
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
    leaf *deleteLeaf(int key)
    {
        root = deleteLeaf(root, key);
        return root;
    }
    leaf *deleteLeaf(leaf *temp, int key)
    {
        if (!isEmpty())
        {
            if (temp == NULL)
            {
                return NULL;
            }
            else if (key < temp->data)
            {
                temp->left = deleteLeaf(temp->left, key);
            }
            else if (key > temp->data)
            {
                temp->right = deleteLeaf(temp->right, key);
            }
            else
            {
                if (temp->left == NULL && temp->right == NULL)
                {
                    delete temp;
                    temp = NULL;
                }
                else if (temp->left == NULL)
                {
                    leaf *t = temp;
                    temp = temp->right;
                    delete t;
                    t = NULL;
                }
                else if (temp->right == NULL)
                {
                    leaf *t = temp;
                    temp = temp->left;
                    delete t;
                    t = NULL;
                }
                else
                {
                    leaf *trav = temp->right;
                    while (trav->left != NULL)
                    {
                        trav = trav->left;
                    }
                    temp->data = trav->data;
                    temp->right = deleteLeaf(temp->right, trav->data);
                }
            }
        }
        else
        {
            cout << "Dry Tree !" << endl;
        }
        return temp;
    }
    void search(int key) { search(root, key); }
    void search(leaf *temp, int key)
    {
        if (!isEmpty())
        {
            if (temp == NULL)
            {
                cout << "Key Not Found !" << endl;
            }
            else if (temp->data == key)
            {
                cout << "Key Found !" << endl;
            }
            else if (key < temp->data)
            {
                search(temp->left, key);
            }
            else if (key > temp->data)
            {
                search(temp->right, key);
            }
        }
        else
        {
            cout << "Dry Tree !";
        }
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
    void inOrder() { inOrder(root); }
    void inOrder(leaf *trav)
    {
        if (trav)
        {
            inOrder(trav->left);
            cout << trav->data << " ";
            inOrder(trav->right);
        }
    }
    void postOrder() { postOrder(root); }
    void postOrder(leaf *trav)
    {
        if (trav)
        {
            postOrder(trav->left);
            postOrder(trav->right);
            cout << trav->data << " ";
        }
    }
};
int main()
{
    tree t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(13);
    t.insert(6);
    t.insert(9);
    cout << "Pre Order : ";
    t.preOrder();
    cout << endl;
    cout << "In Order : ";
    t.inOrder();
    cout << endl;
    cout << "Post Order : ";
    t.postOrder();
    cout << endl;
    cout << "Deleted 2" << endl;
    t.deleteLeaf(2);
    cout << "Pre Order : ";
    t.preOrder();
    cout << endl;
    cout << "In Order : ";
    t.inOrder();
    cout << endl;
    cout << "Post Order : ";
    t.postOrder();
    cout << endl;
    t.search(1);
    t.search(2);
    t.search(4);
    t.search(99);
    system("pause");
    return 0;
}