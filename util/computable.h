#pragma once

#include <cstdlib>
#include <vector>

namespace Computable {

struct Result {
    size_t size;
    void * data;
};

template <typename T>
class Matrix {
 public:
    Matrix(size_t height, size_t width) : height(height), width(width) {};
    Matrix() = default;
    ~Matrix() = default;
    size_t size() const;
    bool initialize(std::vector<T>); // True if success
    virtual Result compute();

 protected:
    size_t height, width;
    bool init = false;
    std::vector<T> data;

 public:
    T& operator()(size_t i, size_t j) {
        return data[i*width + j];
    }
    const T& at(size_t i, size_t j) {
        return data.at(i*width + j);
    }

};


}
