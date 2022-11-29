#include <iostream>
using namespace std;

void sSort(int arr[], int size)
{
    int swapCount = 0, innerCount = 0, outerCount = 0;
    int minIndex = -1;
    for (int i = 0; i < size - 1; i++)
    {
        outerCount++;
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            innerCount++;
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapCount++;
            swap(arr[minIndex], arr[i]);
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
    sSort(arr, size);
    display(arr, size);
    system("pause");
    return 0;
}