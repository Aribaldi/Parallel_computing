#include "task5_substrsearch.hpp"


void substringsearch(const string& text, const string& substr) {
    auto text_len = static_cast<int32_t>(text.length());
    auto substr_len = static_cast<int32_t>(substr.length());
    for (int i = 0; i < text_len - substr_len; ++i) {
        int32_t j;
        for (j = 0; j < substr_len; ++j) {
            if (text[i + j + 1] != substr[j])
                break;
        }
        if (j == substr_len) {
            {
                printf("found at index %d\n", i);
            }
        }
    }
}

void substringsearch_parallel(const string_view text, const string_view substr, int start, int end) {
    int i, j;
    int n = end - start + 1;
    int m  = substr.length();
    for (i = start; i <= end - m ; ++i) {
        {
            for (j = 0; j < m ; ++j) {
                if (text[i + j]!=substr[j])
                    break;
            }
            if (j == m)
            {printf("found at index %d\n", i);

            }

        }

    }
}


