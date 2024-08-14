#include <iostream>
#include <stdexcept>
#include <stdlib.h>

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class mlist_stack {
public:
    mlist_stack() : topNode(nullptr), size(0) {}
    ~mlist_stack() { clear(); }

    bool empty() { return size==0; }

    size_t size() { return size; }

    void clear() {
        while(topNode) {
            pop();
        }
    }

    //压栈
    void push(const T& value) {
        Node<T>* nweNode = new Node<T>(value);
        
    }

    //弹栈
    void pop() {

    }

    //栈顶


private:
    Node<T>* topNode;
    size_t size;
};

int main() {

    system("pause");
    return 0;
}