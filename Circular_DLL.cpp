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
    void insertBeginning(int data)
    {
        node *newNode = new node();
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }
    void insertEnd(int data)
    {
        node *newNode = new node();
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertPos(int data, int pos)
    {
        node *newNode = new node();
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        if (pos == 0)
        {
            insertBeginning(data);
            return;
        }
        trav = head;
        while (pos > 1)
        {
            trav = trav->next;
            pos--;
            if (trav->next == head)
            {
                insertEnd(data);
                return;
            }
        }
        if (trav != NULL)
        {
            newNode->prev = trav;
            newNode->next = trav->next;
            trav->next->prev = newNode;
            trav->next = newNode;
        }
    }
    void deleteHead()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "List does not exists ! " << endl;
            return;
        }
        node *temp = new node();
        temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        cout << "Deleted " << temp->data << " at head" << endl;
        delete (temp);
    }
    void deleteTail()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "List does not exists ! " << endl;
            return;
        }
        node *temp = new node();
        temp = tail;
        tail = tail->prev;
        head->prev = tail;
        tail->next = head;
        cout << "Deleted " << temp->data << " at tail" << endl;
        delete (temp);
    }
    void deletePos(int pos)
    {
        int tempPos = pos;
        if (head == NULL && tail == NULL)
        {
            cout << "List does not exists ! " << endl;
            return;
        }
        if (pos == 0)
        {
            deleteHead();
            return;
        }
        trav = head;
        do
        {
            trav = trav->next;
            pos--;
        } while (trav != head && pos > 0);
        if (trav == head)
        {
            deleteTail();
            return;
        }
        node *temp = new node();
        temp = trav;
        trav->next->prev = trav->prev;
        trav->prev->next = trav->next;
        cout << "Deleted " << temp->data << " at " << tempPos << endl;
        delete (temp);
    }
    void search(int key)
    {
        int loc = 0;
        bool found = false;
        trav = head;
        do
        {
            if (trav->data == key)
            {
                found = true;
                break;
            }
            loc++;
            trav = trav->next;
        } while (trav != head);
        if (found)
        {
            cout << "Element " << key << " found at " << loc << endl;
        }
        else
        {
            cout << "Element does not exists !" << endl;
        }
    }
    void print()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "List does not exists ! " << endl;
            return;
        }
        trav = head;
        do
        {
            cout << trav->data << (trav == tail ? "" : "--->");
            trav = trav->next;
        } while (trav != head && head != tail);
        cout << endl;
    }
};
int main()
{
    CDLL l;
    l.insertBeginning(1);
    l.insertBeginning(2);
    l.insertEnd(3);
    l.insertEnd(4);
    l.insertPos(5, 2);
    l.insertPos(6, 3);
    l.insertPos(7, 7);
    l.print();
    l.deleteHead();
    l.print();
    l.search(6);
    l.deleteTail();
    l.print();
    l.deletePos(2);
    l.print();
    l.search(4);
    l.search(9);

    system("pause");
    return 0;
}