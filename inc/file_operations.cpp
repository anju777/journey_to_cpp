#include "file_operations.h"

using namespace std;

int get_num_lines(string filename) {
    /**
     * @brief Takes in the name of a file. Returns the number of lines in that
     * file.
     *
     * @param filename File to parse.
     * @return Number of files in filename. -1 if it could not open the file.
     */
    ifstream file;
    string dummy;
    int num_lines = 0;

    file.open(filename);

    if (!file.is_open()) {
        cerr << "File " << filename << " could not open!";
        return -1;
    }

    while (getline(file, dummy)) {
        num_lines++;
    }

    return num_lines;
}


int get_len_line(string filename, int line_number) {
    /**
     * @brief Gets the length of the line at line_number
     *
     * @param filename File to parse.
     * @return Number of letters found at line number.
     */
    ifstream file;
    string line;
    int num_lines = 0;

    file.open(filename);

    if (!file.is_open()) {
        cerr << "File " << filename << " could not open!";
        return -1;
    }

    getline(file, line);
    while (num_lines != line_number) {
        getline(file, line);
    }

    return line.length();
}

string read_full_file(string filename) {
    ifstream file(filename);

    if (file.is_open()) {
        stringstream buffer;
        buffer << file.rdbuf();
        string content = buffer.str();
        return content;
    } else {
        cerr << "Unable to open file " << filename << "!\n";
        return "";
    }
}
