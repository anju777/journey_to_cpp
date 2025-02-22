#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    cout << "You are " << age << " years old!" << endl;

    float weight;
    cout << "What is your weight (lb)? I promise I won't save it! ";
    cin >> weight;
    cout << "You weigh " << weight - 20 << " lbs" << endl << endl;;

    string name, occupation;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your occupation: ";
    getline(cin, occupation);

    cout << "Hello " << name << "!" << endl;

    char first_letter = occupation[0];
    if (
        first_letter == 'a' || first_letter == 'e' || first_letter == 'i' ||
        first_letter == 'o' || first_letter == 'u'
    ) {
        cout << "I heard that you are an " << occupation << endl;
    } else
    {
        cout << "I heard that you are a " << occupation << endl;
    }


    // char favorite;
    // cout << "What is your favorite alphabet? ";
    // cin >> favorite;
    // cout << "~~~~ " << favorite << " ~~~~~" << endl;
    return 0;
}