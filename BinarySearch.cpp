#include <iostream>
using namespace std;
void sort(int ptr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (ptr[i] < ptr[j])
            {
                int temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}
void print(int ptr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}
void binarySearch(int arr[], int size, int item)
{
    int LB = 0;
    int HB = size - 1;
    while (LB <= HB)
    {
        int mid = (LB + HB) / 2;
        if (arr[mid] == item)
        {
            cout << "Found at " << mid << endl;
            return;
        }
        else if (arr[mid] < item)
        {
            LB = mid + 1;
        }
        else if (arr[mid] > item)
        {
            HB = mid - 1;
        }
    }
    cout << "Item not found " << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 3, 4, 5, 6, 7, 8};
    int size = *(&arr + 1) - arr;
    sort(arr, size);
    print(arr, size);
    binarySearch(arr, size, 3);

    system("pause");
    return 0;
}