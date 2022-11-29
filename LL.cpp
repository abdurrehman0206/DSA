#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class list
{
private:
    node *head, *tail;

public:
    list() : head(NULL), tail(NULL){};
    void insertAtStart(int num)
    {
        node *newNode = new node;
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtEnd(int num)
    {
        node *newNode = new node;
        newNode->data = num;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertAtPosition(int num, int pos)
    {

        node *newNode = new node;
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL)
        {
            insertAtStart(num);
        }
        else
        {
            node *previous = head;
            for (int i = 0; i < pos - 1; i++)
            {
                previous = previous->next;
                if (previous == NULL)
                {
                    cout << "Position not found" << endl;
                    return;
                }
            }
            newNode->next = previous->next;
            previous->next = newNode;
        }
    }
    void deleteStart()
    {
        if (head == NULL)
        {
            cout << "List is empty !" << endl;
            return;
        }
        node *temp = new node();
        temp = head;
        head = head->next;
        delete (temp);
    }
    void deleteEnd(){
        if(head == NULL){
            cout << "List is empty !" << endl;
            return;

        }
        node *temp = new node();
        temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
    void display()
    {
        if (head == NULL)
            return;
        node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};
int main()
{
    list l;
    l.insertAtStart(10);
    l.insertAtStart(20);
    l.insertAtStart(30);
    l.display();
    l.insertAtEnd(40);
    l.insertAtEnd(50);
    l.insertAtEnd(60);
    l.display();
    l.insertAtPosition(100, 6);
    l.display();
    l.deleteStart();
    l.display();
    l.deleteEnd();
    l.display();
    system("pause");
    return 0;
}