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
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(fast < nums.size()) {
            if(nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        for(;slow < nums.size(); slow++) {
            nums[slow] = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    // Test case
    vector<int> nums = {0, 1, 0, 3, 12};
    cout << "Original vector: ";
    printVector(nums, nums.size());

    solution.moveZeroes(nums);

    cout << "After moving zeroes: ";
    printVector(nums, nums.size());

    // Additional test cases
    vector<vector<int>> testCases = {
        {0, 0, 1},
        {1, 0, 2, 0, 3},
        {0, 0, 0},
        {1, 2, 3},
        {},
        {0, 1, 0, 0, 2, 0, 3}
    };

    for (const auto& testCase : testCases) {
        vector<int> nums = testCase;
        cout << "Original vector: ";
        printVector(nums, nums.size());

        solution.moveZeroes(nums);

        cout << "After moving zeroes: ";
        printVector(nums, nums.size());
        cout << "--------------------------" << endl;
    }

    system("pause");
    return 0;
}
