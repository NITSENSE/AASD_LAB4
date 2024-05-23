#ifndef EXP
#define EXP

#include "SearchTree.h"
#include <vector>
#include <chrono>

const size_t K = 116640;
const size_t ATTEMPTS100 = 100;
const size_t ATTEMPTS1000 = 1000;

#include "../include/experiment.h"

int lcg(const int& len = K) {
    static int x = 0;
    x = (1021 * x + 24631) % len;
    return x;
}

set generate_random_tree(size_t size) {
    set tree;
    for (size_t i = 0; i < size; ++i) {
        tree.insert(lcg());
    }
    return tree;
}

std::vector<int> generate_random_vector(size_t size) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.push_back(lcg());
    }
    return arr;
}

template <class T>
double average_fill_time(T generate, size_t size) {
    double time = 0.0;
    for (size_t i = 0; i < ATTEMPTS100; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        generate(size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        time += duration.count();
    }
    return time / ATTEMPTS100;
}

double average_time_search_in_tree(const set& tree) {
    double time = 0.0;
    for (size_t i = 0; i < ATTEMPTS1000; ++i) {
        auto start = std::chrono::steady_clock::now();
        tree.contains(lcg());
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> duration = end - start;
        time += duration.count();
    }
    return time / ATTEMPTS1000;
}

double average_time_insert_tree(set tree) {
    double time = 0.0;
    for (size_t i = 0; i < ATTEMPTS1000; ++i) {
        auto start = std::chrono::steady_clock::now();
        tree.insert(lcg());
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> duration = end - start;
        time += duration.count();
    }
    return time / ATTEMPTS1000;
}

double average_time_erase_tree(set tree) {
    double time = 0.0;
    for (size_t i = 0; i < ATTEMPTS1000; ++i) {
        auto start = std::chrono::steady_clock::now();
        tree.insert(lcg());
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> duration = end - start;
        time += duration.count();
    }
    return time / ATTEMPTS1000;
}

double average_time_search_in_vector(const std::vector<int>& arr) {
    double time = 0.0;
    for (size_t i = 0; i < ATTEMPTS1000; ++i) {
        auto start = std::chrono::steady_clock::now();
        std::find(arr.begin(), arr.end(), lcg());
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> duration = end - start;
        time += duration.count();
    }
    return time / ATTEMPTS1000;
}

double average_time_insert_vector(std::vector<int> arr) {
    double time = 0.0;
    for (size_t i = 0; i < ATTEMPTS1000; ++i) {
        auto start = std::chrono::steady_clock::now();
        arr.insert(arr.begin() + lcg(int(arr.size())), lcg());
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> duration = end - start;
        time += duration.count();
    }
    return time / ATTEMPTS1000;
}

double average_time_erase_vector(std::vector<int> arr) {
    double time = 0.0;
    for (size_t i = 0; i < ATTEMPTS1000; ++i) {
        auto start = std::chrono::steady_clock::now();
        arr.erase(arr.begin() + lcg(int(arr.size())));
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> duration = end - start;
        time += duration.count();
    }
    return time / ATTEMPTS1000;
}


#endif
