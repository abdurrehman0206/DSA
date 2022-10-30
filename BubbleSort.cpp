#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    int iterations = 0;
    int swaps = 0;
    for (int i = 0; i < size - 1; i++)
    {
        iterations++;
        for (int j = 0; j < size - i - 1; j++)
        {
            iterations++;
            if (arr[j] > arr[j + 1])
            {
                swaps++;
                swap(arr[j], arr[j + 1]);
            }
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
    bubbleSort(arr, size);
    cout << "After Sort : " << endl;
    print(arr, size);
    system("pause");
    return 0;
}