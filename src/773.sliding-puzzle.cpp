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
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    Solution()
    {
        buildMap(_data);
    }

    int slidingPuzzle1(vector<vector<int>> &board) 
    {
        map<string, int>::iterator itd = _data.find(vec2str(board));
        if (itd != _data.end())
        {
            return itd->second;
        }
        return -1;
    }

    /**
     * GitHub大神解法，供学习参考
     * https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sliding-puzzle.cpp
     * 
     * */
    int slidingPuzzle2(vector<vector<int>>& board) {
        const auto& R = board.size(), &C = board[0].size();
        vector<int> begin, end;
        unordered_map<int, pair<int, int>> expected;
        int zero_idx = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                auto val = (C * i + j + 1) % (R * C);
                expected[val] = {i, j};
                if (board[i][j] == 0) {
                    zero_idx = begin.size();
                }
                begin.emplace_back(board[i][j]);
                end.emplace_back(val);
            }
        }
        
        int min_steps = heuristic_estimate(begin, R, C, expected);
        unordered_set<vector<int>, Hash<vector<int>>> lookup;
        vector<pair<int, vector<int>>> closer{make_pair(zero_idx, begin)}, detour;
        while (true) {
            if (closer.empty()) {
                if (detour.empty()) {
                    return -1;
                }
                min_steps += 2;
                swap(closer, detour);
            }
            int zero;
            vector<int> board;
            tie(zero, board) = closer.back(); closer.pop_back();
            if (board == end) {
                return min_steps;
            }
            if (!lookup.count(board)) {
                lookup.emplace(board);
                int r = zero / C;
                int c = zero % C;
                static const vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (const auto& direction : directions) {
                    int i = r + direction.first;
                    int j = c + direction.second;
                    if (0 <= i && i < R && 0 <= j && j < C) {
                        auto new_zero = C * i + j;
                        auto new_board = board;
                        swap(new_board[zero], new_board[new_zero]);
                        int r2, c2;
                        tie(r2, c2) = expected[board[new_zero]];
                        int r1 = zero / C;
                        int c1 = zero % C;
                        int r0 = new_zero / C;
                        int c0 = new_zero % C;
                        bool is_closer = dot({r1 - r0, c1 - c0}, {r2 - r0, c2 - c0}) > 0;
                        is_closer ? closer.emplace_back(new_zero, new_board) : detour.emplace_back(new_zero, new_board);
                    }
                }
            }
        }

        return min_steps;
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


    int heuristic_estimate(const vector<int>& board, int R, int C, const unordered_map<int, pair<int, int>>& expected) {
        int result = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                const auto& val = board[C * i + j];
                if (val == 0) {
                    continue;
                }
                int r, c;
                tie(r, c) = expected.at(val);
                result += abs(r - i) + abs(c - j);
            }
        }
        return result;
    }

    inline int dot(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first * b.first + a.second * b.second;
    }
                        
    template<typename ContType>
    struct Hash {
        size_t operator()(const ContType& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<typename ContType::value_type>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
};
// @lc code=end

