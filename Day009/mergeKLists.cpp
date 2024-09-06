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
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1), *p = &dummy;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            p->next = node;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
            p = p->next;
        }
        return dummy.next;
    }
};

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

int main() {
    // 创建多个有序链表
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    cout << "K Lists: " << std::endl;
    printList(l1);
    printList(l2);
    printList(l3);

    // 将链表放入vector
    vector<ListNode*> lists = {l1, l2, l3};

    // 创建解决方案实例
    Solution solution;
    ListNode* mergedList = solution.mergeKLists(lists);

    // 打印合并后的链表
    cout << "Merged List: " << std::endl;
    printList(mergedList);

    // 清理动态分配的内存
    delete l1;
    delete l2;
    delete l3;

    system("pause");
    return 0;
}