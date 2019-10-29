/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (!nums.size())
            return true;
        int n = nums.size(), sum = 0;
        for (int each : nums)
        {
            sum += each;
        }
        if (sum % 2)
            return false;
        sort(nums.begin(), nums.end(), greater<int>());
        sum /= 2;
        if (nums[0] > sum)
            return false;
        return helper(nums, 0, sum);
    }

private:
    bool helper(vector<int> &nums, int x, int sum)
    {
        if ((sum - nums[x]) == 0)
            return true;
        else if ((sum - nums[x]) < 0)
            return false;
        for (int i = x + 1; i < nums.size(); ++i)
        {
            if (helper(nums, i, sum - nums[x]))
                return true;
        }
        return false;
    }
};
int main(void)
{
    vector<int> vec = {12, 23, 56, 78, 22};
    Solution s;
    cout << s.canPartition(vec) << endl;
    return 0;
}
// @lc code=end
