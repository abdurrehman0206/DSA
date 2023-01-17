#include <iostream>
using namespace std;

class cQueue
{
    int *data;
    int FRONT;
    int REAR;
    int SIZE;

public:
    cQueue(int _size) : SIZE(_size), FRONT(-1), REAR(-1)
    {
        data = new int[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            data[i] = -1;
        }
    }
    bool isFull() { return ((FRONT == REAR + 1) || (FRONT == 0 && REAR == SIZE - 1)); }
    bool isEmpty() { return (FRONT == -1 && REAR == -1); }
    int front() { return (!isEmpty() ? data[FRONT] : -1); }
    int rear() { return (!isEmpty() ? data[REAR] : -1); }
    void enqueue(int key)
    {
        if (isEmpty())
        {
            FRONT = 0;
        }
        else if (isFull())
        {
            cout << "Queue is Full !" << endl;
            return;
        }
        REAR += 1 % SIZE;
        data[REAR] = key;
    }
    void dequeue()
    {
        if (!isEmpty())
        {
            data[FRONT] = -1;
            if (FRONT == REAR)
            {
                FRONT = REAR = -1;
            }
            else
            {
                FRONT += 1 % SIZE;
            }
        }
        else
        {
            cout << "Queue is Empty !" << endl;
        }
    }
    void printQueue()
    {
        if (!isEmpty())
        {
            cout << "Queue : ";
            for (int i = REAR; i >= FRONT; i--)
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
    cQueue p(5);
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