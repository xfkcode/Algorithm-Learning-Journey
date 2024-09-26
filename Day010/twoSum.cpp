#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void printVector(const vector<int>& nums, int size) {
    for (int i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                return vector<int>{left+1, right+1};
            else if(sum < target)
                left++;
            else if(sum > target)
                right--; 
        }
        return vector<int>{-1, -1};
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test case 1 result: ";
    printVector(result1, result1.size());

    // Test case 2
    vector<int> nums2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test case 2 result: ";
    printVector(result2, result2.size());

    // Test case 3
    vector<int> nums3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test case 3 result: ";
    printVector(result3, result3.size());

    // Test case 4
    vector<int> nums4 = {1, 2, 3, 4, 4, 9, 10};
    int target4 = 8;
    vector<int> result4 = solution.twoSum(nums4, target4);
    cout << "Test case 4 result: ";
    printVector(result4, result4.size());

    // Test case 5 (No solution)
    vector<int> nums5 = {1, 2, 3};
    int target5 = 7;
    vector<int> result5 = solution.twoSum(nums5, target5);
    cout << "Test case 5 result: ";
    printVector(result5, result5.size());

    system("pause");
    return 0;
}
