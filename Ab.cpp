// lets implement undo redo operations
#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
    int data;
    node *next;
};

class List
{
    node *top;

public:
    List() : top(NULL) {}

    void push(int val)
    {
        node *temp = new node;
        temp->next = NULL;
        temp->data = val;
        if (top == NULL)
        {
            top = temp;
            return;
        }
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        node *ptr = top;
        top = top->next;
        delete (ptr);
    }

    int item()
    {
        // correction#1
        return (top) ? top->data : -1;
    }

    bool empty()
    {
        return top == NULL;
    }

    void display()
    {
        if (empty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        node *ptr = top;

        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};
int main()
{
    List l1;
    List l2;
    l1.push(20);
    l1.push(10);
    l1.push(9);
    l1.push(2);
    l1.push(9);
    l1.push(6);
    l1.push(3);

    //	while(!l.empty()){
    //		cout<<l.item()<<endl;
    //		l.pop();
    //	}

    // let's write the undo redo functions
    bool flag = true;
    char ch;
    while (flag)
    {
        ch = getche();
        switch (ch)
        {
        case 'z':
            if (l1.item() != -1)
            {
                cout << "UNDO" << endl;
                l2.push(l1.item());
                l1.pop();
            }

            system("cls");
            l1.display();
            flag = true;
            break;
        case 'x':
            if (l2.item() != -1)
            {
                cout << "REDO" << endl;
                l1.push(l2.item());
                l2.pop();
            }
            system("cls");
            l1.display();
            flag = true;
            break;
        default:
            flag = false;
            break;
        }
    }
    system("pause");
    return 0;
}