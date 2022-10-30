#include <iostream>
using namespace std;
void input(double a[4][4])
{
    cout << "Input Array : " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Row " << i + 1 << " : " << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << i + 1 << "x" << j + 1 << " : ";
            cin >> a[i][j];
        }
    }
}
void sumDiagonals(double a[4][4])
{
    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += a[i][i];
    }
    cout << "Sum of Diagonals : " << sum << endl;
}
int main()
{
    double matA[4][4];
    input(matA);
    sumDiagonals(matA);
    system("pause");
    return 0;
}