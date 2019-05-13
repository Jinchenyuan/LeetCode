#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates1(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (!i || n > nums[i-1])
                nums[i++] = n;
        return i;
    }
    int removeDuplicates2(vector<int>& nums) {
        int length = (nums.size() > 0) ? 1 : 0;
        std::vector<int>::iterator pos = nums.begin();
        for (std::vector<int>::iterator iter = nums.begin(); iter < nums.end(); ++iter)
        {
            if (iter != nums.begin())
            {
                if (*pos != *iter)
                {
                    *(pos+1) = *iter;
                    pos++;
                    length++;
                }
            }
        }
        return length;
    }
    int removeDuplicates3(vector<int>& nums) {
        int len = nums.size();
        int cnt = 0;
        vector<int>::iterator idx = nums.begin();
        while(idx != nums.end()){
            int val = *idx;
            idx++;
            while (idx != nums.end() && val == *(idx))
            {
                cnt++;
                idx = nums.erase(idx);
            }
        }
        return (len - cnt);
    }
};