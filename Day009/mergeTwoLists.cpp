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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1), *p = &dummy;
        ListNode *p1 = list1, *p2 = list2;

        while(p1 != nullptr && p2 != nullptr) {
            // 比较 p1 和 p2 两个指针
            // 将值较小的的节点接到 p 指针
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            // p 指针不断前进
            p = p->next;
        }

        if (p1 != nullptr) {
            p->next = p1;
        }
        
        if (p2 != nullptr) {
            p->next = p2;
        }
        
        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        if(!head->next) {
            std::cout << head->val;
            head = head->next;
            continue;
        }
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode* createList(std::initializer_list<int> values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int value : values) {
        if (head == nullptr) {
            head = new ListNode(value);
            tail = head;
        } else {
            tail->next = new ListNode(value);
            tail = tail->next;
        }
    }

    return head;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Test Case 1
    ListNode* list1 = createList({1, 2, 4});
    printList(list1);
    ListNode* list2 = createList({1, 3, 4});
    printList(list2);
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);
    printList(mergedList);
    deleteList(mergedList);

    // Test Case 2
    list1 = createList({2, 6, 8});
    list2 = createList({1, 3, 7});
    printList(list1);
    printList(list2);
    mergedList = sol.mergeTwoLists(list1, list2);
    printList(mergedList);
    deleteList(mergedList);

    // Test Case 3
    list1 = createList({1, 4, 5});
    printList(list1);
    list2 = createList({2, 6});
    printList(list2);
    mergedList = sol.mergeTwoLists(list1, list2);
    printList(mergedList);
    deleteList(mergedList);
    system("pause");
    return 0;
}