#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    int key = 0;
    int j = 0;
    int iterations = 0;
    int swaps = 0;
    for (int i = 1; i < size; i++)
    {
        iterations++;
        key = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            iterations++;
            arr[j] = arr[j - 1];
            j--;
        }
        if (j != i)
        {
            swaps++;
            arr[j] = key;
        }
    }
    cout << "Number of iterations : " << iterations << endl;
    cout << "Number of swaps : " << swaps << endl;
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {2, 4, 43, 534, 23, 1, 3};
    int size = *(&arr + 1) - arr;
    cout << "Before Sort : " << endl;
    print(arr, size);
    insertionSort(arr, size);
    cout << "After Sort : " << endl;
    print(arr, size);
    system("pause");
    return 0;
}