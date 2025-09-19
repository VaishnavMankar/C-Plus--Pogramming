//9. Custom Comparator for Descending Order

// By default, set stores elements in ascending order. You can use a custom comparator for descending order.

#include <iostream>
#include <set>

struct Descending {
    bool operator()(int a, int b) const {
        return a > b; // Sort in descending order
    }
};

int main() {
    std::set<int, Descending> s = {10, 5, 15, 20};

    std::cout << "Set in descending order: ";
    for (int x : s) {
        std::cout << x << " ";  // Output: 20 15 10 5
    }

    return 0;
}

//Using a custom comparator changes the order in which elements are stored.
