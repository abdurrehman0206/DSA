#include <iostream>
using namespace std;

struct node
{

    int data;
    node *next;
};

class queue
{

    node *head;
    node *tail;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int data)
    {

        node *temp = new node;
        temp->data = data;
        temp->next = NULL;

        if (head == NULL)
        {

            head = temp;
            tail = temp;
			return ;
        }

        temp->next = head;
        head = temp;
    }

    void disp()
    {

        if (head == NULL)
        {

            cout << "Queue is Empty" << endl;
            return;
        }

        node *ptr = head;

        while (ptr != NULL)
        {

            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};

int main()
{
    queue q;

    q.enqueue(0);
    q.enqueue(1);
    q.disp();

    cout << endl;
    system("pause");
    return 0;
}