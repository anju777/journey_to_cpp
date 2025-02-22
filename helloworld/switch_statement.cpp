#include <iostream>

using namespace std;

string get_day_of_week(int day_num)
{
    day_num %= 7;
    string day_name;
    switch (day_num)
    {
    case 0:
        cout << "Passing case 0" << endl;
        day_name = "Sunday";
        break;
    case 1:
        day_name = "Monday";
        break;
    case 2:
        day_name = "Tuesday";
        break;
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    case 7:
        return "Sunday";
    default:
        cout << "Passing default" << endl;
        day_name = "unknown";
        break;
    }

    return day_name;
}

int main()
{
    cout << get_day_of_week(9);
    return 0;
}