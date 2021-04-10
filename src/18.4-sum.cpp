/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vv(vector<vector<int> > vv)
{
    cout << "[ ";
    for (size_t i = 0; i < vv.size(); i++)
    {
        cout << "[";
        for (size_t k = 0; k < vv[i].size(); k++)
        {
            if (k != vv[i].size() - 1)
                cout << vv[i][k] << ", ";
            else
                cout << vv[i][k];
            
        }
        if (i != vv.size() - 1)
            cout << "], ";
        else
           cout << "]";
    }
    cout << " ]" << endl;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4) {
            return ret;
        }
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;
                }
                int left = j + 1, right = length - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ret;
    }
};

int main(void)
{
    vector<int> tv = { 1, 0, -1, 0, -2, 2 };
    Solution s;
    print_vv(s.fourSum(tv, 0));
    return 0;
}
// @lc code=end

