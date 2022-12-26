#include <iostream>
using namespace std;

// Queue using a single linked list with head and tail
// Implentation of a queue using linked list
// Linked list
struct node
{
    int data;
    node *next = NULL;
};
class Queue
{
    node *head, *tail;

public:
    Queue() : head(NULL), tail(NULL){};
    // since we are using LL we do not need to chk is FULL
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    // enqueue is basically insertion at tail
    void enqueue(int key)
    {
        // creating new node
        // checking to see if the list is empty
        // if empty then assign head and tail to newly created node
        // else insert at tail
        node *temp = new node;
        temp->data = key;
        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            // linking the new node
            tail->next = temp;
            // making new node the tail
            tail = temp;
        }
    }
    // dequeue is basically deletion at head
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty !" << endl;
        }
        else
        {
            // making a temp pointer to head
            node *temp = head;
            // storing the data to be deqeued
            int tempData = head->data;
            // first we need to move the head to its new position
            head = head->next;
            // we need to delink
            temp->next = NULL;
            cout << "Dequeued " << tempData << endl;
            delete temp;
            return tempData;
        }
    }
    void display()
    {
        if (!isEmpty())
        {
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Queue Empty !" << endl;
        }
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.display();
    q.enqueue(2);
    q.display();
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    system("pause");
    return 0;
}