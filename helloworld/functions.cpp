#include<iostream>
using namespace std;

int sum(int x, int y)
{
    return x + y;
}

int cube_num(int num);
// Cubes provided number. i.e. returns num ^ 3

void say_hello(string name = "June");

double cube_double(double num)
{
    double ret_num = num;
    for (int i = 0; i < 3; ++i) {
        ret_num *= num;
    }
    return ret_num;
}

int main()
{
    // say_hello("Anju");
    // say_hello();
    // cout << sum(1024, 7);
    cout << cube_double(4.5);

    return 0;
}

void say_hello(string name)
{
    cout << "Hello " << name << endl;
}

int cube_num(int num)
{
    int ret_num = num;
    for (int i = 0; i < 3; ++i) {
        ret_num *= num;
    }
    return ret_num;
}