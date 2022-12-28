#include <iostream>
using namespace std;

class cQ
{
    int front, rear;
    int *data;
    int size;

public:
    cQ(int _size) : front(-1), rear(-1), size(_size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = -1;
        }
        cout << "Circular Queue Size " << size << " instansiated !" << endl;
    };
    bool isFull()
    {
        return ((front == rear + 1) || (front == 0 && rear == size - 1) ? true : false);
    }
    bool isEmpty()
    {
        return ((front == -1 && rear == -1) ? true : false);
    }
    void enqueue(int key)
    {
        if (!isFull())
        {
            if (isEmpty())
            {
                front = 0;
            }
            rear += 1 % size;
            data[rear] = key;

            cout << "Enqueued " << key << endl;
        }
        else
        {
            cout << "Full !" << endl;
        }
    }
    int dequeue()
    {
        int dq = -1;
        if (!isEmpty())
        {
            dq = data[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front += 1 % size;
            }
            cout << "Dequeued " << dq << endl;
        }
        else
        {
            cout << "Empty !" << endl;
        }
        return dq;
    }
    void display()
    {
        if (!isEmpty())
        {
            for (int i = front; i <= rear; i += 1 % size)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    cQ c(3);
    c.enqueue(1);
    c.display();
    c.enqueue(2);
    c.display();
    c.enqueue(3);
    c.display();
    c.enqueue(4);
    c.display();
    c.dequeue();
    c.display();
    c.dequeue();
    c.display();
    c.dequeue();
    c.display();
    c.dequeue();
    c.display();
    system("pause");
    return 0;
}