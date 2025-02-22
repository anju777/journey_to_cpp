#include <iostream>

using namespace std;

int main()
{
    string hello_world = "Hello world!!!";

    cout << hello_world.length() << endl;

    cout << hello_world[0] << hello_world[hello_world.length() - 1] << endl;

    hello_world[8] = 'u';
    cout << hello_world << endl;

    hello_world[8] = 'r';

    // Parameters/arguments is the input to functions
    cout << hello_world.find("Hello") << endl;
    cout << hello_world.find('o') << endl;
    cout << hello_world.find("wo") << endl;

    string substr_to_find = "world!!";
    cout << hello_world.substr(hello_world.find("wo", 0), substr_to_find.length()) << endl;

    string hello_world_substr = hello_world.substr(6, 4);
    cout << hello_world_substr << endl;

    return 0;
}