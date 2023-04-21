/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                markValid(board, m, n, i, 0);

            if (board[i][n - 1] == 'O')
                markValid(board, m, n, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
                markValid(board, m, n, 0, i);

            if (board[m - 1][i] == 'O')
                markValid(board, m, n, m - 1, i);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    } 

private:
    void markValid(vector<vector<char>> &board, int m, int n, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
        {
            return;
        }
        board[i][j] = 'Y';
        markValid(board, m, n, i - 1, j);
        markValid(board, m, n, i + 1, j);
        markValid(board, m, n, i, j - 1);
        markValid(board, m, n, i, j + 1);
    }
};

int main(int argc, char **argv)
{
    vector<vector<char>> board = {{'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}, {'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}};
    Solution s;
    s.solve(board);
    return 0;
}
// @lc code=end
