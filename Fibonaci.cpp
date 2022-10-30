#include <iostream>
using namespace std;
int Fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}
int main()
{
    int nthTerm = 0;
    cout << "Enter nth term of the series : ";
    cin >> nthTerm;
    cout << Fibonacci(nthTerm);
    system("pause");
    return 0;
}