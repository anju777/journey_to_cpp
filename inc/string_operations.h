#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <assert.h>

#include <iostream>
#include <vector>

using namespace std;

string* split_string(string text, char delimiter = ' ');

vector<string> split_string_all(string text, string delimiter = "\n");

string strip(string text, char delimiter = ' ');

int count_char(string text, char target);

string replace_all(string text, string to_replace, string replace_with);

bool is_digit(char c);

bool is_hex(char c);

#endif