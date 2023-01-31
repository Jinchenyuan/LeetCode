/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() <= 0)
        {
            return 0;
        }

        unordered_map<int, int> degree;
        unordered_map<int, int> sublengthsStart;
        unordered_map<int, int> sublengthsEnd;
        
        int maxDegreeValue = 0;
        int result = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) 
        {
            int key = nums[i];
            if (degree.find(key) == degree.end())
            {
                degree[key] = 1;
                sublengthsStart[key] = i;
                sublengthsEnd[key] = i;
            }
            else
            {
                degree[key]++;
                sublengthsEnd[key] = i;
            }

            if (maxDegreeValue < degree[key])
            {
                maxDegreeValue = degree[key];
                result = sublengthsEnd[key] - sublengthsStart[key] + 1;
            }
            else if (maxDegreeValue == degree[key])
            {
                result = min(result, sublengthsEnd[key] - sublengthsStart[key] + 1);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums = {1,2,2,3,1};
    cout << solution.findShortestSubArray(nums) << endl;
    return 0;
}
// @lc code=end

