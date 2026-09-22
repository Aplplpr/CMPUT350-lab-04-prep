#include <cstddef>  // size_t
#include <cstdint>
#include <list>
#include <random>
#include <iostream>
#include <vector>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    // test here...
    std::list<uint64_t> list;

    std::mt19937_64 rng(0);

    Timer timer;
    for (size_t i = 0; i < SIZE; i++) {
        list.push_back(rng());
    }
    uint64_t listInsertTime = timer.click<Timer::Micros>();
    std::cout << "List insertion time: " << listInsertTime << " microseconds\n";

    // vector without reserve
    rng.seed(0);

    std::vector<uint64_t> vector;

    timer.restart();

    for (size_t i = 0; i < SIZE; i++) {
        vector.push_back(rng());
    }

    uint64_t vectorInsertTime = timer.click<Timer::Micros>();

    std::cout << "Vector insertion time without reserve: " << vectorInsertTime << " microseconds\n";


    // vector with reserve
    rng.seed(0);

    std::vector<uint64_t> reservedVector;
    reservedVector.reserve(SIZE);

    timer.restart();

    for (size_t i = 0; i < SIZE; i++) {
        reservedVector.push_back(rng());
    }

    uint64_t reservedVectorInsertTime = timer.click<Timer::Micros>();

    std::cout << "Vector insertion time with reserve: " << reservedVectorInsertTime << " microseconds\n";

    // sum list
    uint64_t listSum = 0;

    timer.restart();

    for (uint64_t value : list) {
        listSum += value;
    }

    uint64_t listSumTime = timer.click<Timer::Micros>();

    std::cout << "List sum: " << listSum << "\n";
    std::cout << "List sum time: " << listSumTime << " microseconds\n";


    // sum vector without reserve
    uint64_t vectorSum = 0;

    timer.restart();

    for (uint64_t value : vector) {
        vectorSum += value;
    }

    uint64_t vectorSumTime = timer.click<Timer::Micros>();

    std::cout << "Vector sum: " << vectorSum << "\n";
    std::cout << "Vector sum time: " << vectorSumTime << " microseconds\n";

    return 0;
}
