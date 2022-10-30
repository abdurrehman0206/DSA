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
        if (rear == -1 && front == -1)
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
            if (rear < front)
            {
                front = rear = -1;
                return;
            }

            cout << "Dequeued " << arr[front] << endl;
            orderQueue();
        }
    }

    void orderQueue()
    {

        int temp;
        rear--;
        for (int i = 0; i <= rear; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    void printQueue()
    {
        if (front == -1 && rear == -1)
        {
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
    q->dequeue();
    q->printQueue();
    q->dequeue();
    q->printQueue();
    q->dequeue();
    q->printQueue();
    q->dequeue();
    q->printQueue();
    system("pause");
    return 0;
}