#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <cassert>

template<typename T>
class marray_queue {
public:
    marray_queue() : _queue(nullptr), q_capacity(10), q_size(0),
                     b_index(-1) {
        _queue = new T[q_capacity];
    }
    ~marray_queue() {
        delete[] _queue;
    }

    bool empty() const { return q_size==0; }
    size_t size() const { return q_size; }
    size_t capacity() const { return q_capacity; }

    void enqueue(const T& value) {
        if(q_size==q_capacity) {
            resize();
        }
        _queue[++b_index] = value;
        ++q_size;
    }

    void dequeue() {
        if(empty()) { throw std::out_of_range("Queue is empty"); }
        for(int i=0; i<q_size-1; i++) {
            _queue[i] = _queue[i+1];
        }
        --q_size;
        --b_index;
    }

    T& front() {
        if(empty()) { throw std::out_of_range("Queue is empty"); }
        return _queue[0];
    }

private:
    size_t q_size;
    size_t q_capacity;
    T* _queue;
    int b_index;

    void resize() {
        q_capacity *= 2;
        T* temp = _queue;
        _queue = new T[q_capacity];
        for(int i=0; i<q_size; i++) {
            _queue[i] = temp[i];
        }
        delete[] temp;
    }
};

int main() {
    marray_queue<int> queue;

    // 测试 enqueue
    for (int i = 1; i <= 15; ++i) {
        queue.enqueue(i);
        std::cout << "Enqueued: " << i << ", Queue size: " << queue.size() << ", Capacity: " << queue.capacity() << std::endl;
    }

    // 测试 front 和 dequeue
    while (!queue.empty()) {
        std::cout << "Front element: " << queue.front() << std::endl;
        queue.dequeue();
        std::cout << "Dequeued. Queue size: " << queue.size() << std::endl;
    }

    // 测试异常情况
    try {
        queue.front();
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        queue.dequeue();
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    system("pause");
    return 0;
}