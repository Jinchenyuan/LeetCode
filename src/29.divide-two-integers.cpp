/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <math.h>

class Solution {
public:

    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;

        int s = 1;
        if (dividend > 0 && divisor < 0 || dividend < 0 || divisor > 0) s = -1;

        int dvd = abs(dividend);
        int dvs = abs(divisor);

        int mb = 1;

        while ((dvd >> mb) > dvs)
        {
            mb++;
        }
        mb--;

        int ret = (1 << mb);
        while (true)
        {
           int tmb = removeHighBit(dvd);
           if (dvd > dvs)
           {
               ret += (1 << (mb - tmb));
           }
           else
           {
               break;
           }
        }

        return ret * s;
    }

private:

    unsigned int removeHighBit(int &value)
    {
        int mb = 0;
        while (INT32_MAX >> mb & value > value)
        {
            mb++;
        }
        value &= INT32_MAX >> mb;
        return mb;
    }
};
// @lc code=end

