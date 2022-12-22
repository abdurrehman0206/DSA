#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};
class DLL
{
    node *head, *tail;

public:
    DLL()
    {
        head = NULL;
        tail = NULL;
    };
    // insert at start
    void insertBeg(int v)
    {
        // creating a new node
        node *temp = new node;
        // assigning data to new node temp
        temp->data = v;
        // making the next and prev = NULL
        temp->next = NULL;
        temp->prev = NULL;
        // making next NULL is not required when inserting at beginning
        // we check if the list is empty or not
        // if empty insert and assign head tail
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        // incase head is not null we push the new node in front
        else
        {
            // firstly we make the new links before breaking old one
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    // insertion at end
    void insertEnd(int v)
    {
        // creating a new node
        node *temp = new node;
        // assigning value to node temp
        temp->data = v;
        // setting next and prev to NULL
        temp->next = NULL;
        temp->prev = NULL;
        // checking if list is empty or not
        // if empty assign head and tail
        // else push node to end
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            // firstly creating new links
            temp->prev = tail;
            tail->next = temp;
            // reassigning tail
            tail = temp;
        }
    }
    // insertion at mid
    void insertMid(int v, int pos)
    {
        // creating new node temp and assigning data to it and making next and prev NULL
        node *temp = new node;
        temp->data = v;
        temp->next = NULL;
        temp->prev = NULL;
        // we check if the pos is 0 we insert at the beginning
        if (pos == 0)
        {
            // we call the insert at start function
            insertBeg(v);
        }
        else
        {
            // if pos is not 0 then we move a pointer to the desired location and then insert
            // making a new pointer to move to desired location
            node *ptr = head;
            // we need to run the loop till desired location is found or
            // the link lists end
            while (pos > 1 && ptr != NULL)
            {
                ptr = ptr->next;
                pos--;
            }
            // if ptr = NULL that means the pos is greater than the size so we insert at end
            if (ptr == NULL)
            {
                // call insert end fucntion
                insertEnd(v);
            }
            else
            {
                // if position is found then insert
                temp->next = ptr->next;
                temp->prev = ptr;
                ptr->next = temp;
                ptr->next->prev = temp;
            }
        }
    }
    // deletion at beg
    void deleteBeg()
    {
        // making a new node to store the item to delete
        node *temp = new node;
        // assigning head to the new node as we are deleting head
        temp = head;
        // if the list is empty there is nothing to delete
        if (head == NULL)
        {
            cout << "List is empty ! " << endl;
        }
        else
        {
            // if list is populated then we can delete head
            // we need to unlink head first
            // temp is pointing to head
            // moving the head
            head = head->next;
            // delinking
            head->prev = NULL;
            temp->next = NULL;
            cout << "Deleted " << temp->data << " at head" << endl;
            // deleting the node from memory
            delete temp;
        }
    }
    // deletion at end
    void deleteEnd()
    {
        // creating a new node temp to point to the node to be deleted
        node *temp = new node;
        // since we are deleting tail
        temp = tail;
        // we need to check if the list is empty or not
        if (head == NULL)
        {
            cout << "List is empty !" << endl;
        }
        else
        {
            // if list is populated delete
            // moving tail
            tail = tail->prev;
            // delinking
            tail->next = NULL;
            temp->prev = NULL;
            cout << "Deleted " << temp->data << " at tail" << endl;
            // deleting node from memory
            delete temp;
        }
    }
    void deletePos(int pos)
    {
        // creating a new node temp to point to the node to be deleted
        node *temp = new node;
        // since we are deleting tail
        temp = head;
        // we need to check if the list is empty or not
        if (head == NULL)
        {
            cout << "List is empty !" << endl;
        }
        else if (pos == 0)
        {
            deleteBeg();
        }
        else
        {
            while (temp != NULL && pos > 0)
            {
                temp = temp->next;
                pos--;
            }
            if (temp == NULL)
            {
                cout << "Position doesn't exist !" << endl;
            }
            else if (temp->next == NULL)
            {
                deleteEnd();
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = NULL;
                temp->next = NULL;
                cout << "Deleted " << temp->data << endl;
                delete temp;
            }
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
        }
        else
        {
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    DLL d;
    d.insertBeg(3);
    d.insertBeg(2);
    d.insertBeg(1);
    d.display();
    d.insertEnd(4);
    d.insertEnd(5);
    d.insertEnd(6);
    d.display();
    // we count from 0 for pos
    // so if we want to insert an element at fourth position we specify it as 3
    // inserting 7 at 4th location i.e 3rd pos
    d.insertMid(7, 3);
    // incase we give a larger number that is bigger than size
    d.display();
    // it will insert it at the end
    d.insertMid(8, 11);
    d.display();
    d.deleteBeg();
    d.display();
    d.deleteEnd();
    d.display();
    d.deletePos(3);
    d.display();
    d.deletePos(2);
    d.display();

    system("pause");
    return 0;
}