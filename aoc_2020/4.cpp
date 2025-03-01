#include <assert.h>

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <sstream>
#include <vector>

#include "file_operations.h"
#include "string_operations.h"

using namespace std;

// /**
//  * @brief Keywords:
//  * byr (Birth Year)
//  * iyr (Issue Year)
//  * eyr (Expiration Year)
//  * hgt (Height)
//  * hcl (Hair Color)
//  * ecl (Eye Color)
//  * pid (Passport ID)
//  * cid (Country ID) - optional (for part 1)
//  */

int solve_part_1(string filename) {
    ifstream file;
    file.open(filename);

    int num_valid = 0;
    set<string> passport_solution_set = {
        "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"
    };

    if (!file.is_open()) {
        cerr << "File " << filename << "could not open!\n";
        return -1;
    }

    stringstream buffer;

    buffer << file.rdbuf();
    string content = buffer.str();

    vector<string> chunks = split_string_all(content, "\n\n");

    for (size_t i = 0; i < chunks.size(); i++) {
        string chunk = chunks[i];
        set<string> curr_set;

        string* split;
        split = split_string(chunk, ':');
        while (split[1].length() != 0) {
            string candidate = split[0];
            candidate = candidate.substr(candidate.length() - 3, 3);
            if (passport_solution_set.find(candidate) != passport_solution_set.end()) {
                curr_set.insert(candidate);
            }

            split = split_string(split[1], ':');
        }

        if (curr_set == passport_solution_set) {
            num_valid++;
        }
    }

    file.close();

    cout << filename << ": Number of valid passports = " << num_valid << endl;

    return num_valid;
}

void solve_part_2(string filename) {
    ifstream file;
    file.open(filename);

    int num_valid = 0;
    set<string> passport_solution_set = {
        "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"
    };
    set<string> allowed_eye_colors = {
        "amb", "blu", "brn", "gry", "grn", "hzl", "oth"
    };

    if (!file.is_open()) {
        cerr << "File " << filename << "could not open!\n";
        return;
    }

    stringstream buffer;

    buffer << file.rdbuf();
    string content = buffer.str();

    vector<string> chunks = split_string_all(content, "\n\n");

    for (size_t i = 0; i < chunks.size(); i++) {
        string chunk = chunks[i];
        bool is_valid = true;  // Whether the criteria meets
        set<string> curr_set;

        chunk = replace_all(chunk, "\n", " ");

        string* split;
        split = split_string(chunk, ':');
        while (split[1].length() != 0) {
            if (!is_valid) {
                break;
            }

            string candidate = split[0];
            string value = split_string(strip(split[1]), ' ')[0];

            candidate = candidate.substr(candidate.length() - 3, 3);
            if (passport_solution_set.find(candidate) != passport_solution_set.end()) {
                curr_set.insert(candidate);

                // Check validity
                if (candidate == "byr") {
                    // 1920 <= byr <= 2002
                    if (value.length() != 4) {
                        is_valid = false;
                    }
                    if (stoi(value) < 1920 || stoi(value) > 2002) {
                        is_valid = false;
                    }
                } else if (candidate == "iyr") {
                    // 2010 <= iyr <= 2020
                    if (value.length() != 4) {
                        is_valid = false;
                    }
                    if (stoi(value) < 2010 || stoi(value) > 2020) {
                        is_valid = false;
                    }
                } else if (candidate == "eyr") {
                    // 2020 <= eyr <= 2030
                    if (value.length() != 4) {
                        is_valid = false;
                    }
                    if (stoi(value) < 2020 || stoi(value) > 2030) {
                        is_valid = false;
                    }
                } else if (candidate == "hgt") {
                    // 150 <= cm <= 193
                    // 59 <= in <= 76
                    size_t cm_loc = value.find("cm");
                    size_t in_loc = value.find("in");
                    if (cm_loc != string::npos) {
                        // is cm
                        int cm_height = stoi(value.substr(0, cm_loc));
                        if (cm_height < 150 || cm_height > 193) {
                            is_valid = false;
                        }
                    } else if (in_loc != string::npos) {
                        // is in
                        int in_height = stoi(value.substr(0, in_loc));
                        if (in_height < 59 || in_height > 76) {
                            is_valid = false;
                        }
                    } else {
                        is_valid = false;
                    }
                } else if (candidate == "hcl") {
                    if ((value.length() != 7) || (value[0] != '#')) {
                        is_valid = false;
                    }

                    string color = value.substr(1, 6);
                    for (char c : color) {
                        if (!is_digit(c) && !is_hex(c)) {
                            is_valid = false;
                        }
                    }
                } else if (candidate == "ecl") {
                    // in {amb, blu, brn, gry, grn, hzl, oth}
                    if (allowed_eye_colors.find(value) == allowed_eye_colors.end()) {
                        is_valid = false;
                    }
                } else if (candidate == "pid") {
                    // 9-digit number
                    if (value.length() != 9) {
                        is_valid = false;
                    }
                    try {
                        stoi(value);
                    } catch (exception &err) {
                        is_valid = false;
                    }
                }
            }

            split = split_string(split[1], ':');
        }

        if (curr_set == passport_solution_set && is_valid) {
            num_valid++;
        }
    }

    file.close();

    cout << filename << ": Number of valid passports = " << num_valid << endl;
}

int main() {
    cout << "Part 1:" << endl;
    solve_part_1("4_example.txt");
    solve_part_1("4.txt");

    cout << endl;
    cout << "Part 2:" << endl;
    solve_part_2("4_valid_passports.txt");
    solve_part_2("4_invalid_passports.txt");
    solve_part_2("4.txt");
    return 0;
}