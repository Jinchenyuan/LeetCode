#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
template<typename T>
void show(vector<vector<T>> grid)
{
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n---------------------" << endl;
}

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() < 1)
            return 0;
        if (grid[0].size() < 1)
            return 0;
        size_t m = grid.size();
        size_t n = grid[0].size();
        vector<vector<int>> record = {m, vector<int>(n, 0)};
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
               if (record[i][j] == 0 && grid[i][j] == '1')
               {
                    ans++;
                    traverse(grid, record, m, n, i, j, grid[i][j]);
               } 
           }
        }
        return ans;
    }
    void traverse(vector<vector<char>> &grid, vector<vector<int>> &record, size_t m, size_t n, int i, int j, char key)
    {
        if (record[i][j] > 0)
            return;
        record[i][j] = 1;
        //up
        if (i > 0 && grid[i - 1][j] == key)
            traverse(grid, record, m, n, i - 1, j, key);
        //left
        if (j > 0 && grid[i][j - 1] == key)
            traverse(grid, record, m, n, i ,j - 1, key);
        //right
        if (j < n - 1 && grid[i][j + 1] == key)
            traverse(grid, record, m, n, i, j + 1, key);
        //down
        if (i < m - 1 && grid[i + 1][j] == key)
            traverse(grid, record, m, n, i + 1, j, key);
    }
};

int main(void)
{
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    show(grid);
    Solution s;
    
    cout << s.numIslands(grid) << endl;

    return 0;
}
