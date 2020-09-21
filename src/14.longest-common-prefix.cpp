/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0)
        {
            return "";
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }
        size_t maxLen = strs[0].length();
        size_t strsNum = strs.size();
        for (size_t i = 1; i < strsNum; i++)
        {
            maxLen = maxLenPrefixOfTwoStr(strs[0].substr(0, maxLen), strs[i]);
            if (maxLen <= 0 )
            {
                return "";
            }
        }
        return strs[0].substr(0, maxLen);
    }

private:
    size_t maxLenPrefixOfTwoStr(string str1, string str2)
    {
        size_t len1 = str1.length(), len2 = str2.length();
        size_t shortLen = min(len1, len2);
        size_t ret = 0;

        for (size_t i = 0; i < shortLen; i++)
        {
            if (str1[i] != str2[i]) break;
            ret++;
        }
        
        return ret;
    }
};
// @lc code=end

