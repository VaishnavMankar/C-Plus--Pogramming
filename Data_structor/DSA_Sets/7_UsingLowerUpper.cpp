// 7. Using lower_bound() and upper_bound()
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {10, 20, 30, 40, 50};

    std::cout << "Lower bound of 25: " << *s.lower_bound(25) << "\n"; // Output: 30
    std::cout << "Upper bound of 30: " << *s.upper_bound(30) << "\n"; // Output: 40

    return 0;
}

// lower_bound(x): Returns an iterator pointing to the first element greater than or equal to x.
// upper_bound(x): Returns an iterator pointing to the first element greater than x.