#include <iostream>

using namespace std;

int main() {
    string color, plural_noun, celebrity;

    cout << "Enter a color: ";
    getline(cin, color);

    cout << "Enter a plural noun: ";
    getline(cin, plural_noun);
    cout << "Enter a celebrity: ";
    getline(cin, celebrity);

    cout << "Roses are " << color << endl;
    cout << plural_noun << " are blue" << endl;
    cout << "I love " << celebrity << endl;
}