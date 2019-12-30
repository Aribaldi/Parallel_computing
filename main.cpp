#include "task1_maxminsearch.hpp"
#include "task2_mmult.hpp"
#include "task3_mvmult.hpp"
#include "task5_substrsearch.hpp"

int main() {

    Matrix A = GetRandomMatrix(100, 100);
    Matrix B = GetRandomMatrix(100, 100);
    Matrix C = GetRandomMatrix(5000, 5000);

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
    vector<int32_t> testv = get_random_vector(5000);

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

    cout <<"Task 5:" << endl;
    ifstream inpfile ("/home/iref/CLionProjects/Parallel_computing/task5_test.txt");
    std::string text((std::istreambuf_iterator<char>(inpfile)),
                    std::istreambuf_iterator<char>());
    string sub = "Caesar";
    vector<int32_t> pos;

    int n,m,i=0;
    int bs = text.length() / 8;
    int rem = text.length() % 8;
    int tid, start, end;
    int lenp = sub.length();
    auto time_start = high_resolution_clock::now();
    #pragma omp parallel num_threads(8) private(tid,start,end) shared(text,sub,rem,bs,m, lenp) default(none)
    {
        tid=omp_get_thread_num();

        if(tid==0)
        {
        #pragma omp critical (part1)
            {
                start=tid;
                end=bs-1;
                substringsearch_parallel(text, sub, start,end);
            }
        }
        else
        {
        #pragma omp critical (part2)
            {
                start=(tid*bs)-lenp;
                end=(tid*bs)+bs-1;
                substringsearch_parallel(text,sub,start,end);
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - time_start);
    cout << " That was simple bruteforce substring search, microseconds (parallel version):" << duration.count() << endl;
    if(rem!=0)
        substringsearch_parallel(text,sub, (9)*bs,text.length());

    auto time_start2 = high_resolution_clock::now();
    substringsearch(text, sub);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - time_start2);
    cout << "This was non parallel version; time:" << duration2.count() << endl;
    return 0;
}

