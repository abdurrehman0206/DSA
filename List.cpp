#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insert(int item, node *&head)
{
    node *newNode = new node;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void dupli(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        node *temp2 = temp;
        while (temp2->next != NULL)
        {
            if (temp->data == temp2->next->data)
            {
                node *temp3 = temp2->next;
                temp2->next = temp2->next->next;
                delete temp3;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}
void matching(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        node *newNode = new node;
        newNode->data = temp->data;
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
}

int main()
{
    node *head = NULL;
    insert(1, head);
    insert(2, head);
    insert(2, head);
    insert(3, head);
    insert(4, head);
    insert(4, head);
    insert(5, head);
    print(head);
    dupli(head);
    print(head);
    matching(head);
    print(head);
    system("pause");
    return 0;
}