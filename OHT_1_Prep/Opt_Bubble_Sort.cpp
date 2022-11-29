#include <iostream>
using namespace std;

void obSort(int arr[], int size)
{
    int swapCount = 0, innerCount = 0, outerCount = 0;
    bool flag = false;
    for (int i = 0; i < size - 1; i++)
    {
        outerCount++;
        flag = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            innerCount++;
            if (arr[j] > arr[j + 1])
            {
                swapCount++;
                flag = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    cout << "Swaps : " << swapCount << endl;
    cout << "Outer Loop : " << outerCount << endl;
    cout << "Inner Loop : " << innerCount << endl;
}
void display(int arr[], int size)
{
    cout << "Array :: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {2, 8, 1, 3, 0, 2, 4, 5, 9, 10, 11};
    int size = *(&arr + 1) - arr;
    display(arr, size);
    obSort(arr, size);
    display(arr, size);
    system("pause");
    return 0;
}