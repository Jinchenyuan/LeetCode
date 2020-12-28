/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0); 
        
        for (int i = 1; i <= num; i++) {
            ret[i] = ret[i >> 1] + (i & 1);
        }
        
        return ret;
    }
};
// @lc code=end

