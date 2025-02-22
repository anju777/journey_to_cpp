#include <iostream>
using namespace std;
// MINE: namespace is like global/local variables

int main() {
    // Declare a variable
    int var;

    // Assign a number
    var = 100;

    // Print out the number
    cout << var;
    cout << "\n\n";

    // Other types of variables
    float var_float;
    var_float = 3.1415;
    cout << "Do you want to eat ";
    cout << var_float;
    cout << "?\n\n";

    char var_char = 'x';
    cout << var_char;
    cout << " <- I should be a char!\n\n";

    bool var_bool = true;
    cout << "You're rocking c++: ";
    cout << var_bool << endl << endl;

    // var_string is called an "identifier"
    string var_string = "Finally a string!\n\n";
    cout << var_string;

    int num1 = 10, num2 = 20;
    cout << "I am the sum of 2 numbers: ";
    cout << num1 + num2 << endl << endl;

    // extern int new_var;
    // MINE: extern can be used to declare a variable (won't allocte memory)

    int new_var;
    // Memory is allocated here!!

    new_var = 15;
    // Memory is now allocated.

    return 0;
}