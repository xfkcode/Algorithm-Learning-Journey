#include <iostream>
#include <stdexcept>
#include <stdlib.h>

template<typename T>
class marray_stack {
public:
    marray_stack() : stacksize(0), capacity(10), topIndex(-1) {
        arr = new T[capacity];
    }
    ~marray_stack() { clear(); }

    size_t size() const { return stacksize; }
    size_t capacity() const { return capacity; }

    bool empty() { return topIndex==-1;}

    void clear() {
        topIndex = -1;
        stacksize = 0;
        capacity = 0;
        delete[] arr;
    }

    //压栈
    void push(const T& value) {
        if(topIndex >= capacity - 1) {
            resize();
        }
        arr[++topIndex] = value;

    }
    //弹栈
    void pop() {
        if(empty()) {
            
        }
    }

    //栈顶
    T& top() {

    }


private:
    T* arr;
    int stacksize;
    int capacity;
    int topIndex;


};

int main() {
    
    system("pause");
    return 0;
}