#include <iostream>
using namespace std;

#define MAXBALLS 10
class Cannon
{
    string *data;
    int top;
    int size;

public:
    Cannon() : size(MAXBALLS), top(-1)
    {
        data = new string[size];
        for (int i = 0; i < size; i++)
            data[i] = -1;
    }
    bool isFull()
    {
        return top == size - 1;
    }
    bool isEmpty()
    {
        return top < 2;
    }
    void load(string _ball)
    {
        if (!isFull())
        {
            data[++top] = _ball;

            cout << "Loaded " << _ball << endl;
        }
        else
        {
            cout << "Cannon is full" << endl;
        }
    }
    string fire()
    {
        if (!isEmpty())
        {
            string temp = data[top];
            data[top--] = -1;
            cout << "Fired " << temp << endl;
            return temp;
        }
        else
        {
            cout << "Cannon cannot fire ! Not sufficient Ammo !" << endl;
            return "Not Fired";
        }
    }
    ~Cannon()
    {
        delete[] data;
        cout << "Cannon is destroyed" << endl;
    }
};

int main()
{
    Cannon c;
    c.load("Red");
    c.load("Green");
    c.load("Black");
    c.load("Blue");
    c.load("Yellow");
    c.load("White");
    c.load("Orange");
    c.load("Pink");
    c.load("Purple");
    c.load("Brown");
  
    c.fire();
    c.fire();
    c.fire();
    c.fire();
    c.fire();
    c.fire();
    c.fire();
    c.fire();
    c.fire();
    c.fire();
    c.fire();

    system("pause");
    return 0;
    system("pause");
}