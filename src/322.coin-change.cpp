/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;

        for (size_t i = 1; i <= amount; i++) {
            for (size_t j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == Max ? -1 : dp[amount];
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> coins = {1, 2, 5};
    cout << s.coinChange(coins, 1) << endl;
    return 0;
}

example1:
coins (1, 2, 5) amount 1

Max = 2
dp = {0, 2}

loop amount i = 1
loop coins.size() j = 0
i >= coins[j] dp[1] = min(dp[1], dp(1 - coins[0]) + 1) = min(2, dp[1 - 1] + 1) = min[2, 1]  = 1
dp {0, 1}
return dp[1] => 1

example2:
coins (1, 2, 5) amount 2

Max = 3
dp = {0, 3, 3}

loop amount i = 1
loop coins.size() j = 0
i >= coins[j] dp[1] = min(dp[1], dp(1 - coins[0]) + 1) = min(2, dp[1 - 1] + 1) = min[2, 1]  = 1
dp {0, 1, 3}

loop amount i = 2
loop coins.size() j = 0
i >= coins[j] dp[2] = min(dp[2], dp[2 - coins[0]] + 1) = min(3, dp[1] + 1) = min(3, 2) = 2
dp {0, 1, 2}
loop coins.size() j = 1
i >= coins[j] dp[2] = min(dp[2], dp[2 - coins[1]] + 1) = min(2, dp[0] + 1) = min(2, 1) = 1
dp {0, 1, 1}

return dp[2] => 1


// @lc code=end

