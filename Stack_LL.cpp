#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next = NULL;
};
class stack
{
    node *head;

public:
    stack() : head(NULL){};
    bool isEmpty()
    {
        return head == NULL ? true : false;
    }
    void push(int data)
    {
        node *newNode = new node();
        newNode->data = data;
        if (isEmpty())
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty !" << endl;
            return -1;
        }
        else
        {
            int tempData = head->data;
            node *temp = new node();
            temp = head;
            head = head->next;
            temp = NULL;
            delete temp;
            cout << "Popped : " << tempData << endl;
            return tempData;
        }
    }
    int top()
    {
        return isEmpty() ? -1 : head->data;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty !" << endl;
        }
        else
        {
            node *trav = head;
            while (trav != NULL)
            {
                cout << trav->data << " | ";
                trav = trav->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    cout << s.pop() << endl;
    s.display();
    s.pop();
    s.display();
    system("pause");
    return 0;
}