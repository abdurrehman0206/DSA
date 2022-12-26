#include <iostream>
using namespace std;

// stack is a linear data structure working on LIFO principle
// since we only need access to top element
// we can use a singly linked list
// it will make the stack dynamic with no size restrictions
// the code structure for singly linked list is simple
// SINGLY LINKED LIST
struct node
{
    int data;
    node *next = NULL;
};
class Stack
{
    node *head;

public:
    Stack() : head(NULL){};
    // we only need head in this case
    // pushing is basically insertion at head
    // popping is deletion at head
    // we do not need to check if stack is full

    // checking empty
    bool isEmpty()
    {
        // if the head is NULl that means the list is empty
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    // push is insertion at head/beginning
    void push(int key)
    {
        // creating a new node
        node *temp = new node;
        // assigning value to data
        temp->data = key;
        if (isEmpty())
        {
            // if the list is empty
            // insert the new node and make it head
            head = temp;
        }
        else
        {
            // if not then link the new node to head and make new node the head
            temp->next = head;
            head = temp;
            cout << "Pushed " << head->data << endl;
        }
    }
    // popping is deletion at head
    int pop()
    {
        // vatiable to store the deleted data
        int popped;
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return errno;
        }
        else
        {
            // assign a temp pointer to the head before deleting it
            node *temp = head;
            // moving the head to its next i.e the new head
            // delinking the old head
            head = head->next;
            temp->next = NULL;
            popped = temp->data;
            cout << "Popped " << temp->data << endl;
            // delete the node from memory / free memory
            delete temp;
            return popped;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Stack is Empty!" << endl;
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.display();565
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