/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ret = 1;
        map<int, int> m;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == ret)
            {
                map<int, int>::iterator ite = m.find(++ret);
                while (ite != m.end())
                {
                   ite = m.find(++ret);
                }
            }
            else if (nums[i] > ret)
            {
                m[nums[i]] = 1;
            }
        }
        
        return ret;
    }
};
// @lc code=end

