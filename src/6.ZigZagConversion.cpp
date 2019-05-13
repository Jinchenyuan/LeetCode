#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convert1(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        std::string res;
        res.reserve(s.size());
        int interval = 2 * (numRows - 1);
        for (int i = 0; i < s.length(); i += interval)
        {
            res += s[i];
        }
        for (int row = 1; row < numRows - 1; row ++) {
            for (int i = row, j = 0; i < s.length(); j += interval, i = j - i) {
                res += s[i];
            }
        }
        if (numRows > 1) {
            for (int i = numRows - 1; i < s.length(); i += interval)
            {
                res += s[i];
            }
        }
        return res;
    }

    string convert2(string s, int numRows) {
        if (numRows == 1)
            return s;
        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }

    string convert3(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        for (string row : rows)
            ret += row;
        return ret;
    }

    string convert4(string s, int numRows) {
        if (numRows <= 1)
            return s;
        vector<char> v[numRows];
        int i = 0, j = 0, d = 1;
        for (size_t k = 0; k < s.size(); k++)
        {
            (v[i]).push_back(s.at(k));
            i += d;
            if (i == numRows || i < 0)
            {
                d *= -1;
                i += d * 2;
            }
        }
        string ret = "";
        for(size_t i = 0; i < numRows; i++)
        {
            vector<char>::iterator it;
            for (it = (v[i]).begin(); it != (v[i]).end(); it++)
            {
                if (*it > 0)
                    ret.push_back(*it);
            }
        }
        return ret;
    }
};