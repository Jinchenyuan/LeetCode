/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> v)
{
    cout << "[";
    for (size_t k = 0; k < v.size(); k++)
    {
        if (k != v.size() - 1)
            cout << v[k] << ", ";
        else
            cout << v[k];
        
    }
    cout << "]" << endl;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ret;
        vector<int> find;
        findNext(nums, 0, ret, find, target);
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }

private:
    void findNext(vector<int> &nums, int idx, vector<vector<int>> &ret, vector<int> &find, int target) {
        if (find.size() == 4)
        {
            int sum = 0;
            for (size_t i = 0; i < find.size(); i++)
            {
                sum += find[i];
            }
            if (sum == target)
            {
                sort(find.begin(), find.end());
                ret.push_back(find);
            }

            return;
        }
        else
        {
            vector<int> newFind;
            newFind.assign(find.begin(), find.end());

            if (idx >= nums.size())
            {
                return;
            }
            newFind.push_back(nums[idx]);
            findNext(nums, idx + 1, ret, find, target);
            findNext(nums, idx + 1, ret, newFind, target);
        }   
    }
};

int main(void)
{
    vector<int> tv = { 1, 0, -1, 0, -2, 2 };
    Solution s;
    s.fourSum(tv, 0);
    return 0;
}
// @lc code=end

