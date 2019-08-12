#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

class Tire
{
public:
    Tire *next[26];
    bool isWord;
    string *word;

    Tire(): next{nullptr}, isWord(false)
    {
    }

    static void add(Tire *root, string &word)
    {
        auto cur = root;
        for (auto c : word)
        {
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new Tire();
            cur = cur->next[c - 'a'];
        }
        cur->isWord = true;
        cur->word = &word;
    }
};

class Solution {
public:
    vector<string> findWords1(vector<vector<char>>& board, vector<string>& words) {
        auto root = new Tire();
        for (auto &word : words)
            Tire::add(root, word);
        vector<string> ans;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (root->next[board[i][j] - 'a'])
                    dfs_wordSearch(i, j, root->next[board[i][j] - 'a'], board, vis, ans);
            }
        }
        return ans;
    }

    void dfs_wordSearch(int i, int j, Tire *cur, vector<vector<char>> &board, vector<vector<bool>> &vis, vector<string> &ans)
    {
        static int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        if (cur->isWord)
        {
            ans.push_back(*cur->word);
            cur->isWord = false;
        }
        vis[i][j] = 1;
        for (auto &d : dirs)
        {
            int nx = i + d[0], ny = j + d[1];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !cur->next[board[nx][ny] - 'a'] || vis[nx][ny])
                continue;
            dfs_wordSearch(nx, ny, cur->next[board[nx][ny] - 'a'], board, vis, ans);
        }
        vis[i][j] = 0;
    }

    vector<string> findWords2(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for (vector<string>::iterator ite = words.begin(); ite != words.end(); ite++)
        {
            if (exist(board, *ite))
            {
                ans.push_back(*ite);
            }
        }
        return ans;
    }

    bool search(vector<vector<char>>& board, string &word, int i, int j, int pos) {
        if (pos == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        bool ans = false;
        if (board[i][j] == word[pos])
        {
            char t = board[i][j];
            board[i][j] = '\0';
            ans = search(board, word, i + 1, j, pos + 1) ||
                  search(board, word, i, j + 1, pos + 1) ||
                  search(board, word, i - 1, j, pos + 1) ||
                  search(board, word, i, j - 1, pos + 1);
            board[i][j] = t;
        }
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if (row == 0)
            return false;
        int col = board[0].size();
        if (col == 0)
            return false;
        if (word.size() == 0)
            return true;

        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j) {
                if(search(board, word, i, j, 0))
                    return true;
            }
        return false;
    }
};

