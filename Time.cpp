#include <iostream>
#include <ctime>
using namespace std;
time_t mymktime(tm *timeptr, int, int, int);
char myasctime(tm *timeptr);
int main()
{

    // Reference year has been changed to 1904 as there is an anomoly in year 1900 >>>> Google indicates that there was no leap year between 1896 - 1904
    // https://www.timeanddate.com/calendar/?year=1896&country=64

    time_t rawtime;
    struct tm *timeinfo;
    struct tm *timeptr;
    int year, month, day;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;
    do
    {

        cout << "Enter day: ";
        cin >> day;
    } while (month == 2 && year % 4 != 0 && day > 28);

    time(&rawtime);
    timeptr = localtime(&rawtime);

    mymktime(timeptr, year, month, day);
    cout << "That day is a " << timeptr->tm_wday << endl;
    cout << myasctime(timeptr) << endl;
    system("pause");
    return 0;
}

char myasctime(tm *timeptr)
{
    string months[12] = {"January", "Febraury", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string weekday[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int mon;
    int weekd;
    int iyear;
    cout << "Time Is : ";
    cout << timeptr->tm_hour << " : " << timeptr->tm_min << " : " << timeptr->tm_sec << endl;
    cout << "Day Is : ";
    weekd = timeptr->tm_wday;
    for (int i = 0; i < 7; i++)
    {
        if (i == weekd)
        {
            cout << weekday[i] << endl;
        }
    }

    cout << "Month Is : ";
    mon = timeptr->tm_mon;
    for (int i = 0; i < 12; i++)
    {
        if (i == mon)
        {
            cout << months[i] << endl;
        }
    }

    cout << "Year Is : ";
    cout << timeptr->tm_year + 1904 << endl;
    return 0;
}

time_t mymktime(tm *timeptr, int year, int month, int day)
{

    timeptr->tm_year = year - 1904;
    timeptr->tm_mon = month - 1;
    timeptr->tm_mday = day;

    int w_day;
    int four_y_batchs = 0;
    int t_days;

    if (year % 4 == 0)
    {
        four_y_batchs = ((timeptr->tm_year) / 4);
        t_days = ((timeptr->tm_year) * 365) + (four_y_batchs);
    }
    else
    {
        four_y_batchs = ((timeptr->tm_year) / 4) + 1;
        t_days = ((timeptr->tm_year) * 365) + (four_y_batchs);
    }

    for (int i = 1; i <= month; i++)
    {
        if (i != month)
        {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                t_days += 31;
            }
            else if (i == 2)
            {
                if (year % 4 == 0)
                {
                    t_days += 29;
                }
                else
                {
                    t_days += 28;
                }
            }
            else if (i == 4 || i == 6 || i == 9 || i == 11)
            {
                t_days += 30;
            }
        }
        else
        {
            t_days += day;
        }
    }
    w_day = (t_days + 4) % 7;
    timeptr->tm_wday = w_day;
    return 0;
}
