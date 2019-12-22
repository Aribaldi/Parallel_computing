#include "task1_maxminsearch.hpp"
#include "task2_mmult.hpp"
int main() {

    Matrix A = GetRandomMatrix(500, 500);
    Matrix B = GetRandomMatrix(500, 500);
    Matrix C = GetRandomMatrix(5, 5);

    cout << "Task1:" << endl;
    cout << "Input Matrix:" << endl;
    PrintMatrix(C);
    double time;
    int32_t maxmin;
    tie(time, maxmin) = getmaxmin(C);
    cout << "Elapsed time (milliseconds):" << time << endl;
    cout << "Maximum of minimums:" << maxmin << endl;

    cout <<"Task 2:" << endl;

//    cout << "Matrix A:" << endl;
//    PrintMatrix(A);

//    cout << "Matrix B:" << endl;
//    PrintMatrix(B);

    double sequantial_time, parallel_time;
    Matrix res;
    tie(sequantial_time, res) = matrixmultiply_sequantial(A, B);
    cout << "Elapsed time in sequantial mode (milliseconds):" << sequantial_time << endl;
    //cout << "Result:" << endl;
    //PrintMatrix(res);
    tie(parallel_time, res) = matrixmultiply_parallel(A, B);
    cout << "Elapsed time in parallel mode (milliseconds):" << parallel_time << endl;
    //cout << "Result:" << endl;
    //PrintMatrix(res);

    return 0;
}
