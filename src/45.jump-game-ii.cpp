/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int step = 0, disMin = 0, disMax = 0;
        while (disMax < nums.size() - 1)
        {
            int newDisMin = -1, newDisMax = -1;
            for (int i = disMin; i <= disMax; i++)
            {
                newDisMin = newDisMin < 0 ? (1 + i) : min(newDisMin, 1 + i);
                newDisMax = newDisMax < 0 ? nums[i] + i : max(newDisMax, nums[i] + i);
            }
            disMin = newDisMin;
            disMax = newDisMax;
            step++;
        }
        return step;
    }
};

int main(void)
{
    vector<int> nums = {1, 2};
    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}
// @lc code=end

