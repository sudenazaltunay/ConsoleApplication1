#include <iostream>
#include <vector>
#include "mergeSort.h"
#include "vectorGenerator.h"
#include "benchmark.h"

int main() {
    std::vector<size_t> sizes = { 10000, 20000, 30000, 40000, 50000 };
    auto comparator = [](int a, int b) { return a < b; };

    for (size_t size : sizes) {
        std::cout << "Vector Size: " << size << std::endl;

        
        auto randomVec = generateRandomVector<int>(size);
        auto randomVecCopy = randomVec;

        
        auto sortedVec = generateSortedVector<int>(size);
        auto sortedVecCopy = sortedVec;

        auto reverseVec = generateSortedReverseVector<int>(size);
        auto reverseVecCopy = reverseVec;

        Benchmark<> b1;
        mergeSort(randomVec, 0, randomVec.size() - 1, comparator);
        std::cout << "MergeSort (Random): " << b1.elapsed() << " microseconds" << std::endl;

       
        Benchmark<> b2;
        mergeSort(sortedVec, 0, sortedVec.size() - 1, comparator);
        std::cout << "MergeSort (Sorted): " << b2.elapsed() << " microseconds" << std::endl;

       
        Benchmark<> b3;
        mergeSort(reverseVec, 0, reverseVec.size() - 1, comparator);
        std::cout << "MergeSort (Reverse): " << b3.elapsed() << " microseconds" << std::endl;

        std::cout << "--------------------------" << std::endl;
    }

    return 0;
}
