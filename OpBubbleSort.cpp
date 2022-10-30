#include <iostream>
using namespace std;

void print(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *ptr++ << " ";
    }
    cout << endl;
    ptr = NULL;
    delete ptr;
}
void bubbleSort(int arr[], int size)
{
    bool flag = false;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        flag = false;
        for (int j = 0; j < size; j++)
        {

            count++;
            flag = false;
            if (arr[j] > arr[j + 1])
            {
                flag = true;
                swap(arr[j], arr[j + 1]);
            }
            if (arr[size - j] < arr[size - j - 1])
            {
                flag = true;
                swap(arr[size - j], arr[size - j - 1]);
            }
        }
        if (!flag)
        {
            break;
        }
    }
    cout << "Total number of passes: " << count << endl;
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = *(&arr + 1) - arr;
    print(arr, size);
    bubbleSort(arr, size);
    print(arr, size);
    system("pause");
    return 0;
}