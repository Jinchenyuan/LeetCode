/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
/**
 * 
 * leetcode 暂时没办法一次构建数据给后续使用，思路还是动态规划构建好数据，使用时按数据搜索就行
 * 
 * */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    Solution()
    {
        buildMap(_data);
    }

    int slidingPuzzle(vector<vector<int>> &board) 
    {
        map<string, int>::iterator itd = _data.find(vec2str(board));
        if (itd != _data.end())
        {
            return itd->second;
        }
        return -1;
    }

private:
    void buildMap(map<string, int> &data)
    {
        vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 0}};
        move(data, goal, 0);
    }

    void move(map<string, int> &data, vector<vector<int>> &board, int step)
    {
        //self
        map<string, int>::iterator itd = data.find(vec2str(board));
        if (itd != data.end())
        {
            if (itd->second <= step)
                return;
            else
                itd->second = step;
        }
        else
        {
            data.insert(pair<string, int>(vec2str(board), step));
        }
        int i, j;
        findZero(board, i, j);
        //up
        if (i == 1)
        {
            swap(board[i][j], board[i - 1][j]);
            move(data, board, step + 1);
            swap(board[i][j], board[i - 1][j]);
        }
        //down
        if (i == 0)
        {
            swap(board[i][j], board[i + 1][j]);
            move(data, board, step + 1);
            swap(board[i][j], board[i + 1][j]);
        }
        //left
        if (j > 0)
        {
            swap(board[i][j], board[i][j - 1]);
            move(data, board, step + 1);
            swap(board[i][j], board[i][j - 1]);
        }
        //right
        if (j < 2)
        {
            swap(board[i][j], board[i][j + 1]);
            move(data, board, step + 1);
            swap(board[i][j], board[i][j + 1]);
        }
    }

    int findZero(vector<vector<int>> const &board, int &oi, int &oj)
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 0)
                {
                    oi = i;
                    oj = j;
                    return 1;
                }
            }
        }
        return -1;
    }

    string vec2str(vector<vector<int>> const &board)
    {
        string str = "";
        for (auto v : board)
            for (auto i : v)
                str += i;

        return str;
    }

    map<string, int> _data;
};
// @lc code=end

