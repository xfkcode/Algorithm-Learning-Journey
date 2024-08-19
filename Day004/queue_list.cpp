#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <cassert>

template<typename T>
class Node {
public:
    Node(const T& value) : data(value), next(nullptr) {}
    ~Node() {}

    T data;
    Node* next;
};

template<typename T>
class mlist_queue {
public:
    mlist_queue() : head(nullptr),  tail(nullptr), queuesize(0) {}
    ~mlist_queue() { clear(); }

    size_t  size() const {
        return queuesize;
    }

    bool empty() const {
        return queuesize==0;
    }

    void clear() {
        while(!empty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) {
        Node<T>* newnode = new Node<T>(value);
        if(!tail) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        ++queuesize;
    }

    void dequeue() {
        if(empty()) { throw std::out_of_range("Queue is empty"); }

        Node<T>* frontnode = head;
        
        head =  head->next;
        delete frontnode;
        --queuesize;
        if(!head) {
            tail = nullptr;
        }
    }

    T& front() {
        if(empty()) { throw std::out_of_range("Queue is empty");}

        return head->data;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    size_t queuesize;

};


int main() {
    mlist_queue<int> queue;

    // 测试空队列
    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    // 测试入队操作
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    std::cout << "Queue front: " << queue.front() << std::endl;

    // 测试出队操作
    queue.dequeue();
    std::cout << "Queue front: " << queue.front() << std::endl;

    queue.dequeue();
    std::cout << "Queue front: " << queue.front() << std::endl;

    queue.dequeue();
    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    // 测试在空队列上调用 front 和 dequeue
    try {
        queue.front();
    } catch(const std::out_of_range& e) {
        std::cout << "Caught expected exception when accessing front on empty queue: " << e.what() << std::endl;
    }

    try {
        queue.dequeue();
    } catch(const std::out_of_range& e) {
        std::cout << "Caught expected exception when dequeuing empty queue: " << e.what() << std::endl;
    }
    system("pause");
    return 0;
}