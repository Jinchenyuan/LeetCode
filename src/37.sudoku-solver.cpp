/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

 // @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		map<int, vector<char>> legal;
		vector<int> keys = getLegal(board, legal);
		if (keys.size() > 0)
		{
			map<int, char> path;
			stack<int> step;
			step.push(0);
			travel(board, legal, path, keys, step);
		}
	}

private:
	void travel(vector<vector<char>>& board, map<int, vector<char>> legal, map<int, char> path, vector<int>& keys, stack<int> step)
	{
		while (true)
		{
			int pos = keys[step.size() - 1];
			char c = legal[pos][step.top()];
			if (valid(path, pos, c))
			{
				path[pos] = c;
				step.push(0);
				if (step.size() > keys.size())
				{
					break;
				}
			}
			else
			{
				int idx = step.top();
				idx++;
				if (idx >= legal[pos].size())
				{
					step.pop();
					if (!back(legal, path, keys, step))
					{
						break;
					}
				}
				else
				{
					step.pop();
					step.push(idx);
				}
			}
		}

		for (map<int, char>::iterator ite = path.begin(); ite != path.end(); ite++)
		{
			int l = (ite->first) / 10, y = (ite->first) % 10;
			board[l][y] = ite->second;
		}
	}

	bool back(map<int, vector<char>>& legal, map<int, char>& path, vector<int>& keys, stack<int>& step)
	{
		if (step.size() < 1)
		{
			return false;
		}
		int idx = step.top();
		idx++;
		int pos = keys[step.size() - 1];
		path.erase(pos);
		step.pop();
		if (idx >= legal[pos].size())
		{
			return back(legal, path, keys, step);
		}
		else
		{
			step.push(idx);
			return true;
		}

	}

	bool valid(map<int, char> path, int pos, char c)
	{
		int l = pos / 10, y = pos % 10;
		for (map<int, char>::iterator ite = path.begin(); ite != path.end(); ite++)
		{
			int lp = ite->first / 10, yp = ite->first % 10;
			if (lp == l || yp == y)
			{
				if (ite->second == c)
				{
					return false;
				}
			}
			if (lp / 3 == l / 3 && yp / 3 == y / 3)
			{
				if (ite->second == c)
				{
					return false;
				}
			}
		}

		return true;
	}

	vector<int> getLegal(vector<vector<char>>& board, map<int, vector<char>>& legal)
	{
		vector<int> ret;
		for (size_t i = 0; i < board.size(); i++)
		{
			for (size_t j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == '.')
				{
					vector<char> tmp;
					//横
					tmp.assign(board[i].begin(), board[i].end());
					//竖
					for (int k = 0; k < 9; k++)
					{
						tmp.push_back(board[k][j]);
					}
					//3x3  0 1 2 3 4 5 6 7 8
					int l = (i / 3) * 3, y = (j / 3) * 3;
					for (int k = l; k < l + 3; k++)
					{
						for (int z = y; z < y + 3; z++)
						{
							tmp.push_back(board[k][z]);
						}
					}
					int key = i * 10 + j;
					vector<char> value;
					for (int k = 0; k < 9; k++)
					{
						int valid = 1;
						for (size_t z = 0; z < tmp.size(); z++)
						{
							if ('1' + k == tmp[z])
							{
								valid = 0;
								break;
							}
						}
						if (valid)
							value.push_back('1' + k);
					}
					if (value.size() == 1)
					{
						board[i][j] = value[0];
						legal.clear();
						return getLegal(board, legal);
					}
					else if (value.size() == 0)
					{
						int i = 0;
					}

					legal[key] = value;
					ret.push_back(key);
				}
			}
		}
		return ret;
	}
};

void dump(vector<vector<char>>& board)
{
	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[i].size(); j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(void)
{
	vector<vector<char>> board1 = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'} };

	vector<vector<char>> board2 = {
		{'.','.','9','7','4','8','.','.','.'},
		{'7','.','.','.','.','.','.','.','.'},
		{'.','2','.','1','.','9','.','.','.'},
		{'.','.','7','.','.','.','2','4','.'},
		{'.','6','4','.','1','.','5','9','.'},
		{'.','9','8','.','.','.','3','.','.'},
		{'.','.','.','8','.','3','.','2','.'},
		{'.','.','.','.','.','.','.','.','6'},
		{'.','.','.','2','7','5','9','.','.'} };
	Solution s;
	s.solveSudoku(board2);
	dump(board2);
	return 0;
}
// @lc code=end

