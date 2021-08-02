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
        int s = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;
        unsigned int dvd = dividend > 0 ? dividend : -dividend;
        unsigned int dvs = divisor > 0 ? divisor : -divisor;

        unsigned int bits[33];
        unsigned int i=0;
        unsigned int d = dvs;
        bits[i] = d;
        while( d <= dvd ){
            bits[++i] = d = d << 1;
        }
        i--;

        unsigned int ret = 0;
        while(dvd >= dvs){
            if (dvd >= bits[i]) {
                dvd -= bits[i];
                ret += (1 << i);
            }else{
                i--;
            }
        }

        if ( ret > INT32_MAX && s > 0 ) {
            return INT32_MAX;
        }

        if (ret > INT32_MAX + 1 && s < 0) {
            return INT32_MIN;
        }

        return (int)ret * s;
    }
};
// @lc code=end

