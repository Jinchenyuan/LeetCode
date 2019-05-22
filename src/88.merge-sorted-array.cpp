#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
class Solution {
private:
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
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        --m;
        --n;
        while (m >= 0 && n >= 0)
        {
            if(nums1[m] > nums2[n])
            {
                nums1[pos--] = nums1[m--];
            }
            else
            {
                nums1[pos--] = nums2[n--];
            }
        }
        while (n >= 0)
        {
            nums1[pos--] = nums2[n--];
        }
    }
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        sortquick(nums1, 0, m + n);
    }
};

int main(void)
{
    
    return 0;
}

