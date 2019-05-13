#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int split(vector<int> &nums, int m, int sum)
    {
        ll temp = 0;
        int cnt = 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            temp += 1LL * nums[i];
            if (temp > sum) {
                temp = 1LL * nums[i];
                cnt++;
                if (cnt > m)
                    return 0;
            }
        }
        return 1;
    }

    int splitArray(vector<int>& nums, int m) {
        ll left = 0, right = 0;
        for(size_t i = 0; i < nums.size(); i++)
        {
            left = max(left, 1LL * nums[i]);
            right += 1LL * nums[i];
        }
        if (nums.size() == m)
            return left;
        if (m == 1)
            return right;
        while(left < right){
            ll mid = (left + right) >> 1;
            if (split(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};