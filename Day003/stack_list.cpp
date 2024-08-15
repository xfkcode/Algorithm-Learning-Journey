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
    mlist_stack() : topNode(nullptr), stacksize(0) {}
    ~mlist_stack() { clear(); }

    bool empty() { return stacksize==0; }

    size_t size() { return stacksize; }

    void clear() {
        while(topNode) {
            pop();
        }
    }

    //压栈
    void push(const T& value) {
        Node<T>* nweNode = new Node<T>(value);
        if(topNode) {
            nweNode->next = topNode;
        } 
        topNode = nweNode;
        ++stacksize;
    }

    //弹栈
    void pop() {
        if(!topNode) { return; }
        Node<T>* temp = topNode;
        
        topNode = topNode->next;

        delete temp;
        --stacksize;
    }

    //栈顶
    T& top() {
        if (empty()) throw std::out_of_range("Stack is empty");
        return topNode->data;
    }

private:
    Node<T>* topNode;
    size_t stacksize;
};

int main() {
    // 创建一个整数栈
    mlist_stack<int> stack;

    // 测试空栈
    std::cout << "Test empty stack: " << std::boolalpha << stack.empty() << std::endl;  // 预期输出: true

    // 压入元素
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // 测试栈是否为空
    std::cout << "Stack is empty after push: " << std::boolalpha << stack.empty() << std::endl;  // 预期输出: false

    // 检查栈顶元素
    std::cout << "Top element: " << stack.top() << std::endl;  // 预期输出: 30

    // 弹出元素
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;  // 预期输出: 20

    // 继续弹出元素
    stack.pop();
    std::cout << "Top element after another pop: " << stack.top() << std::endl;  // 预期输出: 10

    // 测试栈的大小
    std::cout << "Stack size: " << stack.size() << std::endl;  // 预期输出: 1

    // 清空栈
    stack.clear();
    std::cout << "Stack is empty after clear: " << std::boolalpha << stack.empty() << std::endl;  // 预期输出: true

    // 测试空栈时的top()操作
    try {
        stack.top();  // 预期抛出异常
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;  // 预期输出: "Caught exception: Stack is empty"
    }

    system("pause");
    return 0;
}