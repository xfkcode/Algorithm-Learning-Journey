#include <iostream>
#include <stdexcept>
#include <stdlib.h>

template<typename T>
class m_vector {
public:
    m_vector() : _size(0), _capacity(1), _data(new T[1]) {}
    ~m_vector() {
        delete[] _data;
    }

    size_t size() const {
        return _size;
    }

    size_t capacity() const {
        return _capacity;
    }

    bool empty() const {
        return _size == 0;
    }

    //增
    void push_back(const T& value) {
        if (_size == _capacity) {
            resize();
        }
        _data[_size++] = value;
    }

    //删
    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    //查改
    T& operator[](size_t index) {
        return _data[index];
    }
    const T& operator[](size_t index) const {
        return _data[index];
    }
    T& at(size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }
    const T& at(size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    void clear() {
        _size = 0;
    }

private:
    size_t _size;
    size_t _capacity;
    T* _data;

    void resize() {
        _capacity *= 2;
        T* new_data = new T[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;      
    }
};


int main(int argc, const char** argv) {
    m_vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Element at index " << i << ": " << vec[i] << std::endl;
    }

    vec.pop_back();
    std::cout << "After pop_back, size: " << vec.size() << std::endl;

    vec[0] = 10;        
    vec.at(1) = 20;     

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Element at index " << i << ": " << vec[i] << std::endl;
    }
    
    system("pause");
    return 0;
}