#include <iostream>
using namespace std;
int iteration = 0, recursiveCalls = -1;
void merge(int arr[], int start, int mid, int end)
{
    int tempArr[50];
    int i = start;
    int j = mid + 1;
    int k = start;
    while (i <= mid && j <= end)
    {
        iteration++;
        if (arr[i] < arr[j])
        {
            tempArr[k++] = arr[i++];
        }
        else
        {
            tempArr[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        iteration++;
        tempArr[k++] = arr[i++];
    }
    while (j <= end)
    {
        iteration++;
        tempArr[k++] = arr[j++];
    }
    for (int l = start; l < k; l++)
    {
        iteration++;
        arr[l] = tempArr[l];
    }
}
void mSort(int arr[], int start, int end)
{
    recursiveCalls++;
    if (start < end)
    {
        int mid = (start + end) / 2;
        mSort(arr, start, mid);
        mSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
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
    mSort(arr, 0, size - 1);
    display(arr, size);
    cout << "Iterations : " << iteration << endl;
    cout << "Recursive Calls : " << recursiveCalls << endl;
    system("pause");
    return 0;
}