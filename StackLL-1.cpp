#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node() : data(0), next(NULL) {}
};
class stack
{
    node *head;

public:
    stack() : head(NULL) {}
    bool isEmpty() { return head == NULL; }
    void push(int key)
    {
        node *newNode = new node;
        newNode->data = key;
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
    void pop()
    {
        if (!isEmpty())
        {
            node *temp = head;
            head = head->next;
            temp = NULL;
            delete temp;
        }
        else
        {
            cout << "UnderFlow !" << endl;
        }
    }
    int top() const { return head->data; }
    void printStack()
    {
        if (!isEmpty())
        {
            cout << "Stack : ";
            node *trav = head;
            while (trav)
            {
                cout << trav->data << " ";
                trav = trav->next;
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
    stack s;
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(5);
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