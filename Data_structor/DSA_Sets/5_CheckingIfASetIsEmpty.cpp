//5. Checking if a Set is Empty

#include <iostream>
#include <set>

int main() {
    std::set<int> s;

    if (s.empty()) {
        std::cout << "Set is empty.\n";
    }

    s.insert(25);
    if (!s.empty()) {
        std::cout << "Set is not empty.\n";
    }

    return 0;
}

//empty() returns true if the set is empty, otherwise false.
