#ifndef VECTORGENERATOR_H
#define VECTORGENERATOR_H

#include <vector>
#include <cstdlib>
#include <ctime>


template <typename T>
std::vector<T> generateRandomVector(size_t n) {
    std::vector<T> result;
    result.reserve(n);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (size_t i = 0; i < n; ++i) result.push_back(std::rand());
    return result;
}


template <typename T>
std::vector<T> generateSortedVector(size_t n) {
    std::vector<T> result(n);
    for (size_t i = 0; i < n; ++i) result[i] = i + 1;
    return result;
}


template <typename T>
std::vector<T> generateSortedReverseVector(size_t n) {
    std::vector<T> result(n);
    for (size_t i = 0; i < n; ++i) result[i] = n - i;
    return result;
}

#endif
