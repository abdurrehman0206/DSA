#include <iostream>
using namespace std;
int Fibonnaci(int nthTerm, int firstTerm = 0, int secondTerm = 1)
{
    if (nthTerm == 0)
    {
        return firstTerm;
    }
    else if (nthTerm == 1)
    {
        cout << firstTerm << " ";
        return secondTerm;
    }
    else
    {
        cout << firstTerm << " ";
        return Fibonnaci(nthTerm - 1, secondTerm, firstTerm + secondTerm);
    }
}

int main()
{
    int nthTerm = 0;
    cout << "Enter nth term of the series : ";
    cin >> nthTerm;
    cout << Fibonnaci(nthTerm);
    cout << endl;
    system("pause");
    return 0;
}