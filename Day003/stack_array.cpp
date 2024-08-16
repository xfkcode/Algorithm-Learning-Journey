#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <cassert>

template<typename T>
class marray_stack {
public:
    marray_stack() : stacksize(0), stackcapacity(10), topIndex(-1) {
        arr = new T[stackcapacity];
    }
    ~marray_stack() { delete[] arr; }

    size_t size() const { return stacksize; }
    size_t capacity() const { return stackcapacity; }

    bool empty() const { return topIndex==-1;}

    void clear() {
        topIndex = -1;
        stacksize = 0;
    }

    //压栈
    void push(const T& value) {
        if(topIndex >= stackcapacity - 1) {
            resize();
        }
        arr[++topIndex] = value;
        ++stacksize;
    }
    //弹栈
    void pop() {
        if(empty()) {
            throw std::underflow_error("Stack underflow");
        }
        --topIndex;
        --stacksize;
    }

    //栈顶
    T& top() const {
        if(empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[topIndex];
    }


private:
    T* arr;
    int stacksize;
    int stackcapacity;
    int topIndex;

    void resize() {
        T* temp = arr;
        stackcapacity *= 2;
        arr = new T[stackcapacity];
        for(int i = 0; i <= topIndex; ++i) {
            arr[i] = temp[i];
        }
        delete[] temp;
    }

};

int main() {
    marray_stack<int> stack;

    // 测试压栈操作
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.size() == 3);
    std::cout << "Pushed 3 elements. Stack size: " << stack.size() << std::endl;

    // 测试栈顶元素
    assert(stack.top() == 3);
    std::cout << "Top element is: " << stack.top() << std::endl;

    // 测试弹栈操作
    stack.pop();
    assert(stack.size() == 2);
    assert(stack.top() == 2);
    std::cout << "Popped 1 element. Stack size: " << stack.size() << ", top element: " << stack.top() << std::endl;

    // 测试清空栈
    stack.clear();
    assert(stack.size() == 0);
    assert(stack.empty());
    std::cout << "Cleared the stack. Stack is empty: " << std::boolalpha << stack.empty() << std::endl;

    // 测试动态扩容
    for (int i = 0; i < 20; ++i) {
        stack.push(i);
    }
    assert(stack.size() == 20);
    assert(stack.capacity() >= 20);
    std::cout << "Pushed 20 elements. Stack size: " << stack.size() << ", capacity: " << stack.capacity() << std::endl;
    
    system("pause");
    return 0;
}