#include <iostream>
using namespace std;

struct node
{
    string name;
    int accNo;
    int balance;
    node *next = NULL;
};
class list
{
    node *head, *tail, *trav;

public:
    list() : head(NULL), tail(NULL), trav(NULL){};
    int getSize()
    {
        int size = 0;
        trav = head;
        while (trav != NULL)
        {
            trav = trav->next;
            size++;
        }
        return size;
    }
    bool accExists(int newAccNo)
    {
        bool exists = false;
        trav = head;
        while (trav != NULL)
        {
            if (trav->accNo == newAccNo)
            {
                exists = true;
            }
            trav = trav->next;
        }
        return exists;
    }
    void insert(int pos = -1)
    {
        if (pos > getSize() + 1)
        {
            cout << "Position Invalid!" << endl;
            return;
        }
        if (pos == -1)
        {
            pos = getSize();
        }
        node *temp = new node();
        cout << "Input Name : ";
        cin >> temp->name;
        do
        {
            cout << "Input Acc No : ";
            cin >> temp->accNo;
        } while (accExists(temp->accNo));
        cout << "Enter initial deposit : ";
        cin >> temp->balance;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        if (pos == 0)
        {
            temp->next = head;
            head = temp;
        }
        else if (pos == getSize())
        {
            tail->next = temp;
            tail = temp;
        }
        else
        {
            trav = head;
            while (pos > 1)
            {
                trav = trav->next;
                pos--;
            }

            temp->next = trav->next;
            trav->next = temp;
        }
    }
    void checkBalance()
    {
        int tempAccNo;
        cout << "Enter your account Number : ";
        cin >> tempAccNo;
        trav = head;
        while (trav->accNo != tempAccNo)
        {
            trav = trav->next;
        }
        if (trav != NULL)
        {
            cout << "Name : " << trav->name << endl;
            cout << "Acc No : " << trav->accNo << endl;
            cout << "Balance : " << trav->balance << endl;
        }
        else
        {
            cout << "Account Not Found!" << endl;
        }
    }
    void display()
    {
        trav = head;
        while (trav != NULL)
        {
            cout << trav->name << "," << trav->accNo << "," << trav->balance << (trav->next ? "--->" : "---> NULL");
            trav = trav->next;
        }
        cout << endl;
    }
};
int main()
{
    node n;
    cout << "n" << n.name << endl;
    list l;
    l.insert();
    l.insert();
    l.insert(2);
    l.insert(5);
    l.display();
    l.checkBalance();
    system("pause");
    return 0;
}