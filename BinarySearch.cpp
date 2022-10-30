#include <iostream>
using namespace std;
void sort(int *ptr, int size)
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
void print(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}
void binarySearch(int *ptr, int size, int item)
{
    int LB = 0;
    int HB = size - 1;
    int Mid = (LB + HB) / 2;
    while (LB <= HB)
    {
        if (*ptr == item)
        {
            cout << "Found at " << endl;
            return;
        }
        else if (*ptr < item)
        {
            LB = Mid + 1;
        }
        else if (*ptr > item)
        {
            HB = Mid - 1;
        }
        *ptr++;
    }
    cout << "Item not found " << endl;
}
int main()
{
    int arr[] = {1, 84, 46, 18, 16, 50,
                 446, 16, 6641, 81, 64, 564, 64, 6469, 64};
    int size = *(&arr + 1) - arr;
    sort(arr, size);
    binarySearch(arr, size, 64);

    system("pause");
    return 0;
}