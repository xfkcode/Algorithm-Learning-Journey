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
    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;  
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    
    // Test cases
    vector<int> test1 = {1, 2, 3, 4, 5};
    int target1 = 3;
    cout << "Index of " << target1 << ": " << solution.binarySearch(test1, target1) << endl;

    vector<int> test2 = {1, 2, 3, 4, 5};
    int target2 = 6;
    cout << "Index of " << target2 << ": " << solution.binarySearch(test2, target2) << endl;

    vector<int> test3 = {1, 2, 3, 4, 5};
    int target3 = 1;
    cout << "Index of " << target3 << ": " << solution.binarySearch(test3, target3) << endl;

    vector<int> test4 = {1, 2, 3, 4, 5};
    int target4 = 5;
    cout << "Index of " << target4 << ": " << solution.binarySearch(test4, target4) << endl;

    vector<int> test5 = {1, 3, 5, 7, 9, 11};
    int target5 = 7;
    cout << "Index of " << target5 << ": " << solution.binarySearch(test5, target5) << endl;

    vector<int> test6 = {1, 3, 5, 7, 9, 11};
    int target6 = 2;
    cout << "Index of " << target6 << ": " << solution.binarySearch(test6, target6) << endl;

    // Edge case: empty array
    vector<int> test7 = {};
    int target7 = 1;
    cout << "Index of " << target7 << ": " << solution.binarySearch(test7, target7) << endl;

    // Edge case: single element (target found)
    vector<int> test8 = {1};
    int target8 = 1;
    cout << "Index of " << target8 << ": " << solution.binarySearch(test8, target8) << endl;

    // Edge case: single element (target not found)
    vector<int> test9 = {1};
    int target9 = 2;
    cout << "Index of " << target9 << ": " << solution.binarySearch(test9, target9) << endl;

    system("pause");
    return 0;
}
