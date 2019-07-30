/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int calc_max(int i, int j, const vector<vector<int> > &matrix, vector<vector<int> > dp, int &height, int &width)
    {
        if (dp[i][j] > 0)
            return dp[i][j];
        dp[i][j] = 1;
        int maxp = 1;
        if (i > 0 && matrix[i][j] < matrix[i - 1][j])
            maxp = max(maxp, calc_max(i - 1, j, matrix, dp, height, width) + 1);
        if (i + 1 < height && matrix[i][j] < matrix[i + 1][j])
            maxp = max(maxp, calc_max(i + 1, j, matrix, dp, height, width) + 1);
        if (j > 0 && matrix[i][j] < matrix[i][j - 1])
            maxp = max(maxp, calc_max(i, j - 1, matrix, dp, height, width) + 1);
        if (j + 1 < width && matrix[i][j] < matrix[i][j + 1])
            maxp = max(maxp, calc_max(i, j + 1, matrix, dp, height, width) + 1);
        dp[i][j] = maxp;
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if (matrix.size() == 0)
            return 0;
        vector<vector<int> > dp (matrix.size(), vector<int>(matrix[0].size(), 0));
        int height = matrix.size();
        int width = matrix[0].size();
        int maxp = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                maxp = max(maxp, calc_max(i, j, matrix, dp, height, width));
            }
        }
        return maxp;
    }
};

int main(void)
{
    //[[7,8,9],[9,7,6],[7,2,3]]
    vector<vector<int> > vec;
    vector<int> vec1;
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(9);
    vector<int> vec2;
    vec2.push_back(9);
    vec2.push_back(7);
    vec2.push_back(6);
    vector<int> vec3;
    vec3.push_back(7);
    vec3.push_back(2);
    vec3.push_back(3);
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    Solution s;
    int ret = s.longestIncreasingPath(vec);
    cout << ret << endl;
    return 0;
}
