/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) {
            return {1};
        }
        vector<int> left = beautifulArray((n + 1) >> 1);
        vector<int> right = beautifulArray(n >> 1);

        int j = 0;
        vector<int> ret(n);
        for (int i = 0; i < left.size(); i++) {
            ret[j++] = left[i] * 2 - 1;
        }
        for (int i = 0; i < right.size(); i++) {
            ret[j++] = right[i] * 2;
        }
        return ret;
    }
};
// @lc code=end

