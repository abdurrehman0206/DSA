#include <iostream>
using namespace std;
static int iterations = 0;
static int swaps = 0;
static int recusriveCalls = 0;
void quickSort(int arr[], int size)
{
    recusriveCalls++;
    int pivot = arr[size - 1];
    int lesser = 0, greater = size - 1;
    int i = 0;
    while (lesser < greater)
    {
        iterations++;
        while (arr[lesser] < pivot)
        {
            iterations++;
            lesser++;
        }
        while (arr[greater] > pivot)
        {
            iterations++;
            greater--;
        }
        if (arr[lesser] > arr[greater])
        {
            swap(arr[lesser], arr[greater]);
            swaps++;
        }
    }
    if (lesser > 1)
    {
        quickSort(arr, lesser);
    }
    if (greater < size - 1)
    {
        quickSort(arr + greater + 1, size - greater - 1);
    }
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
    quickSort(arr, size);
    cout << "After Sort : " << endl;
    print(arr, size);
    cout << "Number of iterations : " << iterations << endl;
    cout << "Number of swaps : " << swaps << endl;
    // recursive call is one less than the number of times the function is called
    cout << "Number of recursive calls : " << recusriveCalls - 1 << endl;
    system("pause");
    return 0;
}