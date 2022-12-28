#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
    char data;
    node *next = NULL;
    node *prev = NULL;
};
class StackLL
{
    node *head, *tail;

public:
    StackLL() : head(NULL), tail(NULL) {}
    StackLL(StackLL *s)
    {
        node *trav = s->tail;
        while (trav != NULL)
        {
            push(trav->data);
            trav = trav->prev;
        }
    }
    bool isEmpty()
    {
        return head == NULL ? true : false;
    }
    void push(char key)
    {
        node *newNode = new node;
        newNode->data = key;
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    int pop()
    {
        int popped;
        if (!isEmpty())
        {
            node *temp = tail;
            popped = tail->data;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            return popped;
        }
        return errno;
    }
    void display()
    {
        if (!isEmpty())
        {
            node *trav = head;
            while (trav != NULL)
            {
                cout << trav->data << " ";
                trav = trav->next;
            }
            cout << endl;
        }
    }
    const bool operator==(const StackLL *s)
    {

        node *trav1 = s->head;
        node *trav2 = head;
        while (trav1 != NULL && trav2 != NULL)
        {
            if (trav1->data != trav2->data)
            {
                return false;
            }
            trav1 = trav1->next;
            trav2 = trav2->next;
        }
        return true;
    }
};

int main()
{
    StackLL s1;
    char ch;
    cout << "Enter an Expression : ";
    do
    {
        ch = getche();
        if (ch != ' ' || ch != ',')
        {
            s1.push(ch);
        }
        else
        {
            continue;
        }

    } while (ch != '.');
    s1.pop();
    cout << endl;
    StackLL s1r(&s1);

    s1.display();
    s1r.display();
    // cout << &s1 == &s1r;
    bool is = s1 == &s1r;
    cout << is << endl;
    system("pause");
    return 0;
}