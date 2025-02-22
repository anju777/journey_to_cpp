#include <iostream>

using namespace std;

int main()
{
    cout << -40.23243 << endl;

    cout << 5 - 7 << endl;

    cout << 10 % 4 << endl;

    // Order of operations: PEMDAS
    cout << (4  + 5) * 10 << endl;

    int num = 5;
    double dnum = 5.5;

    cout << dnum << endl;

    cout << "Number was " << num << endl;
    num++;
    cout << "-> num++; Number now is " << num << endl;

    num--;
    num /= 2;
    cout << "Number now is " << num << endl;

    cout << "<int> / <int> = <int>: 7/3 = " << 7 / 3 << endl;
    cout << "<int> / <float> = <float>: 7/3.0 = " << 7 / 3.0 << endl;
    cout << "<float> / <int> = <float>: 3.0/2 = " << 3.0 / 2 << endl;

    // <float> + <int> = <float>
    cout << 5.5 + 9;
}