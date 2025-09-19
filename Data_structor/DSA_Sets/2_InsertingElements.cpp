//2. Inserting Elements
#include <iostream>
#include <set>

int main() {
    std::set<int> s;

    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10); // Duplicate, ignored

    std::cout << "Set contains: ";
    for (int x : s) {
        std::cout << x << " ";  // Output: 10 20 30
    }

    return 0;
}

// insert(value) inserts an element into the set.
// Duplicate values are ignored.