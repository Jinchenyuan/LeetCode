#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
class Solution {
private:
    int divide(string s, int start, int end)
    {
        if (end < 0)
            return 0;
        if (start > end)
            return 1;
        int ret = 0;
        int svalue = stoi(s.substr(start, 1));
        int dvalue = stoi(s.substr(start, 2));
        if (start == end )
        {
            if (svalue > 0 && svalue <= 26)
                return 1;
        }
        else if(end > start)
        {
            if (dvalue > 26 && dvalue % 10 == 0)
                return 0;
            if (dvalue >= 10)
                ret += divide(s, start + 1, end);
            if (dvalue >= 10 && dvalue <= 26)
                ret += divide(s, start + 2, end);
        }
        return ret;
    }

public:
    int numDecodings1(string s) {
        if(s.size() == 0 || s[0] == '0')
            return 0;
        int pre = 1, cur = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            int tmp;
            if (s[i] == '0')
            {
                if(s[i - 1] == '1' || s[i - 1] == '2')
                    tmp = pre;
                else
                    return 0;
            }
            else
            {
                if((s[i - 1] == '1' && s[i] <= '9') || (s[i - 1] == '2' && s[i] <= '6')) {
                    tmp = cur + pre;
                }
                else
                {
                    tmp = cur;
                }
            }
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
    int numDecodings2(string s) {
        return divide(s, 0, s.size() - 1);
    }
};

int main(void)
{
    string a = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";
    Solution s;
    int ret2 = s.numDecodings2(a);
    int ret1 = s.numDecodings1(a);
    cout << "right answer:" << ret2 << endl;
    cout << "test answer :" << ret1 << endl;
    return 0;
}
