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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) { return nullptr; }
        ListNode *slow = head, *fast = head;
        while(fast != nullptr) {
            if(fast->val != slow->val) {
#if 0                
                slow = slow->next;
                slow->val = fast->val;
#else
                slow->next = fast;
                slow = slow->next;
#endif
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};

int main(int argc, const char** argv) {
    // Create test cases
    Solution solution;
    
    // Test Case 1: Empty List
    ListNode* list1 = createList({});
    ListNode* result1 = solution.deleteDuplicates(list1);
    std::cout << "Test Case 1: ";
    printList(result1); // Expected Output: (Empty Line)

    // Test Case 2: Single Element List
    ListNode* list2 = createList({1});
    ListNode* result2 = solution.deleteDuplicates(list2);
    std::cout << "Test Case 2: ";
    printList(result2); // Expected Output: 1

    // Test Case 3: List with No Duplicates
    ListNode* list3 = createList({1, 2, 3, 4, 5});
    ListNode* result3 = solution.deleteDuplicates(list3);
    std::cout << "Test Case 3: ";
    printList(result3); // Expected Output: 1 -> 2 -> 3 -> 4 -> 5

    // Test Case 4: List with All Duplicates
    ListNode* list4 = createList({1, 1, 1, 1, 1});
    ListNode* result4 = solution.deleteDuplicates(list4);
    std::cout << "Test Case 4: ";
    printList(result4); // Expected Output: 1

    // Test Case 5: List with Some Duplicates
    ListNode* list5 = createList({1, 1, 2, 3, 3, 4, 5, 5});
    ListNode* result5 = solution.deleteDuplicates(list5);
    std::cout << "Test Case 5: ";
    printList(result5); // Expected Output: 1 -> 2 -> 3 -> 4 -> 5

    system("pause");
    return 0;
}