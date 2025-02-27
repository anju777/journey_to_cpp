#include "string_operations.h"

using namespace std;

void test_split_string_all() {
    vector<string> res = split_string_all("hello\n\nworld\n!");
}

int main() {

    test_split_string_all();

    return 0;
}