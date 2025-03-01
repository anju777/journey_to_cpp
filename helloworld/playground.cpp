#include <iostream>
#include <fstream>

#include "string"

using namespace std;

void print_ascii(char c) {
    cout << "ASCII value of " << c << " is " << int(c) << endl;
}

int main() {
    print_ascii('0');
    print_ascii('9');
    print_ascii('a');
    print_ascii('f');
}