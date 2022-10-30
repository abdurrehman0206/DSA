#include <iostream>
using namespace std;
class Stack
{
private:
    int top;
    int arr[10];

public:
    Stack() : top(-1){};
    void push(int num)
    {
        if (isFull())
        {
            cout << "Stack Full ! " << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = num;
            cout << "Pushed " << num << " at " << top << endl;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Empty Stack ! " << endl;
        }
        else
        {
            cout << "Popped " << arr[top] << " at " << top << endl;
            top--;
        }
    }
    void printStack()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top == 9)
        {
            return true;
        }
        return false;
    }
    int peek()
    {
        return arr[top];
    }
};
int main()
{
    Stack *s = new Stack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->printStack();
    s->pop();
    s->printStack();

    system("pause");
    return 0;
}