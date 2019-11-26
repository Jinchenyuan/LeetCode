/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPowerOfTwo1(int n)
    {
        return n <= 0 ? false : (n & (n - 1)) == 0;
    }
    bool isPowerOfTwo2(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;

        while (n > 1)
        {
            if (n & 1)
                return false;
            n /= 2;
        }
        return true;
    }
};
// @lc code=end

