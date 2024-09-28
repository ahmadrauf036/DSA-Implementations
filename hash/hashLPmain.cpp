#include "hashLP.cpp"

int main() {
    // Create a hash map with a specified size
    HashMap hashMap(10);

    // Insert key-value pairs
    hashMap.insert(1, "Alice");
    hashMap.insert(2, "Bob");
    hashMap.insert(3, "Charlie");
    hashMap.insert(11, "David"); // This will collide with key 1

    // Search for values
    std::cout << "Key 1: " << hashMap.search(1) << std::endl;
    std::cout << "Key 2: " << hashMap.search(2) << std::endl;
    std::cout << "Key 3: " << hashMap.search(3) << std::endl;
    std::cout << "Key 11: " << hashMap.search(11) << std::endl;
    std::cout << "Key 4: " << hashMap.search(4) << std::endl; // Key not found

    return 0;
}
