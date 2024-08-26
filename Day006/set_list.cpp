#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <stdlib.h>
#include <cassert>

template<typename T, typename Hash = std::hash<T>>
class HashSet {
public:
    HashSet(size_t size) : table_capacity(size), table_size(0), load_factor_threshold(0.75) {
        table.resize(size);
    }
    ~HashSet() {}

    bool empty() const { return table_size==0; }
    size_t size() const { return table_size;}

    bool insert(const T& key) {
        if (count(key)) {
            return false;
        }
        if (float(table_size) / table_capacity > load_factor_threshold) {
            rehash();
        }
        size_t index = hashFunc(key);
        table[index].push_back(key);
        ++table_size;
        return true;
    }

    bool erase(const T& key) {
        size_t index = hashFunc(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                --table_size;
                return true;
            }
        }
        return false;        
    }

    bool count(const T& key) const {
        size_t index = hashFunc(key);
        for (const auto& element : table[index]) {
            if (element == key) {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<std::list<T>> table;
    size_t table_size;
    size_t table_capacity;
    float load_factor_threshold;

    size_t hashFunc(const T& key) const {
        return Hash{}(key) % table_capacity;
    }

    void rehash() {
        table_capacity *= 2;
        std::vector<std::list<T>> new_table(table_capacity);
        for (const auto& bucket : table) {
            for (const auto& element : bucket) {
                size_t new_index = Hash{}(element) % table_capacity;
                new_table[new_index].push_back(element);
            }
        }
        table = std::move(new_table);
    }
};

int main() {
     // Test 1: Insert and Count
    {
        HashSet<int> set(10);

        assert(set.insert(5) == true); // Should succeed
        assert(set.insert(10) == true); // Should succeed
        assert(set.insert(5) == false); // Should fail (already exists)

        assert(set.count(5) == true); // Should be present
        assert(set.count(10) == true); // Should be present
        assert(set.count(15) == false); // Should not be present

        std::cout << "Insert and Count Test Passed\n";
    }

    // Test 2: Erase
    {
        HashSet<int> set(10);

        set.insert(5);
        set.insert(10);

        assert(set.erase(5) == true); // Should succeed
        assert(set.erase(10) == true); // Should succeed
        assert(set.erase(5) == false); // Should fail (already erased)

        assert(set.count(5) == false); // Should not be present
        assert(set.count(10) == false); // Should not be present

        std::cout << "Erase Test Passed\n";
    }

    // Test 3: Load Factor and Rehashing
    {
        HashSet<int> set(2); // Small initial size to trigger rehashing quickly

        assert(set.insert(1) == true);
        assert(set.insert(2) == true);
        assert(set.insert(3) == true); // This should trigger rehashing

        assert(set.count(1) == true);
        assert(set.count(2) == true);
        assert(set.count(3) == true);

        std::cout << "Rehash Test Passed\n";
    }

    // Test 4: Empty Set
    {
        HashSet<int> set(10);

        assert(set.empty() == true);
        assert(set.size() == 0);

        set.insert(1);
        assert(set.empty() == false);
        assert(set.size() == 1);

        std::cout << "Empty Set Test Passed\n";
    }

    // Test 5: Erase Non-existent Element
    {
        HashSet<int> set(10);

        set.insert(1);
        set.insert(2);

        assert(set.erase(3) == false);

        std::cout << "Erase Non-existent Test Passed\n";
    }

    // Test 6: Performance with Large Data
    {
        HashSet<int> set(10000);

        for (int i = 0; i < 10000; ++i) {
            assert(set.insert(i) == true);
        }

        for (int i = 0; i < 10000; ++i) {
            assert(set.count(i) == true);
        }

        std::cout << "Large Data Test Passed\n";
    }
    
    system("pause");
    return 0;
}