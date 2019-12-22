#include "task1_maxminsearch.hpp"

tuple<double, int32_t> getmaxmin (Matrix &testmat) {
    auto start = high_resolution_clock::now();
    int32_t global_maximum = -1;
    int32_t row_minimum = INT32_MAX;
    omp_set_num_threads(4);
    #pragma omp_schedule(auto)
    #pragma omp parallel for shared(testmat) firstprivate(row_minimum) default(none) reduction(max: global_maximum)
    for (int32_t l = 0; l < testmat.size(); ++l) {
        for (int32_t i = 0; i < testmat.begin()->size(); ++i) {
            if (testmat[l][i] < row_minimum) { row_minimum = testmat[l][i]; }
        }
        if (row_minimum > global_maximum) { global_maximum = row_minimum; }
        row_minimum = INT32_MAX;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return make_tuple(duration.count(), global_maximum);
}