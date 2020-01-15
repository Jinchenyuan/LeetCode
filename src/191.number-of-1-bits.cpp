/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        uint32_t idx = 1;
        do
        {
            if (n & idx)
                ret++;
            idx <<= 1;
        } while (idx);
        
        return ret;
    }
};
// @lc code=end

