//3. Finding an Element
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {5, 10, 15, 20};

    int key = 10;
    if (s.find(key) != s.end()) {
        std::cout << key << " found in set.\n";
    } else {
        std::cout << key << " not found in set.\n";
    }

    return 0;
}

// find(value) returns an iterator pointing to the element if found, otherwise end().
