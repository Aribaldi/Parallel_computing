//
// Created by aribaldi on 12/23/19.
//

#include "task3_mvmult.hpp"

tuple<double, vector<int32_t>> mvmultiply_sequential(Matrix &matrix, vector<int32_t> &vec) {
    std::vector<int32_t> res(matrix.size(), 0);
    auto start = high_resolution_clock::now();
    for (int i = 0; i < matrix.size() ; ++i) {
        for (int j = 0; j < vec.size() ; ++j) {
            res[i] += matrix[i][j] * vec[j];
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return make_tuple(duration.count(), res);
}

tuple<double, vector<int32_t>> mvmultiply_tape_rows(Matrix &matrix, vector<int32_t> &vec) {
    std::vector<int32_t> res(matrix.size(), 0);
    auto start = high_resolution_clock::now();
    int i, j;
    #pragma omp parallel for default(none) shared(i, matrix, vec, res) private(j) num_threads(4)
        for (i = 0; i < matrix.size() ; ++i) {
            for (j = 0; j < vec.size() ; ++j) {
                res[i] += matrix[i][j] * vec[j];
            }
        }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return make_tuple(duration.count(), res);
}

tuple<double, vector<int32_t>> mvmultiply_tape_cols(Matrix &matrix, vector<int32_t> &vec) {
    std::vector<int32_t> res(matrix.size(), 0);
    auto start = high_resolution_clock::now();
    int i, j;
    #pragma omp parallel for default(none) shared(j, matrix, vec, res) private(i) num_threads(4)
    for (i = 0; i < matrix.size() ; ++i) {
        for (j = 0; j < vec.size() ; ++j) {
            res[i] += matrix[i][j] * vec[j];
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return make_tuple(duration.count(), res);
}

tuple<double, vector<int32_t>> mvmultiply_block(Matrix &matrix, vector<int32_t> &vec) {
    std::vector<int32_t> res(matrix.size(), 0);
    auto start = high_resolution_clock::now();
    int i, j;
    #pragma omp parallel default(none) shared(matrix, vec, res) private(i, j) num_threads(4)
    {
        int32_t s  = omp_get_num_threads();
        int32_t h = static_cast<int32_t>(matrix.size() / s);
        int32_t w = static_cast<int32_t>(matrix.begin()->size() / s);

        #pragma omp for
        for (int b = 0; b < s * s ; ++b) {
            i = b / s;
            j = b % s;
            for (int k = i * h; k < (i + 1) * h ; ++k) {
                for (int l = j * w; l < (j + 1) * w ; ++l) {
                    res[k] += matrix[k][l] * vec[l];
                }
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return make_tuple(duration.count(), res);
}




