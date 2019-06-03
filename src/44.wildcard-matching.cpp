#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
class Solution {
public: 
    bool isMatch(string s, string p) {
        int s_long = s.size(), p_long = p.size();
        int i = 0, j = 0;
        int match;
        int risk = -1;
        while (i < s_long)
        {
            if (j < p_long && p[j] == '*') {
                match = i;
                risk = j++;
            }
            else if (j < p_long && (p[j] == s[i] || p[j] == '?')) {
                ++i;
                ++j;
            }
            else if (risk >= 0) {
                i = ++match;
                j = risk + 1;
            }
            else
                return false;
        }
        while (j < p_long && p[j] == '*')
            ++j;
        return j == p_long;
    }
};

int main(void)
{
    string s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
    string p = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
    Solution so;
    cout << so.isMatch(s, p) << endl;
    return 0;
}
