#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int heights[20];

    int lucky_nums[] = {1, 2, 4, 8, 16};

    cout << lucky_nums[2] << endl;

    lucky_nums[29] = 7;
    cout << "Changed 2nd element to 7 -> " << lucky_nums[2] << endl;

    return 0;
}