#include <iostream>
using namespace std;

class pQueue
{
    int *queue;
    int front, rear;
    int size;
    void slide()
    {
        for (int i = rear; i >= front; i--)
        {
            queue[i + 1] = queue[i];
        }
        rear++;
    }
    void order()
    {
        bool inOrder = true;
        for (int i = front; i < rear; i++)
        {
            for (int j = i; j <= rear - i - 1; j++)
            {
                if (queue[j] > queue[j + 1])
                {
                    inOrder = false;
                    swap(queue[j], queue[j + 1]);
                }
            }
            if (inOrder)
            {
                break;
            }
        }
    }

public:
    pQueue(int _size)
    {
        size = _size;
        front = rear = -1;
        queue = new int[size];
        for (int i = 0; i < size; i++)
        {
            queue[i] = -1;
        }
        cout << "Queue instansitated of size " << size << endl;
    };
    bool isFull()
    {
        return (front == 0 && rear == size - 1) ? true : false;
    }
    bool isEmpty()
    {
        return (rear == -1 && front == -1) ? true : false;
    }
    void push(int key)
    {

        if (isFull())
        {
            cout << "Queue Full !" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
            queue[front] = key;
        }
        else
        {
            slide();
            queue[front] = key;
            order();
        }

        cout << "Queued " << key << endl;
    }
    int pop()
    {
        int popped;
        if (isEmpty())
        {
            cout << "Queue Empty!" << endl;
            return -1;
        }
        popped = queue[rear--];
        front = (rear == -1 ? -1 : front);
        cout << "Popped " << popped << endl;
        return popped;
    }
    void display()
    {
        if (!isEmpty())
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Queue Empty!" << endl;
        }
    }
};
int main()
{
    pQueue p(3);
    p.push(1);
    p.display();
    p.push(2);
    p.display();
    p.push(3);
    p.display();
    p.pop();
    p.display();
    p.pop();
    p.display();
    p.pop();
    p.display();
    system("pause");
    return 0;
}