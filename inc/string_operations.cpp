#include "string_operations.h"

using namespace std;

string* split_string(string text, char delimiter) {
    /**
     * @brief Splits the provided string into two based on the delimiter.
     * Will split on the FIRST appearance of the delimiter. If there are
     * multiple, the rest would be ignored.
     *
     */
    string* split = new string[2];
    split[0] = "";
    split[1] = "";

    int i = 0;
    while (text[i] != delimiter && i < text.length()) {
        split[0] += text[i];
        i++;
    }

    // Skip the delimiter
    i++;

    while (i < text.length()) {
        split[1] += text[i];
        i++;
    }

    return split;
}

string strip(string text, char delimiter) {
    /**
     * @brief Takes in text. Strips the delimiter from the front and back of the
     * string. Delimiter defaults to space if not provided.
     *
     * ex)
     *      strip("hello") = "hello";
     *      strip("     hello") = "hello";
     *      strip("   hello   ") = "hello";
     */
    int start_strip = 0;
    int end_strip = 0;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] != delimiter) {
            break;
        }
        start_strip++;
    }

    for (int i = text.length() - 1; i > start_strip; i--) {
        if (text[i] != delimiter) {
            break;
        }
        end_strip++;
    }

    return text.substr(start_strip, text.size() - start_strip - end_strip);
}

/**
 * @brief Counts the number of times target appears in text.
 *
 */
int count_char(string text, char target) {
    int count = 0;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == target) {
            count++;
        }
    }

    return count;
}