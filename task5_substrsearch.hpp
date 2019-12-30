#pragma once
#include "utils.hpp"

void substringsearch (const string& text, const string& substr);
void substringsearch_parallel(const string_view text, const string_view substr, int start, int end);

