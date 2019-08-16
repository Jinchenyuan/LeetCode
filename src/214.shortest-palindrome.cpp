#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;
        int b, e, len = 1;
        for (int i = 0; i <= n / 2;)
        {
            b = e = i;
            while (e < n - 1 && s[e] == s[e + 1])
            {
                e++;
            }
            i = e + 1;
            while (b > 0 && e < n - 1 && s[b - 1] == s[e + 1])
            {
                b--;
                e++;
            }
            if (b == 0 && e - b + 1 > len)
                len = e - b + 1;
        }
        string ans = s.substr(len);
        reverse(ans.begin(), ans.end());
        return ans + s;
    }
    
};

int main(void)
{

    // string s = "aacecaaa";
    string s = "abcd";
    Solution so;
    cout << so.shortestPalindrome(s) << endl;
    return 0;
}
