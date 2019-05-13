#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkValidString1(string s) {
        auto lo = 0, hi = 0;
        for (auto c : s)
        {
            if (c == '(') {
                ++lo;
                ++hi;
            }
            else if (c == ')') {
                --lo;
                --hi;
            }
            else {
                --lo;
                ++hi;
            }
            if (hi < 0) {
                return false;
            }
            if (lo < 0) {
                lo = 0;
            }
        }
        return lo == 0;
    }

    bool checkValidString2(string s) {
        if (s.empty())
            return true;
        vector<int> leftChar;
        vector<int> starChar;
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if (s.at(i) == '(')
                leftChar.push_back(i);
            else if (s.at(i) == ')')
            {
                if (leftChar.size() < 1 && starChar.size() < 1)
                    return false;
                if (leftChar.size() > 0)
                    leftChar.pop_back();
                else if (starChar.size() > 0)
                    starChar.pop_back();
            }
            else if (s.at(i) == '*')
                starChar.push_back(i);
            else
                return false;
        }
        int startIdx = starChar.size() - 1;
        while (leftChar.size() > 0)
        {
            bool isFind = false;
            for (int i = startIdx; i >= 0; i--)
            {
                if (leftChar.back() < starChar[i])
                {
                    leftChar.pop_back();
                    startIdx = i - 1;
                    isFind = true;
                    break;
                }
            }
            if (!isFind)
                return false;
        }
        return true;
    }
};