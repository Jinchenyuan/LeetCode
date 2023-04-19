/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ret = 0;
        while (left < right)
        {
            ret = max(ret, (right - left) * min(height[left], (height[right])));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ret;
    }
};
// @lc code=end

