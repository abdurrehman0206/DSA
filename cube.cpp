#include <iostream>
using namespace std;

class queue
{

    int arr[5];
    int front = -1;
    int rear = -1;

public:
    bool is_empty()
    {

        if (front == -1 && rear == -1)
        {

            return true;
        }
        else
        {

            return false;
        }
    }

    bool is_full()
    {
        if (rear == 4)
        {

            return true;
        }
        else
        {

            return false;
        }
    }

    void enqueue(int data)
    {

        if (is_full())
        {
            cout << "Overflow" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {

            front = rear = 0;
            arr[rear] = data;
        }
        else
        {

            rear++;
            arr[rear] = data;
        }
    }

    void dequeue()
    {

        if (is_empty())
        {

            cout << "Queue is empty" << endl;
        }
        else if (front > rear)
        {

            front = rear = -1;
        }
        else
        {

            front++;
        }

        cout << endl;
    }

    void disp()
    {

        if (is_empty())
        {

            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {

            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{

    queue q;

    cout << "Enqueue" << endl;
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.disp();

    cout << endl
         << "Dequeue" << endl;
    q.dequeue();
    q.disp();
    q.dequeue();
    q.disp();
    q.dequeue();
    q.disp();
    q.dequeue();
    q.disp();
    q.dequeue();
    q.disp();
    q.dequeue();
    q.disp();

    cout << endl;
    system("pause");
    return 0;
}