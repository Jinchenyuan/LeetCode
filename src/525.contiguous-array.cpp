/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> arr(2 * nums.size() + 1, -2);
        arr[nums.size()] = -1;
        int maxLen = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count = count + (nums[i] == 0 ? -1 : 1);
            if (arr[count + nums.size()] >= -1) {
                maxLen = max(maxLen, i - arr[count + nums.size()]);
            } else {
                arr[count + nums.size()] = i;
            }
        }
        return maxLen;
    }
};
// @lc code=end

