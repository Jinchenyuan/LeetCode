#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int ans = 0;
        int tmp = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[i] == nums[i - 1] + 1)
                tmp++;
            else
            {
                ans = (tmp > ans) ? tmp : ans;
                tmp = 1;
            }
        }
        ans = (tmp > ans) ? tmp : ans;
        return ans;
    }
};

int main(void)
{
    int t[] = {1, 2, 0, 1};
    vector<int> v;
    for (int i = 0; i < 4; i++)
    {
        v.push_back(t[i]);
    }
    Solution s;
    int ret = s.longestConsecutive(v);
    cout << ret << endl;
    return 0;
}

