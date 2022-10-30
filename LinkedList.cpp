#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class LinkedList
{
private:
    node *head, *tail;

public:
    LinkedList() : head(NULL), tail(NULL){};
    void addNode(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void display()
    {
        node *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
};

int main()
{
    LinkedList a;
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    a.addNode(4);
    a.display();
    system("pause");
    return 0;
}