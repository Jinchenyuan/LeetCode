#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
class Solution {
private:
    void swap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    void sortbubbling(vector<int> &nums, int start, int end)
    {
        for (int i = start; i < end; i++)
        {
            for (int j = i + 1; j < end; j++)
            {
                if (nums[i] > nums[j])
                {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }

    void sortquick(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return;
        int midl = start, midr = start;
        for (int i = start + 1; i < end; i++)
        {
            if (nums[i] < nums[midr])
            {
                if (i == midr + 1)
                {
                    swap(nums[i], nums[midl]); 
                }
                else
                {
                    swap(nums[i], nums[midr + 1]);
                    swap(nums[midl], nums[midr + 1]);
                }
                midl++;
                midr++;
            }
            else if (nums[i] == nums[midr])
            {
                if (i > midr + 1)
                {
                    swap(nums[i], nums[midr + 1]);
                }
                midr++;
            }
        }
        sortquick(nums, start, midl);
        sortquick(nums, midr + 1, end);
    }

public:
    void sortColors(vector<int>& nums) {
        // sortbubbling(nums, 0, nums.size());
        sortquick(nums, 0, nums.size());
    }
};

int main(void)
{
    vector<int> v;
    int t[] = {2, 0, 2, 1, 1, 0};
    for (size_t i = 0; i < 6; i++)
    {
        v.push_back(t[i]);
    }
    Solution s;
    s.sortColors(v);
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
