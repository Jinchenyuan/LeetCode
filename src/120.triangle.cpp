/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void print_vv(vector<vector<int>> vv)
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

class Solution
{
public:
    int minimumTotal1(vector<vector<int>> &triangle)
    {
        int length = triangle.size();
        vector<int> dp(length + 1);
        for (int i = length - 1; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
    int minimumTotal2(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp;
        for (size_t i = 0; i < triangle.size(); i++)
        {
            vector<int> dpi(triangle[i].size());
            dp.push_back(dpi);
            if (i == 0)
            {
                dp[i][0] = triangle[i][0];
                continue;
            }
            for (size_t j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    continue;
                }
                if (j == triangle[i - 1].size())
                {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }

        int ret = INT32_MAX;
        for (int i = 0; i < dp[triangle.size() - 1].size(); ++i)
        {
            if (dp[triangle.size() - 1][i] < ret)
            {
                ret = dp[triangle.size() - 1][i];
            }
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> vv = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution s;
    int ret = s.minimumTotal1(vv);
    cout << ret << endl;
    return 0;
}
// @lc code=end
