#include <iostream>
#include <omp.h>
#include <ctime>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int64_t **get_random_matrix(unsigned r, unsigned c) {
    int64_t **random_matrix = new int64_t *[r];
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 150.0);
    //srand(time(NULL));
    for (int64_t i = 0; i < r; ++i) {
        random_matrix[i] = new int64_t[c];
        for (int64_t j = 0; j < c; ++j) {
            random_matrix[i][j] = dist(mt);
        }

    }
    return random_matrix;
}

int main() {
    const unsigned rows = 30000;
    const unsigned cols = 30000;

    int64_t **testmat = get_random_matrix(rows, cols);


    int64_t global_maximum = -1;
    auto start = high_resolution_clock::now();
    int64_t row_minimum = INT64_MAX;
    #pragma omp_set_numthreads(4);
    #pragma omp parallel for reduction(min: row_minimum)
    for (int64_t l = 0; l < rows; ++l) {

        for (int64_t i = 0; i < cols; ++i) {
            if (testmat[l][i] < row_minimum) { row_minimum = testmat[l][i]; }
        }
        if (row_minimum > global_maximum) { global_maximum = row_minimum; }
        row_minimum = INT64_MAX;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;

//    for (int64_t i = 0; i < rows; ++i) {
//        for (int64_t j = 0; j < cols; ++j) {
//            cout << testmat[i][j] << '\t';
//        }
//        cout << '\n';
//    }

    cout << global_maximum << endl;

    for (int64_t k = 0; k < rows; ++k) {
        delete[] testmat[k];
    }
    delete[] testmat;

    return 0;
}
