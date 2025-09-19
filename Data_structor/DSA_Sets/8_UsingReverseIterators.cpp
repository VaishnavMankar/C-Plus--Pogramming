//8. Using Reverse Iterators
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {10, 20, 30, 40};

    std::cout << "Elements in descending order: ";
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        std::cout << *it << " ";  // Output: 40 30 20 10
    }

    return 0;
}

//rbegin() and rend() help in iterating over the set in reverse order.
