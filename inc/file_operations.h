#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int get_num_lines(string filename);

int get_len_line(string filename, int line_number = 0);

// vector<string> split_file_by(string filename, string delimiter="\n\n");

#endif