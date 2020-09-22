/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(), same = 0;
        vector<int>::iterator it = nums.begin();
        while (it != nums.end())
        {
            if (*it == val)
            {
                nums.erase(it);
                same++;
            }
            else
            {
                it++;
            }
        }
        
        return len - same;
    }
};
// @lc code=end

