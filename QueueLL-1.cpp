#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node() : data(0), next(NULL) {}
};

class queue
{
    node *head;
    node *tail;

public:
    queue() : head(NULL), tail(NULL) {}
    bool isEmpty() { return head == NULL && tail == NULL; }
    void enqueue(int key)
    {
        node *newNode = new node;
        newNode->data = key;
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int dequeue()
    {

        int dq = -1;
        if (!isEmpty())
        {
            dq = head->data;
            node *temp = head;
            head = head->next;
            if (head == NULL)
            {
                head = tail = NULL;
            }
            temp = NULL;
            delete temp;
        }
        else
        {
            cout << "Queue is empty !" << endl;
        }
        return dq;
    }
    void printQueue()
    {
        if (!isEmpty())
        {
            cout << "Queue : ";
            node *trav = head;
            while (trav)
            {
                cout << trav->data << " ";
                trav = trav->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Queue is empty !" << endl;
        }
    }
};
int main()
{
    queue p;
    p.enqueue(8);
    p.enqueue(6);
    p.enqueue(2);
    p.enqueue(4);
    p.enqueue(7);
    p.enqueue(9);
    p.printQueue();
    p.dequeue();
    p.printQueue();
    p.dequeue();
    p.printQueue();
    p.dequeue();
    p.printQueue();
    p.dequeue();
    p.printQueue();
    p.dequeue();
    p.printQueue();
    p.dequeue();
    p.printQueue();
    system("pause");
    return 0;
}