#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast =0;
        while(fast < nums.size()) {
            if(nums[fast] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};

int main() {


    system("pause");
    return 0;
}