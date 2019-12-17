/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool containsDuplicate1(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
                return true;
        }
        return false;
    }
    bool containsDuplicate2(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};
// @lc code=end

