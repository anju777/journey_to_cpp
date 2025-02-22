#include <iostream>

using namespace std;

int main() {
    int new_array[3][2] = {
        {1, 2},
        {3, 4},
        {5, 43}
    };
    int x = 3;
    char y = '3';

    /*
    Long comment...
    */
    cout << &y << endl;
    cout << *&*&x << endl;

    std::string message = "hello, world";

    cout << message;

    string m = "hello!";
    cout << m;

    cout << static_cast<char>(new_array[2][1]) << endl;
    return 0;
}