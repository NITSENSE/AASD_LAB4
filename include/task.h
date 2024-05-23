#ifndef TASK
#define TASK
#include "SearchTree.h"
std::vector<int> find(const std::vector<int>& arr) {
    set tree;
    std::vector<int> duplicates;
    for (int i : arr) {

        if (tree.contains(i)) {
            duplicates.push_back(i);
        }
        else {
            tree.insert(i);
        }
    }

    return duplicates;
}
#endif
