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

// 释放链表函数
void deleteList(ListNode* head) {
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while(p1 != p2) {
            if(p1==nullptr) {
                p1 = headB;
            } else {
                p1 = p1->next;
            }
            if(p2==nullptr) {
                p2 = headA;
            } else {
                p2 = p2->next;
            }
        }
        return p1;
    }
};

int main() {
    // Create two linked lists with intersection
    ListNode* common = createList({8, 9, 10});
    ListNode* listA = createList({1, 2, 3});
    ListNode* listB = createList({4, 5});

    // Link common part to listA and listB
    ListNode* temp = listA;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = common;

    temp = listB;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = common;

    // Print both lists
    std::cout << "List A: ";
    printList(listA);
    std::cout << "List B: ";
    printList(listB);

    // Find intersection
    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(listA, listB);
    
    if (intersection != nullptr) {
        std::cout << "Intersection Node: " << intersection->val << std::endl;
    } else {
        std::cout << "No Intersection" << std::endl;
    }

    system("pause");
    return 0;
}