#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int get_num_lines(string filename);

int get_len_line(string filename, int line_number = 0);

string read_full_file(string filename);

#endif