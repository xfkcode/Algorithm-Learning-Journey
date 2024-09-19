#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& nums, int size) {
    for (int i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) {
            return 0;
        }
        int slow = 0, fast =0;
        while(fast < nums.size()) {
            if(nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: No duplicates
    vector<int> nums1 = {1, 2, 3, 4, 5};
    int size1 = solution.removeDuplicates(nums1);
    cout << "Test case 1: No duplicates\nNew size: " << size1 << "\nResult: ";
    printVector(nums1, size1);
    
    // Test case 2: Some duplicates
    vector<int> nums2 = {1, 1, 2, 2, 3, 4, 4};
    int size2 = solution.removeDuplicates(nums2);
    cout << "Test case 2: Some duplicates\nNew size: " << size2 << "\nResult: ";
    printVector(nums2, size2);
    
    // Test case 3: All elements are duplicates
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int size3 = solution.removeDuplicates(nums3);
    cout << "Test case 3: All elements are duplicates\nNew size: " << size3 << "\nResult: ";
    printVector(nums3, size3);
    
    // Test case 4: Empty vector
    vector<int> nums4 = {};
    int size4 = solution.removeDuplicates(nums4);
    cout << "Test case 4: Empty vector\nNew size: " << size4 << "\nResult: ";
    printVector(nums4, size4);

    // Test case 5: Single element
    vector<int> nums5 = {42};
    int size5 = solution.removeDuplicates(nums5);
    cout << "Test case 5: Single element\nNew size: " << size5 << "\nResult: ";
    printVector(nums5, size5);

    system("pause");
    return 0;
}