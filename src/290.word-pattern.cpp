/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> ps;
        set<string> ss;
        int idx = 0;
        for (size_t i = 0; i < pattern.length(); i++, idx++)
        {
            char c = pattern[i];
            string tmp;
            while (s[idx] != 32 && s[idx] != 0)
            {
                tmp.push_back(s[idx++]);
            }

            if (ps.find(c) != ps.end())
            {
                if (ps[c] != tmp)
                {
                    return false;
                }
            }
            else
            {
                if (ss.find(tmp) != ss.end()) {
                    return false;
                }
                ps.insert({c, tmp});
                ss.insert(tmp);
            }
        }
        if (idx != s.length() + 1)
        {
            return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    if (s.wordPattern("abba", "dog cat cat dog"))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
// @lc code=end

