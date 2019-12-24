/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
#include <iostream>
class Solution {
public:
    uint32_t reverseBits2(uint32_t n) {
        uint32_t ret = 0;
        int half = 32 >> 1;
        for (int i = 0; i < 32; ++i)
        {
            uint32_t ut = 1 << i;
            ut &= n;
            if (half - i > 0)
                ut = ut << ((half - i) * 2 - 1); 
            else
                ut = ut >> ((i - half) * 2 + 1); 
                
            ret |= ut;
        }
        return ret;
    }

    uint32_t reverseBits1(uint32_t n)
    {
        uint32_t ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            ret = ret << 1;
            ret += n & 1;
            n = n >> 1;
        }
        return ret;
    }
};
// @lc code=end

