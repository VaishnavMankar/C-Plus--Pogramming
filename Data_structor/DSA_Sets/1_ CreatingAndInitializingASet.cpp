// Key Properties of set
// Unique Elements: A set does not allow duplicate values.
// Sorted Order: Elements are stored in a specific order (ascending by default).
// Logarithmic Time Complexity: Operations like insertion, deletion, and search work in O(log N) time.
// No Direct Access by Index: Unlike vectors or arrays, elements in a set cannot be accessed using an index.

//1. Creating and Initializing a Set
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {10, 5, 20, 15, 10, 5}; // Duplicate values ignored

    std::cout << "Elements in set: ";
    for (int x : s) {
        std::cout << x << " ";  // Output: 5 10 15 20 (sorted order)
    }
    return 0;
}

// Duplicates are ignored.
// Elements are sorted in ascending order automatically.