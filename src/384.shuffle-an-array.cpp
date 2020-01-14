/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution {
public:
    Solution(vector<int> &nums) {
        srand(time(NULL));
        _data.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> tmp;
        tmp.assign(_data.begin(), _data.end());
        size_t size = tmp.size();
        for (size_t i = 1; i < size; i++)
        {
            size_t off = rand() % i + 1;
            if (off != i)
                swap(tmp[i], tmp[off]);
        }
        return tmp;
    }

private:
    vector<int> _data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

