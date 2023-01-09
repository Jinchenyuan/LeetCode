/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int size = indices.size();
        string ret(size, 0);
        for (size_t i = 0; i < size; i++)
        {
            ret[indices[i]] = s[i];
        }
        return ret;
    }
};
// @lc code=end

