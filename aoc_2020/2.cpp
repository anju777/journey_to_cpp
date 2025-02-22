#include <cassert>
#include <iostream>
#include <fstream>

#include "file_operations.h"
#include "string_operations.h"

class Rule {
    public:
        char pass_char;
        int lower_limit;
        int upper_limit;

        void register_rule(string raw_rule) {
            // Should split into "1-3", "a"
            _raw_rule = raw_rule;
            string *split = split_string(raw_rule);
            raw_count = split[0];

            // Isolate out the character in question
            assert (split[1].size() == 1);
            pass_char = split[1][0];

            // Isolate out the counts
            split = split_string(raw_count, '-');
            lower_limit = stoi(split[0]);
            upper_limit = stoi(split[1]);
        }

    private:
        string _raw_rule;
        string raw_count;
};

class ParsedLine {
    public:
        Rule rule;
        string password;

        void parse_line(string line) {
            _line = line;
            string* split = split_string(line, ':');
            raw_rule = strip(split[0]);
            rule.register_rule(raw_rule);
            password = strip(split[1]);
        }

    private:
        string _line;
        string raw_rule;
};

/**
 * @brief Returns whether a password is valid based on the provided rule
 *
 * @param rule Rule to use to evaluate the password
 * @param password Password string to evaluate
 * @return true if the password is valid
 * @return false if the password is invalid
 */
bool is_valid_password(Rule rule, string password) {
    int target_count = count_char(password, rule.pass_char);
    return (
        (rule.lower_limit <= target_count) && (target_count <= rule.upper_limit)
    );
}

bool is_valid_password_2(Rule rule, string password) {
    int count_match = 0;
    char first_occurrence = password[rule.lower_limit - 1];
    char second_occurrence = password[rule.upper_limit - 1];

    if (rule.lower_limit >= 1 && first_occurrence == rule.pass_char) {
        count_match++;
    }
    if (rule.upper_limit <= password.length() && second_occurrence == rule.pass_char) {
        count_match++;
    }

    bool is_valid = (count_match == 1);
    return is_valid;
}

int solve_puzzle(
    string filename,
    bool (*valid_password_fn)(Rule, string) = is_valid_password
) {
    // Open file
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        // Exit a function with an error message if the file did not open.
        cerr << "File '" << filename << "' could not open!" << endl;
        return -1;
    }

    // Declare variables
    int valid_passwords = 0;
    string line;
    ParsedLine parsed_line;

    // Iterate through lines and evaluate
    while (getline(file, line)) {
        parsed_line.parse_line(line);

        if (valid_password_fn(parsed_line.rule, parsed_line.password)) {
            valid_passwords++;
        }
    }

    return valid_passwords;
}

int main() {
    int example_res, actual_res;

    // example_res = solve_puzzle("2_example.txt");
    // cout << "Part 1 Example: " << example_res << endl;

    // actual_res = solve_puzzle("2.txt");
    // cout << "Part 1 Actual: " << solve_puzzle("2.txt") << endl << endl;

    // Part 2
    example_res = solve_puzzle("2_example.txt", is_valid_password_2);
    cout << "Part 2 Example: " << example_res << endl << endl;

    actual_res = solve_puzzle("2.txt", is_valid_password_2);
    cout << "Part 2 Actual: " << actual_res << endl;

    // 622 - TOO HIGH

    return 0;
}