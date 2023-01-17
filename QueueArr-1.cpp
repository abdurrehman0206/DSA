#include <iostream>
using namespace std;
class queue
{
    int *data;
    int size;
    int front;
    int rear;
    void slide()
    {
        for (int i = 0; i <= rear; i++)
        {
            data[i] = data[i + 1];
        }
        rear--;
    }

public:
    queue(int _size) : size(_size), front(-1), rear(-1)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = -1;
        }
    }
    bool isEmpty() { return front == -1 && rear == -1; }
    bool isFull() { return rear == size - 1; }
    void enqueue(int key)
    {
        if (isEmpty())
        {
            front = 0;
        }
        else if (isFull())
        {
            cout << "Queue is Full !" << endl;
            return;
        }
        data[++rear] = key;
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
                slide();
            }
        }
        else
        {
            cout << "Queue is Empty !" << endl;
        }
        return dq;
    }
    void printQueue()
    {
        if (!isEmpty())
        {
            cout << "Queue : ";
            for (int i = rear; i >= front; i--)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Queue is Empty !" << endl;
        }
    }
};
int main()
{
    queue p(5);
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

    system("pause");
    return 0;
}