/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    //O(N) 8ms 10MB
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int ans = INT_MAX, sum = 0;
        size_t idx = 0;
        for (size_t i = idx; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum >= s)
            {
                while (sum >= s && idx <= i)
                {
                    ans = min(ans, (int)(i - idx + 1));
                    sum -= nums[idx];
                    idx++;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
