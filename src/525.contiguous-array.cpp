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
        if (nums.size() <= 0) return 0;
        
        int maxLen = (nums.size() / 2) * 2;
        int left = 0, right = 0;
        bool notOver = true;
        while (notOver && maxLen > 0)
        {
            right = maxLen - 1;
            for (left = 0; left < nums.size(), right < nums.size(); left++, right++)
            {
                if (isSameCount(nums, left, right))
                {
                    notOver = false;
                    break;
                }
            }
            if (notOver) maxLen -= 2;
        }

        return maxLen;
    }
private:
    bool isSameCount(vector<int>& nums, int left, int right)
    {
        int sum = 0;
        for (int i = left; i <= right; i++)
        {
            sum += nums[i];
        }
        // cout << "sum:" << sum << " left:" << left << " right:" << right << endl;
        return sum == (right - left + 1) / 2;
    }
};

int main(void)
{
    Solution s;
    vector<int> vec = {0,0,1,0,0,0,1,1};
    cout << s.findMaxLength(vec) << endl;
    return 0;
}
// @lc code=end

