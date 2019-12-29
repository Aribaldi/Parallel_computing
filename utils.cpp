#include "utils.hpp"

Matrix GetRandomMatrix(size_t rows, size_t cols) {
    std::random_device dev;
    std::mt19937       rng(dev());

    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 25);

    Matrix matrix{rows};

    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = std::vector<int32_t>(cols);
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] = static_cast<int>(dist(rng));
        }
    }

    return matrix;
}

void PrintMatrix(const Matrix &matrix) {
    auto rows = matrix.size();
    auto cols = matrix.begin()->size();
    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < cols; ++j) {
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    };
}

Matrix GetZeroMatrix(size_t rows, size_t cols) {
    Matrix matrix{rows};

    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = std::vector<int32_t>(cols);
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] =0;
        }
    }
    return matrix;
}

vector<int32_t> get_random_vector(size_t cols) {
    std::random_device dev;
    std::mt19937       rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 500);
    vector<int32_t> vec(cols, 0);
    for (size_t i = 0; i < cols; ++i)
    {
        vec[i] = static_cast<int>(dist(rng));
    }
    return vec;
}

void print_vector(const vector<int32_t> &vector) {
    auto cols = vector.size();
    for (int32_t i = 0; i < cols; ++i) {
            cout << vector[i] << '\n';
        }
}



