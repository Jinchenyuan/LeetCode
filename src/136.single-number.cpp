/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        return ret;
    }
};
// @lc code=end

