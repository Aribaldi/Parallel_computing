#pragma once

#include <omp.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using namespace std::chrono;
using Matrix = std::vector<std::vector<int32_t>>;

Matrix GetRandomMatrix(size_t rows, size_t cols);
void PrintMatrix(const Matrix& matrix);
Matrix GetZeroMatrix(size_t rows, size_t cols);
vector<int32_t> get_random_vector(size_t cols);
void print_vector(const vector<int32_t> &vector);
