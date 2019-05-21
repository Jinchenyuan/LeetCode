#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
class Solution {
private:
    bool check(vector<vector<int> > visited, vector<vector<char> >& board, string word, int i, int j, int m, int n, int idx)
    {
        // cout << "i=" << i << " j=" << j << " baord[i][j]=" << board[i][j] << " (idx - 1)=" << idx - 1 << " word[idx - 1]=" << word.at(idx - 1) << endl;
        if (idx == word.size())
            return true;
        bool up = false, down = false, left = false, right = false;
        //up
        if (i - 1 >= 0 && visited[i - 1][j] == 0)
        {
            if (board[i - 1][j] == word.at(idx))
            {
                visited[i - 1][j] = 1;
                up = check(visited, board, word, i - 1, j, m, n, idx + 1);
                visited[i - 1][j] = 0;
                if (up)
                    return true;
            }
        }
        //down
        if (i + 1 < m && visited[i + 1][j] == 0)
        {
            if (board[i + 1][j] == word.at(idx))
            {
                visited[i + 1][j] = 1;
                down = check(visited, board, word, i + 1, j, m, n, idx + 1);
                visited[i + 1][j] = 0;
                if (down)
                    return true;
            }
        }
        //left
        if (j - 1 >= 0 && visited[i][j - 1] == 0)
        {
            if (board[i][j - 1] == word.at(idx))
            {
                visited[i][j - 1] = 1;
                left = check(visited, board, word, i, j - 1, m, n, idx + 1);
                visited[i][j - 1] = 0;
                if (left)
                    return true;
            }
        }
        //right
        if (j + 1 < n && visited[i][j + 1] == 0)
        {
            if (board[i][j + 1] == word.at(idx))
            {
                visited[i][j + 1] = 1;
                right = check(visited, board, word, i, j + 1, m, n, idx + 1);
                visited[i][j + 1] = 0;
                if (right)
                    return true;
            }
        }
        return false;
    }
    ing &word, int i, int j, int pos) {
10
​
11
        if (pos == word.size()) return true;
12
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
13
        bool ans = false;

public:
    bool exist2(vector<vector<char> > &board, string word)
    {
        if (board.size() == 0)
            return false;
        if (board[0].size() == 0)
            return false;
        if (word.size() == 0)
            return false;

        int m = board.size(), n = board[0].size(), len = word.size();
        vector<vector<int> > visited;
        for (int i = 0; i < m; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
            {
                tmp.push_back(0);
            }
            visited.push_back(tmp);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word.at(0))
                {
                    visited[i][j] = 1;
                    if (check(visited, board, word, i, j, m, n, 1))
                        return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};

void print_vv(vector<vector<char> > vv)
{
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
        cout << "]" << endl;
    }
}

int main(void)
{
    vector<vector<char> > vv;

    vector<char> v1;
    v1.push_back('A');
    v1.push_back('B');
    v1.push_back('C');
    v1.push_back('E');
    vv.push_back(v1);
    vector<char> v2;
    v2.push_back('S');
    v2.push_back('F');
    v2.push_back('E');
    v2.push_back('S');
    vv.push_back(v2);
    vector<char> v3;
    v3.push_back('A');
    v3.push_back('D');
    v3.push_back('E');
    v3.push_back('E');
    vv.push_back(v3);

    string word("ABCESEEEFS");
    Solution s;
    bool ret = s.exist(vv, word);
    print_vv(vv);
    cout << word << endl;
    cout << "ret:" << ret << endl;
    return 0;
}
