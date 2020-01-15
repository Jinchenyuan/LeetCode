/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        size_t len = nums.size();
        k %= len;
        if (k <= 0)
            return;
        
        deque<int> tmp;
        for (int i = len - 1; i >= 0; i--)
        {
            int idx = i - k;

            if (i >= len - k)
                    tmp.push_back(nums[i]);

            if (idx >= 0)
            {
                nums[i] = nums[idx];
            }
            else
            {
                nums[i] = tmp.front();
                tmp.pop_front();
            } 
        } 
    }
};

/**
 *  1, 2, 3 expect 2, 3, 1
 *  3, 1, 2
 *  2, 3, 1
 * 
 * */

int main(void)
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    s.rotate(nums, 2);
}
// @lc code=end

