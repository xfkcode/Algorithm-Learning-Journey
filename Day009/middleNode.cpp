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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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

void printMiddle(ListNode* middle) {
    if (middle != nullptr) {
        std::cout << "Middle node value: " << middle->val << std::endl;
    } else {
        std::cout << "List is empty, no middle node." << std::endl;
    }
}

int main() {
    Solution sol;

    // Test case 1: Empty list
    ListNode* head1 = nullptr;
    ListNode* middle1 = sol.middleNode(head1);
    std::cout << "Test case 1 - Empty list: ";
    printMiddle(middle1);

    // Test case 2: Single node list
    ListNode* head2 = createList({1});
    ListNode* middle2 = sol.middleNode(head2);
    std::cout << "Test case 2 - Single node list: ";
    printList(head2);
    printMiddle(middle2);

    // Test case 3: Even number of nodes
    ListNode* head3 = createList({1, 2, 3, 4});
    ListNode* middle3 = sol.middleNode(head3);
    std::cout << "Test case 3 - Even number of nodes: ";
    printList(head3);
    printMiddle(middle3);

    // Test case 4: Odd number of nodes
    ListNode* head4 = createList({1, 2, 3, 4, 5});
    ListNode* middle4 = sol.middleNode(head4);
    std::cout << "Test case 4 - Odd number of nodes: ";
    printList(head4);
    printMiddle(middle4);

    // Clean up
    // Function to delete the entire list
    auto deleteList = [](ListNode* head) {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    };

    deleteList(head2);
    deleteList(head3);
    deleteList(head4);

    system("pause");
    return 0;
}