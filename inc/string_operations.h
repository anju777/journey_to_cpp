#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <iostream>

using namespace std;

string* split_string(string text, char delimiter = ' ');

string strip(string text, char delimiter = ' ');

int count_char(string text, char target);

#endif