nt bookmark = 0;
    // for (int i = 0; i < (text_len - delimiter_len); i++) {
    //     assert(text.substr(i, i + delimiter_len - 1).length() == delimiter_len);
    //     if (text.substr(i, i + delimiter_len - 1) == delimiter) {
    //         split_vector.push_back(text.substr(bookmark, i));

    //         // Skip delimiter
    //         i += delimiter_len;
    //         bookmark = i;
    //     }
    // }

    // // Add last chunk
    // if (text.substr(bookmark, text_len).length() != 0) {
    //     split_vector.push_back(text.substr(bookmark, text_len));
    // }