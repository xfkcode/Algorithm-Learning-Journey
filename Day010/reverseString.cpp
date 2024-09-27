#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void printVector(const vector<char>& s) {
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;
}

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    // Test 1: Empty string
    vector<char> test1 = {};
    solution.reverseString(test1);
    cout << "Test 1 (Empty): ";
    printVector(test1);

    // Test 2: Single character
    vector<char> test2 = {'a'};
    solution.reverseString(test2);
    cout << "Test 2 (Single): ";
    printVector(test2);

    // Test 3: Two characters
    vector<char> test3 = {'a', 'b'};
    solution.reverseString(test3);
    cout << "Test 3 (Two): ";
    printVector(test3);

    // Test 4: Even number of characters
    vector<char> test4 = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(test4);
    cout << "Test 4 (Even): ";
    printVector(test4);

    // Test 5: Odd number of characters
    vector<char> test5 = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    solution.reverseString(test5);
    cout << "Test 5 (Odd): ";
    printVector(test5);

    // Test 6: Mixed characters
    vector<char> test6 = {'A', 'B', 'C', '1', '2', '3'};
    solution.reverseString(test6);
    cout << "Test 6 (Mixed): ";
    printVector(test6);
    
    system("pause");
    return 0;
}
