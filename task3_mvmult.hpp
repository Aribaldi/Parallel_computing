#pragma once
#include "utils.hpp"

tuple<double, vector<int32_t>> mvmultiply_sequential(Matrix &matrix, vector<int32_t>&vec);
tuple<double, vector<int32_t>> mvmultiply_tape_rows(Matrix &matrix, vector<int32_t> &vec);
tuple<double, vector<int32_t>> mvmultiply_tape_cols(Matrix &matrix, vector<int32_t> &vec);
tuple<double, vector<int32_t>> mvmultiply_block(Matrix &matrix, vector<int32_t> &vec);