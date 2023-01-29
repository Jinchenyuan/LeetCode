/*
 * @lc app=leetcode id=818 lang=cpp
 *
 * [818] Race Car
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1);
        for (int i = 1; i <= target; ++i) {
            int k = 32 - __builtin_clz(i);
            if (i == (1 << k) - 1) {
                dp[i] = k;
                continue;
            }
            dp[i] = dp[(1 << k) - 1 - i] + k + 1;
            for (int j = 0; j < k; ++j) {
                dp[i] = min(dp[i], dp[i - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
            }
        }
        return dp[target];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << 1 << ":" << s.racecar(1) << endl;
    cout << 2 << ":" << s.racecar(2) << endl;
    cout << 3 << ":" << s.racecar(3) << endl;
    cout << 4 << ":" << s.racecar(4) << endl;
    cout << 5 << ":" << s.racecar(5) << endl;
    cout << 6 << ":" << s.racecar(6) << endl;
    return 0;
}
// @lc code=end

