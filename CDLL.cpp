#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev = NULL;
    node *next = NULL;
};
class CDLL
{
    node *head, *tail, *trav;

public:
    CDLL() : head(NULL), tail(NULL), trav(NULL){};
    void pushFront(int data)
    {
        node *newNode = new node();
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    void pushEnd(int data)
    {
        node *newNode = new node();
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
    void pushPos(int data, int pos)
    {

        node *newNode = new node();
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        trav = head;
        while (pos > 1)
        {
            trav = trav->next;
            pos--;
        }
        if (trav != NULL)
        {
            newNode->prev = trav;
            newNode->next = trav->next;
            trav->next->prev = newNode;
            trav->next = newNode;
        }
    }
    void pushKey(int data, int key)
    {
        node *newNode = new node();
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        if (head->data == key)
        {
            pushFront(data);
            return;
        }

        trav = head;
        do
        {
            trav = trav->next;
        } while (trav->data != key && trav != head);

        if (trav != NULL && trav != head)
        {
            newNode->prev = trav;
            newNode->next = trav->next;
            trav->next->prev = newNode;
            trav->next = newNode;
        }
    }
    void print()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "List is Empty !" << endl;
        }
        trav = head;
        do
        {
            cout << trav->data << (trav == tail ? "" : "-->");
            trav = trav->next;
        } while (trav != head);
        cout << endl;
    }
};
int main()
{
    CDLL l;
    l.pushFront(1);
    l.pushFront(2);
    l.pushEnd(3);
    l.pushEnd(4);
    l.pushKey(7, 3);
    l.pushKey(5, 9);
    l.pushKey(9, 2);
    l.print();
    system("pause");
    return 0;
}