//6. Getting the Size of the Set
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {1, 2, 3, 4, 5};
    
    std::cout << "Size of the set: " << s.size() << std::endl; // Output: 5

    return 0;
}

//size() returns the number of elements in the set.
