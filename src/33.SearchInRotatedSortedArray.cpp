#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
            else if(i > 0 && nums[i] < nums[i - 1] && nums[i - 1] < target)
                return -1;
        }
        return -1;
    }
};