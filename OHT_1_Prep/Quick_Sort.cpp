#include <iostream>
using namespace std;
int swapCount = 0, iteration = 0, recursiveCalls = -1;
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    int j;
    for (int j = start; j < end; j++)
    {
        iteration++;
        if (pivot > arr[j])
        {
            i++;
            if (i != j)
            {
                swapCount++;
                swap(arr[i], arr[j]);
            }
        }
    }
    i++;
    if (i != end)
    {
        swapCount++;
        swap(arr[end], arr[i]);
    }
    return i;
}
void qSort(int arr[], int start, int end)
{
    recursiveCalls++;
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        qSort(arr, start, pivot - 1);
        qSort(arr, pivot + 1, end);
    }
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
    qSort(arr, 0, size - 1);
    display(arr, size);
    cout << "Swaps : " << swapCount << endl;
    cout << "Iterations : " << iteration << endl;
    cout << "Recursive Calls : " << recursiveCalls << endl;
    system("pause");
    return 0;
}