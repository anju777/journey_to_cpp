#include <iostream>

using namespace std;

int main()
{
    int x;
    float y;

    // If x was an int and user inputs smth like 12.5, it freaks out and leaves
    // I think it leaves the .453 in the queue

    // So 12.345345 input would be <int> + <float> = 12.3453
    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    cout << x + y;

    return 0;
}