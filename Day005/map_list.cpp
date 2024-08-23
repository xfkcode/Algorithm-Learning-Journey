#include <stdexcept>
#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <list>
#include <vector>
#include <functional>

template<typename K, typename V>
class HashTable {
public:
    HashTable(size_t size) : table_size(size), current_size(0) { table.resize(size); }
    ~HashTable() {}

    bool empty() const { return current_size==0; }
    size_t size() const { return current_size; }

    void insert(const K& key, const V& value) {
        size_t index = hashFunc(key);
        for(auto& pair : table[index]) {
            if(pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
        current_size++;
    }

    bool erase(const K& key) {
        size_t index = hashFunc(key);
        auto& chain = table[index];
        for(auto it=chain.begin(); it!=chain.end(); it++) {
            if(it->first == key) {
                chain.erase(it);
                current_size--;
                return true;
            }
        }
        return false;
    }

    V* find(const K& key) {
        size_t index = hashFunc(key);
        for(auto& pair : table[index]) {
            if(pair.first == key) {
                return &pair.second;
            }
        }
        return nullptr;
    }

    void print() const {
        for (size_t i = 0; i < table_size; ++i) {
            std::cout << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "{" << pair.first << ": " << pair.second << "} -> ";
            }
            std::cout << "NULL" << std::endl;
        }
    }

private:
    std::vector<std::list<std::pair<K, V>>> table;
    size_t table_size;
    size_t current_size;

    size_t hashFunc(const K& key) const {
        return std::hash<K>{}(key) % table_size;
    }

};


int main() {
    HashTable<std::string, int> myMap(10);

    myMap.insert("apple", 1);
    myMap.insert("banana", 2);
    myMap.insert("orange", 3);

    if (int* value = myMap.find("apple")) {
        std::cout << "apple: " << *value << std::endl;
    } else {
        std::cout << "apple not found" << std::endl;
    }

    myMap.erase("banana");

    myMap.print();

    system("pause");
    return 0;
}