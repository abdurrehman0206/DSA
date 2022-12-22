#include <iostream>
using namespace std;

bool isSpy(int num)
{
    int digit = 0, sum = 0, product = 1;
    while (num > 0)
    {
        digit = num % 10;
        sum += digit;
        product *= digit;
        num /= 10;
    }
    return (sum == product ? true : false);
}
int main()
{
    int num = 0;
    cout << "Enter a number : ";
    cin >> num;
    cout << (isSpy(num) ? "Spy " : "Not Spy ") << " number !" << endl;
    system("pause");
    return 0;
}