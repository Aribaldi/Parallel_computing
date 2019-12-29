#include "task1_maxminsearch.hpp"
#include "task2_mmult.hpp"
#include "task3_mvmult.hpp"
int main() {

    Matrix A = GetRandomMatrix(100, 100);
    Matrix B = GetRandomMatrix(100, 100);
    Matrix C = GetRandomMatrix(10000, 10000);

    cout << "Task1:" << endl;
//    cout << "Input Matrix:" << endl;
//    PrintMatrix(C);
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

    cout <<"Task 3:" << endl;
    double mvtime;
    vector<int32_t> mvres;
    vector<int32_t> testv = get_random_vector(10000);

//    cout << "Input Matrix:" << endl;
//    PrintMatrix(C);
//    cout << "Input vector:" << endl;
//    print_vector(testv);

    tie(mvtime, mvres) = mvmultiply_sequential(C, testv);
    cout << "Elapsed time in sequential mode (milliseconds):" << mvtime << endl;
//    cout << "Result vector:" << endl;
//    print_vector(mvres);

    tie(mvtime, mvres) = mvmultiply_tape_rows(C, testv);
    cout << "Elapsed time in parallel by rows mode (milliseconds):" << mvtime << endl;
//    cout << "Result vector:" << endl;
//    print_vector(mvres);

    tie(mvtime, mvres) = mvmultiply_tape_cols(C, testv);
    cout << "Elapsed time in parallel by cols mode (milliseconds):" << mvtime << endl;
//    cout << "Result vector:" << endl;
//    print_vector(mvres);

    tie(mvtime, mvres) = mvmultiply_block(C, testv);
    cout << "Elapsed time in blocks mode (milliseconds):" << mvtime << endl;
//    cout << "Result vector:" << endl;
//    print_vector(mvres);

    return 0;
}
