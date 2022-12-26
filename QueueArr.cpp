#include <iostream>
using namespace std;
// A queue is a linear data structure
// It works on FIFO Principle
// FIRST IN FIRST OUT
// Enqueue is adding an element to the queue
// We are using simplest approch to queue
// In actual queue we have to move the elements when Enqueuing
// In this implementationt when we dequeue we just move indexes so we will only be able to
// enqueue to full size once before dequeueing all elements and then reseting the pointers
// we are using array for static implemntation of queue
class queue
{
    // we use two index pointers
    int front, rear;
    int data[5];

public:
    queue() : front(-1), rear(-1)
    {
        // just initializing to -1 to avoid garbage
        for (int i = 0; i < 5; i++)
        {
            data[i] = -1;
        }
    }
    // checking if the q is empty or full
    bool isFull()
    {
        // if rear is at last index then the q is full
        if (rear == 4)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        // incase both pointers are at -1 the q is empty
        if (rear == -1 && front == -1)
        {
            return true;
        }
        return false;
    }
    // enqueue is basically adding elements to the end of the q
    void enqueue(int key)
    {
        // if empty insert at index 0 after moving the pointer to start
        if (isEmpty())
        {
            front = rear = 0;
            data[rear] = key;
        }
        else if (isFull())
        {
            cout << "Queue Full!" << endl;
        }
        else
        {
            // insert at next empty spot
            // moving the rear once step forward and inserting
            rear++;
            data[rear] = key;
        }
    }
    // dequeue is removinn and processing the first element added  to the q
    int dequeue()
    {
        // variable for storing the item to be dqd
        int dq;
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            // we need to remove from the end
            // we will remove from front
            dq = data[front];
            // resetting value
            data[front] = -1;
            // moving the front forward
            // remember at this step we actually need to move the elements back
            //  but for visualization we are using this simple approach
            front++;
            // we need to check that if front is ahead of rear that means last element was dqd
            // we need to reset
            if (front > rear)
            {
                front = rear = -1;
            }
            return dq;
        }
    }
    void display()
    {
        // we are printing in reverse to actually see the queues working
        if (!isEmpty())
        {
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
    queue q;
    q.enqueue(1);
    q.display();
    q.enqueue(2);
    q.display();
    q.enqueue(3);
    q.display();
    q.enqueue(4);
    q.display();
    q.enqueue(5);
    q.display();
    q.dequeue();
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