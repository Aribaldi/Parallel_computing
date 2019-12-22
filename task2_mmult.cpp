#include "task2_mmult.hpp"

tuple<double, Matrix> matrixmultiply_sequantial(const Matrix &first, const Matrix &second){
    Matrix result_matrix = GetZeroMatrix(first.size(), second.begin()->size());
    auto start = high_resolution_clock::now();
    for (int i = 0; i < first.size(); ++i) {
        for (int j = 0; j < second.begin()->size() ; ++j) {
            for (int k = 0; k < first.begin()->size() ; ++k) {
                result_matrix[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return make_tuple(duration.count(), result_matrix);
}

tuple<double, Matrix> matrixmultiply_parallel(const Matrix &first, Matrix &second){
    Matrix result_matrix = GetZeroMatrix(first.size(), second.begin()->size());
    auto start = high_resolution_clock::now();
    omp_set_num_threads(8);
    int i, j, k;
    #pragma omp parallel for shared(first, second, result_matrix) private(i, j, k)  default(none)
        for (i = 0; i < first.size(); ++i) {
            for (j = 0; j < second.begin()->size() ; ++j) {
                for (k = 0; k < first.begin()->size() ; ++k) {
                    result_matrix[i][j] += first[i][k] * second[k][j];
                }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return make_tuple(duration.count(), result_matrix);
}
