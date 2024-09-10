/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdlib.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 打印链表函数
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

// 构建链表函数
ListNode* createList(std::initializer_list<int> vals) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// 创建带环的链表
ListNode* createCyclicList(std::initializer_list<int> vals, int pos) {
    ListNode* head = createList(vals);
    if (pos == -1) return head;

    ListNode* tail = head;
    ListNode* cycleNode = nullptr;
    int index = 0;

    while (tail->next != nullptr) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        ++index;
    }
    tail->next = cycleNode;  // 创建环
    return head;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) break; 
        }

        if(fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        slow = head;
        while(slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    Solution solution;

    // 创建带有环的链表
    ListNode* head = createCyclicList({3, 2, 0, -4}, 1);  // 环开始于索引 1（值为 2 的节点）

    // 检测链表中的环
    ListNode* cycleNode = solution.detectCycle(head);

    if (cycleNode) {
        std::cout << "Cycle detected at node with value: " << cycleNode->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    system("pause");
    return 0;
}

