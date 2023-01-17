#include <iostream>
using namespace std;

class stack
{
    int *data;
    int size;
    int TOP;

public:
    stack(int _size) : size(_size), TOP(-1)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = -1;
        }
    }
    bool isEmpty() { return TOP == -1; }
    bool isFull() { return TOP == size - 1; }
    int top() const { return data[TOP]; }
    void push(int key)
    {
        if (!isFull())
        {
            data[++TOP] = key;
        }
        else
        {
            cout << "OverFlow !" << endl;
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            data[TOP--] = -1;
        }
        else
        {
            cout << "UnderFlow !" << endl;
        }
    }
    void printStack()
    {
        if (!isEmpty())
        {
            cout << "Stack : ";
            for (int i = 0; i <= TOP; i++)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "UnderFlow !" << endl;
        }
    }
};
int main()
{
    stack s(5);
    s.push(1);
    cout << "Top : " << s.top() << endl;
    s.push(2);
    cout << "Top : " << s.top() << endl;
    s.push(3);
    cout << "Top : " << s.top() << endl;
    s.push(4);
    cout << "Top : " << s.top() << endl;
    s.push(5);
    cout << "Top : " << s.top() << endl;
    s.push(6);
    cout << "Top : " << s.top() << endl;
    s.printStack();
    s.pop();
    s.printStack();
    s.pop();
    s.printStack();
    s.pop();
    s.printStack();
    s.pop();
    s.printStack();
    s.pop();
    s.printStack();
    system("pause");
    return 0;
}