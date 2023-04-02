/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> countMap;
        for (int i = 0; i < arr.size(); i++) 
        {
            if (countMap.find(arr[i]) == countMap.end())
            {
                countMap[arr[i]] = 1;
            }
            else
            {
                countMap[arr[i]]++;
            }
        }

        int ret = -1;
        for (auto kv : countMap)
        {
            if (kv.first == kv.second && kv.first > ret)
            {
                ret = kv.first;
            }
        }

        return ret;
    }
};
// @lc code=end

