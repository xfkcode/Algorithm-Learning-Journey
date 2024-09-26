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
    int removeElement(vector<int>& nums, int val) {
        int fast =0, slow = 0;
        while(fast < nums.size()) {
            if(nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int newLength1 = solution.removeElement(nums1, val1);
    cout << "New length: " << newLength1 << endl;
    printVector(nums1, newLength1); // Output: 2 2

    // Test case 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int newLength2 = solution.removeElement(nums2, val2);
    cout << "New length: " << newLength2 << endl;
    printVector(nums2, newLength2); // Output: 0 1 3 0 4

    // Test case 3 (All elements are the same)
    vector<int> nums3 = {1, 1, 1, 1};
    int val3 = 1;
    int newLength3 = solution.removeElement(nums3, val3);
    cout << "New length: " << newLength3 << endl;
    printVector(nums3, newLength3); // Output: (empty)

    // Test case 4 (No elements match)
    vector<int> nums4 = {4, 5, 6, 7};
    int val4 = 1;
    int newLength4 = solution.removeElement(nums4, val4);
    cout << "New length: " << newLength4 << endl;
    printVector(nums4, newLength4); // Output: 4 5 6 7

    // Test case 5 (Empty vector)
    vector<int> nums5 = {};
    int val5 = 3;
    int newLength5 = solution.removeElement(nums5, val5);
    cout << "New length: " << newLength5 << endl;
    printVector(nums5, newLength5); // Output: (empty)
    
    system("pause");
    return 0;
}
