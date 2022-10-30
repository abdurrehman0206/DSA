#include <iostream>
using namespace std;
int sumArr(int *ptr, int base, int counter = 0)
{
    if (base == counter)
    {
        return 0;
    }
    else
    {
        return (*ptr) + sumArr(ptr + 1, base, counter + 1);
    }
}
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    int *ptr = array;
    cout << "SUM : " << sumArr(ptr, sizeof(array) / sizeof(array[0])) << endl;
    system("pause");
    return 0;
}