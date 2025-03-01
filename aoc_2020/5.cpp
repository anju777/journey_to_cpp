#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <fstream>

#include "file_operations.h"
#include "string_operations.h"

using namespace std;

long long get_seat_id(int row, int col) {
    return static_cast<long>(row * 8 + col);
}

long long parse_seat_binary(string binary) {
    string row_binary = binary.substr(0, 7);
    string col_binary = binary.substr(7, 3);

    assert(row_binary.length() == 7 && col_binary.length() == 3);

    int i = 6;
    int row = 0;
    for (char row_char : row_binary) {
        if (row_char == 'B') {
            row += pow(2, i);
        }
        i--;
    }

    i = 2;
    int col = 0;
    for (char col_char : col_binary) {
        if (col_char == 'R') {
            col += pow(2, i);
        }
        i--;
    }

    return get_seat_id(row, col);
}

long long parse_seat_binary_from_file(string filename) {
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cout << "File " << filename << " could not be read!";
    }

    string line;
    long long max_seat_id = 0;
    int i = 0;
    while (getline(file, line)) {
        long long seat_id = parse_seat_binary(line);
        max_seat_id = max(seat_id, max_seat_id);
        i++;
    }
    cout << "Total number of lines in " << filename << " = " << i << endl;

    return max_seat_id;
}

long long find_missing_seat_p2(string filename) {
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cout << "File " << filename << " could not be read!";
    }

    set<long long> boarding_passes;

    string line;
    int i = 0;
    while (getline(file, line)) {
        long long seat_id = parse_seat_binary(line);
        boarding_passes.insert(seat_id);
        i++;
    }

    long long prev_val = 0;
    long long my_seat;
    for (
        set<long long>::iterator p_curr_id = boarding_passes.begin();
        p_curr_id != boarding_passes.end();
        p_curr_id++
    ) {
        if (prev_val == 0) {
            prev_val = *p_curr_id;
            continue;
        }

        if (prev_val + 1 != *p_curr_id) {
            my_seat = prev_val + 1;
        }
        prev_val = *p_curr_id;
    }

    return my_seat;
}

int main() {
    cout << "Part 1: " << endl;
    cout << parse_seat_binary("FBFBBFFRLR") << endl;
    cout << parse_seat_binary("BFFFBBFRRR") << endl;
    cout << parse_seat_binary("FFFBBBFRRR") << endl;
    cout << parse_seat_binary("BBFFBBFRLL") << endl;

    cout << "Part 1 answer: " << parse_seat_binary_from_file("5.txt") << endl;

    cout << "Part 2 answer: " << find_missing_seat_p2("5.txt") << endl;
    return 0;
}