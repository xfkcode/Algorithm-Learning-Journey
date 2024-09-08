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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1), *p = &dummy;
        p->next = head;
        ListNode* x = foundKnode(head, n+1);
        x->next = x->next->next;
        return p->next;
    }

private:
    ListNode* foundKnode(ListNode* head, int k) {
        ListNode* p1 = head;
        for(int i=0; i<k ; i++) {
            p1 = p1->next;
        }

        ListNode* p2 = head;
        while(p1!=nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }
};

// 打印链表的帮助函数
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// 构建链表的帮助函数
ListNode* createList(std::initializer_list<int> vals) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    for (int val : vals) {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dummy->next;
}

int main() {
    // 初始化链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createList({1, 2, 3, 4, 5});
    std::cout << "原始链表: ";
    printList(head);

    // 删除倒数第2个节点
    Solution sol;
    head = sol.removeNthFromEnd(head, 2);

    // 输出删除后的链表
    std::cout << "删除倒数第2个节点后的链表: ";
    printList(head);

    system("pause");
    return 0;
}