#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> umap;

    // Insert key-value pairs
    umap[1] = "Apple";
    umap[2] = "Banana";
    umap[3] = "Cherry";

    // Access values using keys
    cout << "Key 1: " << umap[1] << endl;

    // Insert using insert()
    umap.insert({4, "Dates"});

    // Iterate through unordered_map
    for (auto it : umap) {
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }

    // Check if a key exists
    if (umap.find(2) != umap.end()) {
        cout << "Key 2 is present" << endl;
    }

    // Erase an element by key
    umap.erase(3);

    // Check the size
    cout << "Size of unordered_map: " << umap.size() << endl;

    return 0;
}
