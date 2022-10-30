#include <iostream>
using namespace std;
static int iterations = 0;

static int recusriveCalls = 0;
static int recursiveMergeCalls = 0;
void mergeArr(int arr[], int left, int mid, int right)
{
    recursiveMergeCalls++;
    int i = 0;
    int j = 0;
    int k = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1];
    int R[n2];
    for (i = 0; i < n1; i++)
    {
        iterations++;
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        iterations++;
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        iterations++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        iterations++;
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        iterations++;
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right)
{
    recusriveCalls++;

    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeArr(arr, left, mid, right);
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
    mergeSort(arr, 0, size - 1);
    cout << "After Sort : " << endl;
    print(arr, size);
    cout << "Number of iterations : " << iterations << endl;
    // recursive call is one less than the number of times the function is called
    cout << "Number of recursive calls : " << recusriveCalls - 1 << endl;
    cout << "Number of recursive merge calls : " << recursiveMergeCalls << endl;
    system("pause");
    return 0;
}