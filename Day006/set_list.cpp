#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <stdlib.h>

template<typename T>
struct HashNode {
    T data;
    HashNode* next;
    HashNode(const T& data) : data(data), next(nullptr) {}
};

template<typename T, typename Hash = std::hash<T>, typename Equal = std::equal_to<T>>
class HashSet {
public:
    HashSet(size_t size) : buckets_capacity(size), buckets_size(0) {
        buckets.resize(size);
    }
    ~HashSet() {}



    void insert() {

    }

    bool erase() {

    }

    bool count() {

    }





private:
    std::vector<HashNode<T>*> buckets;
    size_t buckets_size;
    size_t buckets_capacity;

    size_t hashFunc(Hash hash) {
        return hash % buckets_capacity;
    }
};

int main() {


    system("pause");
    return 0;
}