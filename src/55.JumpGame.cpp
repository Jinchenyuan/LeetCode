#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int check(vector<int> nums, int idx)
    {
        int key = idx + 1;
        if (idx == nums.size() - 1)
            key = idx;
        for (int i = idx - 1; i >= 0; i--)
        {
            if (nums[i] >= (key - i))
                return i;
        }
        return -1;
    }
    bool canJump(vector<int>& nums) {
         int size = nums.size();
        if (size <= 1)
            return true;
        int ret = true;
        for (int i = size - 1; i >= 0; i--)
        {
            if (nums[i] <= 0)
            {
                i = check(nums, i) + 1;
                if (i == 0)
                {
                    ret = false;
                    break;
                }
            }   
        }
        return ret;
    }
};
