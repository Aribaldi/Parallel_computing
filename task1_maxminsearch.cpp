#include <omp.h>
#include "utils.hpp"


int main() {
    const unsigned rows = 15000;
    const unsigned cols = 15000;

    Matrix testmat = GetRandomMatrix(rows, cols);
    int32_t global_maximum = -1;
    auto start = high_resolution_clock::now();
    int32_t row_minimum = INT32_MAX;
    omp_set_num_threads(4);
    #pragma omp_schedule(auto)
    #pragma omp parallel for shared(testmat) firstprivate(row_minimum) default(none) reduction(max: global_maximum)
    for (int32_t l = 0; l < rows; ++l) {
        for (int32_t i = 0; i < cols; ++i) {
            if (testmat[l][i] < row_minimum) { row_minimum = testmat[l][i]; }
        }
        if (row_minimum > global_maximum) { global_maximum = row_minimum; }
        row_minimum = INT32_MAX;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Elapsed time (milliseconds):" << duration.count() << endl;


    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < cols; ++j) {
            cout << testmat[i][j] << '\t';
        }
        cout << '\n';
    }

//    cout << "Maximum of minimums:" << global_maximum << endl;
//
//    for (int32_t k = 0; k < rows; ++k) {
//        delete[] testmat[k];
//    }
//    delete[] testmat;
//
//    return 0;
//}
