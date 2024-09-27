#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            // 以 s[i] 为中心的最长回文子串
            string s1 = palindrome(s, i, i);
            // 以 s[i] 和 s[i+1] 为中心的最长回文子串
            string s2 = palindrome(s, i, i + 1);
            // res = longest(res, s1, s2)
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }
    string palindrome(std::string s, int l, int r) {
        while(l>=0 && r<s.length() && s[l] == s[r])   {
            l--; r++;
        }
        return s.substr(l+1, r-l-1);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    // Test cases
    string test1 = "babad"; // Expected: "bab" or "aba"
    string test2 = "cbbd";  // Expected: "bb"
    string test3 = "a";     // Expected: "a"
    string test4 = "ac";    // Expected: "a" or "c"
    string test5 = "racecar"; // Expected: "racecar"
    string test6 = "noon";  // Expected: "noon"
    string test7 = "aabb";  // Expected: "aa" or "bb"
    
    cout << "Test 1: " << sol.longestPalindrome(test1) << endl;
    cout << "Test 2: " << sol.longestPalindrome(test2) << endl;
    cout << "Test 3: " << sol.longestPalindrome(test3) << endl;
    cout << "Test 4: " << sol.longestPalindrome(test4) << endl;
    cout << "Test 5: " << sol.longestPalindrome(test5) << endl;
    cout << "Test 6: " << sol.longestPalindrome(test6) << endl;
    cout << "Test 7: " << sol.longestPalindrome(test7) << endl;

    system("pause");
    return 0;
}
