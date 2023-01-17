#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

class Stack
{
    int *data;
    int size;
    int top;

public:
    Stack(int _size) : top(-1), size(_size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = -1;
        }
        cout << "Stack of size " << size << " instantiated !" << endl;
    }
    bool isFull()
    {
        if (top == size - 1)
        {
            cout << "Stack Full !" << endl;
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            cout << "Stack Empty !" << endl;
            return true;
        }
        return false;
    }
    void push(int key)
    {
        if (!isFull())
        {
            data[++top] = key;
        }
    }
    int pop()
    {
        int popped;
        if (!isEmpty())
        {
            popped = data[top];
            data[top--] = -1;
            return popped;
        }
        return errno;
    }

    void display()
    {
        if (!isEmpty())
        {
            for (int i = 0; i <= top; i++)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack s(3);
    Stack si(3);
    s.push(1);
    s.display();
    s.push(2);
    s.display();
    s.push(3);
    s.display();
    do
    {
        char c;
        c = getch();
        if (c == 'y')
        {
            si.push(s.pop());
            s.display();
        }
        else if (c == 'z')
        {
            s.push(si.pop());
            s.display();
        }
        else
        {
            break;
        }

    } while (true);

    // do
    // {
    //     system("pause>nul");
    //     if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x59))
    //     {
    //         s.push(si.pop());
    //         s.display();
    //     }
    //     else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x5A))
    //     {
    //         si.push(s.pop());
    //         s.display();
    //     }
    //     else if (GetAsyncKeyState(VK_ESCAPE))
    //     {
    //         break;
    //     }

    // } while (true);

    system("pause");
    return 0;
}