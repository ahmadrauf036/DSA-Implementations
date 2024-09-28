#include <iostream>
#include <cstring>

// HashNode class
class HashNode {
public:
    int key;
    char value[100];
    HashNode* next;

    HashNode(int k, const char* val) : key(k), next(nullptr) {
        strcpy(value, val);
    }
};
