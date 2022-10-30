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
void multiplyMatrix(double a[4][4], double b[4][4])
{
    double product[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "PRODUCT : " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    double matA[4][4];
    double matB[4][4];
    input(matA);
    input(matB);
    multiplyMatrix(matA, matB);
    system("pause");
    return 0;
}