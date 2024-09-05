/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(-1), *p1 = &dummy1;
        ListNode dummy2(-1), *p2 = &dummy2;

        ListNode* p = head;
        while(p != nullptr) {
            if(p->val >= x) {
                p2->next = p;
                p2 = p2->next;
            } else {
                p1->next = p;
                p1 = p1->next;
            }

            ListNode* tmp = p->next;
            p->next = nullptr;
            p = tmp;
        }

        p1->next = dummy2.next;
        return dummy1.next;
    }
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

int main() {
     // 创建链表: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = createList({1, 4, 3, 2, 5, 2});

    std::cout << "Original list: ";
    printList(head);

    int x = 3; // 指定划分值

    Solution solution;
    ListNode* result = solution.partition(head, x);

    std::cout << "Partitioned list with x = " << x << ": ";
    printList(result);

    system("pause");
    return 0;
}