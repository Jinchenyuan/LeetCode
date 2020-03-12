/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int nr = nums.size();
        if (nr <= 0)
        {
            return nums;
        } 
        int nc = nums[0].size();
        if (nc <= 0)
        {
            return nums;
        }
        if (nr * nc !=  r * c)
        {
            return nums;
        }

        vector<vector<int>> ret;
        vector<int> tmp;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = 0; j < nums[i].size(); j++)
            {
                if (tmp.size() >= c)
                {
                    ret.push_back(tmp);
                    tmp.clear();
                }
                tmp.push_back(nums[i][j]);
            }
        }
        ret.push_back(tmp);
        
        return ret;
    }
};
// @lc code=end

