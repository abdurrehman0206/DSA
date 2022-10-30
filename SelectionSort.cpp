#include <iostream>
using namespace std;

void selectSort(int arr[], int size)
{
    int min = -1;
    int iterations = 0;
    int swaps = 0;
    for (int i = 0; i < size - 1; i++)
    {
        iterations++;
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            iterations++;
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swaps++;
            swap(arr[i], arr[min]);
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
    selectSort(arr, size);
    cout << "After Sort : " << endl;
    print(arr, size);

    system("pause");
    return 0;
}