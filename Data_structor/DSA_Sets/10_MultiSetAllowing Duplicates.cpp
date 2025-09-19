//10. Multi-Set (Allowing Duplicates)
//A multiset is similar to set but allows duplicate values.

#include <iostream>
#include <set>

int main() {
    std::multiset<int> ms = {10, 20, 10, 30, 20};

    std::cout << "Elements in multiset: ";
    for (int x : ms) {
        std::cout << x << " ";  // Output: 10 10 20 20 30
    }

    return 0;
}

// multiset<int> stores duplicate elements.
// Operations are the same as set.

// Conclusion
// set is a powerful data structure in C++ when you need unique elements in sorted order with efficient insertions, deletions, and lookups. Use multiset if duplicates are needed.