#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN, size = nums.size(), sum = 0;
        if (size == 0)
            return 0;
        max = nums[0];
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
            if (sum > max)
                max = sum;
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};
