#pragma once

#include "computable.h"

template<typename T>
class JacobiMatrix : public Computable::Matrix<T> {
public:
    JacobiMatrix() : Computable::Matrix<T>() {};
    JacobiMatrix(size_t height, size_t width, int n_iter) :
        Computable::Matrix<T> (height, width), n_iter(n_iter) {};
    Computable::Result compute();
private:
    int n_iter;
};
