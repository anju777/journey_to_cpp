#include <assert.h>

#include <iostream>
#include <fstream>

#include "file_operations.h"
#include "string_operations.h"

using namespace std;

class SkiCourse {
    public:
        int m_row;
        int m_col;
        int curr_col;
        int num_trees;

        void register_pattern(int row, int col) {
            m_row = row;
            m_col = col;
        }

        SkiCourse() {
            curr_col = 0;
            num_trees = 0;
        }
};

// Move = RIGHT 3, DOWN 1

void solve_part_1(string filename) {
    ifstream file;
    string line;

    file.open(filename);

    if (!file.is_open()) {
        cerr << "File " << filename << " could not open!";
        return;
    }

    int num_trees = 0;
    int line_len = get_len_line(filename);
    int curr_col = 0;

    while (getline(file, line)) {
        char curr_spot = line[curr_col];
        if (curr_spot == '#') {
            num_trees += 1;
        } else {
            assert(curr_spot == '.');
        }

        curr_col = (curr_col + 3) % line_len;
    }
    cout << "File " << filename << " result: " << num_trees << endl;
}

/**
 * @brief Slopes to traverse. Multiply the results.
 * Right 1, down 1.
 * Right 3, down 1. (This is the slope you already checked.)
 * Right 5, down 1.
 * Right 7, down 1.
 * Right 1, down 2.
 *
 * @param filename
 */
void solve_part_2(string filename) {
    int num_ski_patterns = 5;

    SkiCourse ski_courses[num_ski_patterns];
    for (int i = 0; i < num_ski_patterns; i++) {
        // Fill ski_course
        SkiCourse ski_course;
        ski_courses[i] = ski_course;
    }

    ski_courses[0].register_pattern(1, 1);
    ski_courses[1].register_pattern(1, 3);
    ski_courses[2].register_pattern(1, 5);
    ski_courses[3].register_pattern(1, 7);
    ski_courses[4].register_pattern(2, 1);

    ifstream file;
    string line;

    file.open(filename);

    if (!file.is_open()) {
        cerr << "File " << filename << " could not open!";
        return;
    }

    const int line_len = get_len_line(filename);
    int curr_row = 0;
    char curr_spot;

    int i = 0;
    SkiCourse& ski_course = ski_courses[i];
    cout << endl <<  &ski_course << " <- address of ski_course reference (" << &(ski_course.num_trees) << ")\n";
    cout << &ski_courses[i] << " <- address of ski_courses element (" << &(ski_courses[i].num_trees) << ")\n";
    SkiCourse ski_course_var = ski_courses[i];
    cout << &ski_course_var << " <- address of new ski_course variable (" << &(ski_course_var.num_trees) << ")\n";
    SkiCourse* p_ski_course = &ski_courses[i];
    cout << p_ski_course << " <- Ski course pointer (" << &(p_ski_course->num_trees) << ")\n";


    while (getline(file, line)) {
        for (int i = 0; i < num_ski_patterns; i++) {
            SkiCourse &ski_course = ski_courses[i];

            if (curr_row % ski_course.m_row == 0) {
                curr_spot = line[ski_course.curr_col];

                if (curr_spot == '#') {
                    // cout << "Ski course " << i << " saw a tree at row " << curr_row << " and col " << ski_course.curr_col << endl;
                    ski_course.num_trees += 1;
                } else {
                    assert(curr_spot == '.');
                }

                ski_course.curr_col = (ski_course.curr_col + ski_course.m_col) % line_len;
            }
        }

        curr_row++;
    }

    long long product = 1;
    int int_product = 1;
    cout << "Size of long " << sizeof(product) << endl;
    cout << "Size of int " << sizeof(int_product) << endl;
    for (int i = 0; i < num_ski_patterns; i++) {
        SkiCourse& ski_course = ski_courses[i];
        product *= ski_course.num_trees;
    }
    cout << filename << "result: " << product << endl;
}

int main() {
    string example = "3_example.txt";
    string actual = "3.txt";

    cout << "Part 1:" << endl;
    solve_part_1(example);
    solve_part_1(actual);

    cout << endl << "Part 2:" << endl;

    solve_part_2(example);
    solve_part_2(actual);
    // 1479596954: too low -> this was in int and it overflowed!!
    return 0;
}