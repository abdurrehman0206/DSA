#include <iostream>
using namespace std;

class Cube
{
    int length;

public:
    Cube() : length(0){};
    void setLength()
    {
        cout << "Input Lenght : ";
        cin >> length;
    }
    void calcArea()
    {
        int surfaceArea = 0;
        surfaceArea = 6 * length * length;
        cout << "Surface Area : " << surfaceArea << endl;
    }
    void calcVolume()
    {
        int volume = 0;
        volume = length * length * length;
        cout << "Volume : " << volume << endl;
    }
};
int main()
{
    Cube c;
    c.setLength();
    c.calcArea();
    c.calcVolume();
    system("pause");
    return 0;
}