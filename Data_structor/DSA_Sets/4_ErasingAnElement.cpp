//4. Erasing an Element

#include <iostream>
#include <set>

int main() {
    std::set<int> s = {10, 20, 30, 40, 50};

    s.erase(30); // Removes element 30

    std::cout << "After erasing 30, set contains: ";
    for (int x : s) {
        std::cout << x << " ";  // Output: 10 20 40 50
    }

    return 0;
}

// erase(value) removes a specific element.
// erase(iterator) removes the element at a given position.