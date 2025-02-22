#include <iostream>
#include <fstream>
#include <string>

#include "file_operations.h"

using namespace std;

const int target = 2020;

int solve_puzzle(string filename) {
    ifstream input_file;
    int num_lines;
    string line;

    num_lines = get_num_lines(filename);
    int numbers[num_lines];

    input_file.open(filename);

    if (!input_file.is_open()) {
        // Return if file is not open
        cerr << "Error opening the file " << filename << "!" << endl;
        return 1;
    }

    int i = 0;
    // Make numbers list
    while (getline(input_file, line)) {
        numbers[i] = stoi(line);
        i++;
    }

    // Close file. This is not needed anymore
    input_file.close();

    // Loop through numbers until desired is found
    for (i = 0; i < num_lines; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (numbers[i] + numbers[j] == target) {
                return numbers[i] * numbers[j];
            }
        }
    }

    return 0;
}

int solve_puzzle_2(string filename) {
    ifstream input_file;
    int num_lines;
    string line;

    num_lines = get_num_lines(filename);
    int numbers[num_lines];

    input_file.open(filename);

    if (!input_file.is_open()) {
        // Return if file is not open
        cerr << "Error opening the file " << filename << "!" << endl;
        return 1;
    }

    int i = 0;
    // Make numbers list
    while (getline(input_file, line)) {
        numbers[i] = stoi(line);
        i++;
    }

    // Close file. This is not needed anymore
    input_file.close();

    int first_num, second_num, third_num;
    // Loop through numbers until desired is found
    for (i = 0; i < num_lines; i++) {
        first_num = numbers[i];

        if (first_num > target) {
            continue;
        }

        for (int j = i + 1; j < num_lines; j++) {
            second_num = numbers[j];

            if (first_num + second_num > target) {
                continue;
            }

            for (int z = j + 1; z < num_lines; z++) {
                third_num = numbers[z];
                if (first_num + second_num + third_num == target) {
                    return first_num * second_num * third_num;
                }
            }
        }
    }

    return 0;
}

int main() {
    ifstream inputFile;

    cout << "\nPart 1:\n";
    cout << "Example: " << solve_puzzle("1_example.txt") << endl;
    cout << "Actual: " << solve_puzzle("1.txt") << endl;

    cout << "\nPart 2:\n";
    cout << "Example: " << solve_puzzle_2("1_example.txt") << endl;
    cout << "Actual: " << solve_puzzle_2("1.txt") << endl;

    return 0;
}