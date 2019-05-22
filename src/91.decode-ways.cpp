#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
class Solution {
private:
    int divide(string s, int start, int end, bool branch)
    {
        if (start > end)
            return 0;
        int ret = 0;
        int svalue = stoi(s.substr(start, 1));
        int dvalue = stoi(s.substr(start, 2));
        if (start == end )
        {
            if (svalue > 0 && svalue <= 26 && !branch)
                ret++;
        }
        else if(end > start)
        {
            ret += divide(s, start + 1, end, branch);
            if (dvalue > 0 && svalue <= 26)
                ++ret += divide(s, start + 2, end, true);
        }
        return ret;
    }

public:
    int numDecodings(string s) {
        return divide(s, 0, s.size() - 1, false);
    }
};

int main(void)
{
    string a = "12234352";
    Solution s;
    int ret = s.numDecodings(a);
    cout << ret << endl;
    return 0;
}
