/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1, add = 0;
        vector<int> ret;

        for (; i >= 0 || k || add; --i) 
        {
            add += (i < 0 ? 0 : num[i]) + k % 10;
            ret.push_back(add % 10);
            add /= 10;
            k /= 10;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};

void dump(vector<int> nums)
{
    cout << "------------------------" << endl;
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    cout << "------------------------" << endl
         << endl;
}

int main(int argc, char **argv)
{
    vector nums = {1, 2, 0, 0};
    Solution s;
    vector ret = s.addToArrayForm(nums, 34);
    dump(ret);
    return 0;
}
// @lc code=end

