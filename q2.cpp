#include <iostream>
using namespace std;

struct node
{
    unsigned int wheels;
    float tax, fine;
    string licenseNo, owner, date;
    node *next = NULL;
    node *prev = NULL;
};
class E_Challan
{
    node *head, *tail, *trav;

public:
    E_Challan() : head(NULL), tail(NULL), trav(NULL){};
    bool isEmpty()
    {
        return head == NULL ? true : false;
    }

    void addRecord()
    {

        node *newNode = new node;
        cout << "Enter Date : ";
        getline(cin, newNode->date);
        cout << "Enter Owner Name : ";
        getline(cin, newNode->owner);
        cout << "Enter License Plate No. : ";
        getline(cin, newNode->licenseNo);
        cout << "Enter Car Wheels : ";
        cin >> newNode->wheels;
        cout << "Enter Tax : ";
        cin >> newNode->tax;
        cout << "Enter Fine : ";
        cin >> newNode->fine;
        cin.sync();
        checkWheels(newNode);
        newNode->fine += newNode->tax;
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
        cout << endl;
    }
    void checkWheels(node *n)
    {
        if (n->wheels >= 6)
        {
            n->fine += 50;
            cout << "Added 50$ on Wheels" << endl;
            cout << "New Fine : " << n->fine << endl;
        }
    }
    void removeRecord(string _owner, string _license, string _date)
    {
        if (!isEmpty())
        {
            trav = head;
            node *temp = NULL;
            while (trav->owner != _owner && trav->licenseNo != _license && trav->date != _date && trav != NULL)
            {
                trav = trav->next;
            }
            if (trav == head && trav == tail)
            {
                head = NULL;
                tail = NULL;
            }
            else if (trav == head)
            {
                temp = head;
                head = head->next;
                head->prev = NULL;
            }
            else if (trav == tail)
            {
                temp = tail;
                tail = tail->prev;
                tail->next = NULL;
            }
            else if (trav == NULL)
            {
                cout << "No Ticket Found !" << endl;
                return;
            }
            else
            {
                temp = trav;
                trav->next->prev = trav->prev;
                trav->prev->next = trav->next;
            }
            cout << "Paid" << endl;
            delete temp;
        }
        else
        {
            cout << "No Tickets In The System !" << endl;
        }
    }
    void display()
    {
        trav = head;
        while (trav != NULL)
        {
            cout << "------------------------------" << endl
                 << "Date          : " << trav->date << endl
                 << "Name          : " << trav->owner << endl
                 << "Licence Plate : " << trav->licenseNo << endl
                 << "Wheels        : " << trav->wheels << endl
                 << "Tax           : " << trav->tax << endl
                 << "------------------------------" << endl
                 << "Fine          : " << trav->fine << endl
                 << "------------------------------" << endl;
            trav = trav->next;
        }
        cout << endl;
    }
};
int main()
{
    E_Challan e;
    e.addRecord();
    e.addRecord();
    e.addRecord();
    e.display();
    e.removeRecord("Bob", "LXF", "20 Dec");
    e.display();
    system("pause");
    return 0;
}