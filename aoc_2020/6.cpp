#include <iostream>
#include <fstream>
#include <set>

#include "file_operations.h"
#include "string_operations.h"

using namespace std;

void solve_part_1(string filename) {
    long long sum = 0;

    string file_content = read_full_file(filename);
    vector<string> chunks = split_string_all(file_content, "\n\n");

    for (string chunk : chunks) {
        set<char> answers;

        for (char answer : chunk) {
            if (answer != '\n') {
                answers.insert(answer);
            }
        }

        sum += answers.size();
    }

    cout << "Part 1 solution for " << filename << ": " << sum << endl;
}

void solve_part_2(string filename) {
    long long sum = 0;

    string file_content = read_full_file(filename);
    vector<string> chunks = split_string_all(file_content, "\n\n");

    for (string chunk : chunks) {
        vector<string> polls = split_string_all(chunk, "\n");

        string first_answer = polls[0];
        for (int i = 0; i < first_answer.length(); i++) {
            char char_in_question = first_answer[i];
            bool ok_to_add = true;
            for (
                vector<string>::iterator other_answer = (polls.begin() + 1);
                other_answer != polls.end();
                other_answer++
            ) {
                if ((*other_answer).find(char_in_question) == string::npos) {
                    ok_to_add = false;
                }
            }

            if (ok_to_add) {
                sum++;
            }
        }
    }

    cout << "Part 2 solution for " << filename << ": " << sum << endl;
}

int main() {
    solve_part_1("6_example.txt");
    solve_part_1("6.txt");

    cout << endl;

    solve_part_2("6_example.txt");
    solve_part_2("6.txt");
    return 0;
}