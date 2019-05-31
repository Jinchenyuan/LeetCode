#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution {
private:
    void swap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
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
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return;
        len--;
        int pos = -1, pt = -1;
        while (len >= 1)
        {
            if (len < pos)
                break;
            for (int j = len - 1; j >=  0; --j)
            {
                if (nums[len] > nums[j])
                {
                    if(j > pos)
                    {
                        pos = j;
                        pt = len;
                    }
                }
            }
            len--;
        }
        if (pos != -1)
        {
            swap(nums[pos], nums[pt]);
            sortquick(nums, pos + 1, nums.size());
            return;
        }
        sortquick(nums, 0, nums.size());
    }
};
int main(void)
{
    vector<int> vv;
    int t[] = {1, 3, 2};
    for (size_t i = 0; i < 3; i++)
    {
        vv.push_back(t[i]);
    }
    cout << "before:" << endl;
    for (size_t i = 0; i < vv.size(); i++)
    {
        cout << vv[i] << " ";
    }
    cout << endl;
    Solution s;
    s.nextPermutation(vv);
    cout << "after:" << endl;
    for (size_t i = 0; i < vv.size(); i++)
    {
        cout << vv[i] << " ";
    }
    cout << endl;
    return 0;
}
