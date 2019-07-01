#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 1)
            return -1;
        if (nums.size() == 1)
            return 0;
        if (nums.size() == 2)
            return nums[0] > nums[1] ? 0 : 1;
        if (nums[0] > nums[1])
            return 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }
        if (nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;
        return -1;
    }
};


int main(void)
{
    int t[] = {1, 2, 1, 3, 5, 6, 4};
    vector<int> v;
    for (size_t i = 0; i < 7; i++)
    {
        v.push_back(t[i]);
    }
    Solution s;
    int ret = s.findPeakElement(v);
    cout << "ret:" << ret << endl;
    return 0;
}
