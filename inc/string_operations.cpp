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

vector<string> split_string_all(string text, string delimiter) {
    /**
     * @brief Splits the provided string into a vector based on all delimiters.
     *
     * If the string starts with a delimiter, the vector will contain an empty
     * string at the beginning. Similarly, when there are two delimiters
     * consecutive to each other, the empty vector will be pushed in.
     */

    vector<string> split_vector;

    size_t delimiter_len = delimiter.length();
    size_t text_len = text.length();

    if (delimiter_len > text_len) {
        split_vector.push_back(text);
    }

    int bookmark = 0;
    int i = 0;
    while (i <= (text_len - delimiter_len)) {
        assert(text.substr(i, delimiter_len).length() == delimiter_len);
        if (text.substr(i, delimiter_len) == delimiter) {
            split_vector.push_back(text.substr(bookmark, i - bookmark));

            // Skip delimiter
            i += delimiter_len;
            bookmark = i;
        }
        i++;
    }

    // Add last chunk
    if (text.substr(bookmark, text_len).length() != 0) {
        split_vector.push_back(text.substr(bookmark));
    }

    return split_vector;
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
