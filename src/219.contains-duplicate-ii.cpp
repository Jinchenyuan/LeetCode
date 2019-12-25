/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<int> keepNums;
        keepNums.assign(nums.begin(), nums.end());
        
        sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                if (isEqualsDistanceLessK(keepNums, nums[i], k))
                {
                    return true;
                }
                else
                {
                    while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                    {
                        i++;
                    }
                }
            }
        }
        return false;
    }
private:
    bool isEqualsDistanceLessK(vector<int> &nums, int val, int k)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                int step = 1;
                while (step <= k && ++i < nums.size())
                {
                    if (nums[i] == val)
                    {
                        return true;
                    }
                    step++;
                }
            }
        }
        return false;
    }
};
// @lc code=end

