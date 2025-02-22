#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 10;

    // converting int to double
    double nd = static_cast<double>(n);

    // printing data type
    cout << typeid(n).name() << endl;

    // typecasting
    cout << typeid(static_cast<double>(n)).name() << endl;

    // Printing double type
    cout << typeid(nd).name();

    return 0;
}