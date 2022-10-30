#include <iostream>
using namespace std;
struct Time
{
    int hour;
    int minute;
    int second;
};
int main()
{
    Time t1;
    int totalSeconds = 0;
    cout << "Enter hour : ";
    cin >> t1.hour;
    cout << "Enter minutes : ";
    cin >> t1.minute;
    cout << "Enter seconds : ";
    cin >> t1.second;
    cout << "Time :: " << t1.hour << ":" << t1.minute << ":" << t1.second << endl;
    totalSeconds = (t1.hour * 3600) + (t1.minute * 60) + t1.second;
    cout << "Total Seconds :: " << totalSeconds << endl;

    system("pause");
    return 0;
}