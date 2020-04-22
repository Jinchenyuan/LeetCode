/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (k > n || n <= 0 || k <= 0) {
            return ret;
        }

        vector<int> moveVec;
        for (size_t i = 1; i <= k; i++) {
            moveVec.push_back(i);
        }
        
        do 
        {
            vector<int> tmp;
            tmp.assign(moveVec.begin(), moveVec.end());
            ret.push_back(tmp);
        }while ( move(moveVec, n, k) );

        return ret;
    }

private:
    bool move(vector<int> &vec, int n, int k)
    {
        int idx = k - 1, max = n;
        while (idx >= 0)
        {
            if (vec[idx] < max) {
                vec[idx]++;
                goto CAN_MOVE;
            }
            else {
                max = vec[idx] - 1;
                idx--;
            }
        }

        return false;

    CAN_MOVE:
        int val = vec[idx];
        for (int i = idx + 1; i < k; i++) {
            vec[i] = ++val;
        }
        return true;
    }
};

int main(void)
{
    Solution s;
    s.combine(4, 2);
    return 0;
}
// @lc code=end

