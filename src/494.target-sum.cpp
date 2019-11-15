/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution
{
public:
    //dynamic planning.
    int findTargetSumWays1(vector<int> &nums, int S)
    {
        int sum = 0;
        for (auto n : nums)
            sum += n;
        if (sum < S || (S + sum) % 2)
            return 0;
        int target = (S + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = target; j >= 0; --j)
            {
                if (j - nums[i] >= 0)
                    dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
    //recursive call.
    int findTargetSumWays2(vector<int> &nums, int S)
    {
        int ans = 0;
        find(nums, 0, (long long)S, ans);
        return ans;
    }

private:
    void find(vector<int> &nums, int idx, long long s, int &ans)
    {
        if (idx >= nums.size())
            return;
        if (idx == nums.size() - 1)
        {
            if (s == -nums[idx])
                ans++;
            if (s == nums[idx])
                ans++;
        }
        else
        {
            find(nums, idx + 1, s - nums[idx], ans);
            find(nums, idx + 1, s + nums[idx], ans);
        }
    }
};
// @lc code=end
