#include "hashLP.h"

class HashMap {
private:
    HashNode** table;
    int capacity;
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashMap(int size) : capacity(size) {
        table = new HashNode*[capacity];
        for (int i = 0; i < capacity; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(int key, const char* value) {
        int hashIndex = hashFunction(key);
        HashNode* prev = nullptr;
        HashNode* entry = table[hashIndex];

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            entry = new HashNode(key, value);
            if (prev == nullptr) {
                table[hashIndex] = entry;
            } else {
                prev->next = entry;
            }
        } else {
            strcpy(entry->value, value);
        }
    }

    const char* search(int key) {
        int hashIndex = hashFunction(key);
        HashNode* entry = table[hashIndex];

        while (entry != nullptr) {
            if (entry->key == key) {
                return entry->value;
            }
            entry = entry->next;
        }

        return "Key not found";
    }

    ~HashMap() {
        for (int i = 0; i < capacity; ++i) {
            HashNode* entry = table[i];
            while (entry != nullptr) {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }
};
