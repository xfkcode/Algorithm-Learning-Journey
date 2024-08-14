#include <iostream>
#include <iterator>
#include <stdlib.h>

template<typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template<typename T>
class m_List {
public:
    class iterator {
    public:
        Node<T>* ptr;

        iterator(Node<T>* node) : ptr(node) {}

        T& operator*() { return ptr->data; }

        iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        iterator& operator--() {
            ptr = ptr->prev;
            return *this;
        }

        iterator operator--(int) {
            iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const iterator& other) const { return ptr != other.ptr; }
    };

private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    m_List() : head(nullptr), tail(nullptr), size(0) {}
    ~m_List() { clear(); }

    size_t getsize() const { return size; }

    bool empty() const { return size==0; }

    void clear() {
        while(head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
        ++size;
    }

    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        } else {
            head = tail = newNode;
        }
    }

    void pop_back() {
        if(!tail) return;

        Node<T>* temp = tail;
        tail = tail->prev;
        if(tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        --size;
    }

    void pop_front() {
        if(!head) return;

        Node<T>* temp = head;
        head = head->next;
        if(head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        --size;
    }

    T& front() { 
        if(empty()) throw std::out_of_range("List is empty");
        return head->data; 
    }

    T& back() {
        if (empty()) throw std::out_of_range("List is empty");
        return tail->data;
    }

    iterator insert(iterator pos, const T& value) {
        Node<T>* current = pos.ptr;
        Node<T>* newNode = new Node<T>(value);

        if(!current) {
            push_back(value);
            return iterator(tail);
        }

        newNode->prev = current->prev;
        newNode->next = current;
        if(current->prev) {
            current->prev->next = newNode;
        } else {
            head = newNode;
        }
        current->prev = newNode;

        ++size;
        return iterator(newNode);
    }

    iterator erase(iterator pos) {
        if (empty() || !pos.ptr) return pos;

        Node<T>* current = pos.ptr;

        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        iterator nextPos(current->next);
        delete current;
        --size;
        return nextPos;
    }

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }
};


int main() {
    m_List<int> myList;

    // 在链表末尾添加元素
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    // 在链表头部添加元素
    myList.push_front(0);

    // 输出链表中的元素
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 在第二个位置插入元素
    auto it = myList.begin();
    ++it;
    myList.insert(it, 10);

    // 输出链表中的元素
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 删除第一个元素
    myList.pop_front();

    // 输出链表中的元素
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}