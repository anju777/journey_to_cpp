#include <assert.h>

#include <iostream>
#include <fstream>
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

// void solve_part_1(string filename) {
//     ifstream file;
//     file.open(filename);

//     if (!file.is_open()) {
//         cerr << "File " << filename << "could not open!\n";
//         return;
//     }

//     stringstream buffer;

//     buffer << file.rdbuf();
//     string content = buffer.str();
//     cout << content;

//     file.close();
// }

// void solve_part_2(string filename) {

// }

int main() {
//     cout << "Part 1:" << endl;
//     solve_part_1("4_example.txt");
//     solve_part_1("4.txt");

//     cout << "Part 2:" << endl;
//     solve_part_2("4_example.txt");
//     solve_part_2("4.txt");
//     return 0;
    vector<string> message = split_string_all("Iheartloveheartyou!heart", "heart");
    return 0;
}