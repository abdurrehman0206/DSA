#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next = NULL;
    node *prev = NULL;
};
class DLL
{
    node *head;
    node *tail;
    node *trav;

public:
    DLL() : head(NULL), tail(NULL), trav(NULL){};
    void insertBeg(int key)
    {
        node *newNode = new node();
        newNode->data = key;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    };
    void insertEnd(int key)
    {
        node *newNode = new node();
        newNode->data = key;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    };
    void insertPos(int key, int pos)
    {
        node *newNode = new node();
        newNode->data = key;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        trav = head;
        while (pos > 1 && trav != NULL)
        {
            trav = trav->next;
            pos--;
        }
        if (trav == NULL)
        {
            insertEnd(key);
        }
        else
        {
            newNode->next = trav->next;
            newNode->prev = trav;
            trav->next = newNode;
            trav->next->prev = newNode;
        }
    };
    void display()
    {
        trav = head;
        if (head != NULL)
        {
            while (trav != NULL)
            {
                cout << trav->data << (trav->next ? "<-->" : "");
                trav = trav->next;
            }
            cout << endl;
            return;
        }
        cout << "List is empty!" << endl;
    }
};
int main()
{
    DLL d;
    d.display();
    d.insertBeg(3);
    d.insertBeg(2);
    d.insertBeg(1);
    d.display();
    d.insertEnd(4);
    d.insertEnd(5);
    d.insertEnd(6);
    d.display();
    d.insertPos(7, 3);
    d.insertPos(8, 9);
    d.display();
    system("pause");
    return 0;
}