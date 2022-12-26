#include <iostream>
using namespace std;

// Stack is a linear data structure working on
// LIFO Principle
// Last In First Out
class Stack
{
    int *data;
    int TOP;
    int size;

public:
    Stack(int _size) : TOP(-1)
    {
        size = _size;
        // dynamic allocation
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = -1;
        }
    }
    // functions to check if the stack is full or empty
    bool isEmpty()
    {
        // size in the constructor we initialized TOP
        // to -1 we check if the TOP is still at that
        // position . If so then stack is empty
        if (TOP == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        // if TOP is at last index it means the stack is full
        if (TOP == size - 1)
        {
            return true;
        }
        return false;
    }
    // making a push function
    void push(int key)
    {
        // if the stack is full we cannot insert
        if (isFull())
        {
            cout << "Stack is Full !" << endl;
        }
        else
        {
            // we move the TOP index and insert at the new location each time we push
            data[++TOP] = key;
            cout << "Pushed " << key << endl;
        }
    }
    // making a pop function
    // popping an item is not deletion in the sense
    // that we usually pop an item when we need to process it
    // hence we make a fucntion that returns the popped value
    int pop()
    {
        // if the stack is empty nothing to pop
        // we need a varible to store the value
        int popped;
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return errno;
        }
        else
        {
            popped = data[TOP];
            // we reset the value to -1 and move top one step back
            data[TOP--] = -1;
            cout << "Popped " << popped << endl;
            return popped;
        }
    }
    // making a display function
    // in real we usually pop each element and print it but
    // for the sake of visualization
    // we will use a normal array print
    void display()
    {
        if (!isEmpty())
        {
            for (int i = 0; i <= TOP; i++)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Stack is empty!" << endl;
        }
    }
};
int main()
{
    Stack s(3);
    s.push(1);
    s.display();
    s.push(2);
    s.display();
    s.push(3);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    system("pause");
    return 0;
}