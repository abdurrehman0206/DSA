#include <iostream>
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int arr[10];

public:
    Queue() : front(-1), rear(-1){};
    bool isFull()
    {
        if (rear == 9)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    void enqueue(int num)
    {
        if (isFull())
        {
            cout << "Queue Full ! " << endl;
            return;
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
            }
            rear++;
            arr[rear] = num;
            cout << "Enqueued " << num << " at " << rear << endl;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty ! " << endl;
        }
        else
        {
            cout << "Dequeued " << arr[front] << " at " << front << endl;
            front++;
            if (front > rear)
            {
                front = rear = -1;
            }
        }
    }
    void printQueue()
    {
        for (int i = front; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Queue *q = new Queue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->printQueue();
    q->dequeue();
    q->printQueue();
    q->dequeue();
    q->printQueue();


    system("pause");
    return 0;
}