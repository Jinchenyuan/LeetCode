/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

 // @lc code=start

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>> &dungeon) {

		int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        dp[m - 1][n - 1] = max(1, -dungeon[m - 1][n - 1] + 1);

        for(int i = m - 2; i >= 0; i--)
            dp[i][n - 1] = max(1, -dungeon[i][n - 1] + dp[i + 1][n - 1]);

        for(int j = n - 2; j >= 0; j--)
            dp[m - 1][j] = max(1,-dungeon[m - 1][j] + dp[m - 1][j + 1]);
        
        for(int i = m - 2; i >= 0; i--)
            for(int j = n - 2; j >= 0; j--)
                dp[i][j]= max(1, -dungeon[i][j] + min(dp[i + 1][j], dp[i][j + 1]));

        return dp[0][0];

	}
};

int main(void)
{
	vector<vector<int>> dungeon = {
		{-2, -3, 3},
		{-5, -10, 1},
		{10, 30, -5}
	};
	vector<vector<int>> dungeon2 = {
		{200}
	};
	Solution s;
	s.calculateMinimumHP(dungeon2);
}
// @lc code=end

