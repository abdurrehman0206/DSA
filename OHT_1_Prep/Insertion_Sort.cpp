#include <iostream>
using namespace std;

void iSort(int arr[], int size)
{
    int swapCount = 0, innerCount = 0, outerCount = 0;
    int j = 0, key = 0;
    for (int i = 1; i < size; i++)
    {
        outerCount++;
        j = i;
        key = arr[i];
        while (j > 0 && key < arr[j - 1])
        {
            innerCount++;
            arr[j] = arr[j - 1];
            j--;
        }
        if (arr[j] != key && j != i)
        {
            swapCount++;
            arr[j] = key;
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
    iSort(arr, size);
    display(arr, size);
    system("pause");
    return 0;
}