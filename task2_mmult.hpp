#pragma once
#include "utils.hpp"

tuple<double, Matrix> matrixmultiply_sequantial(const Matrix &first, const Matrix &second);
tuple<double, Matrix> matrixmultiply_parallel(const Matrix &first, Matrix &second);
