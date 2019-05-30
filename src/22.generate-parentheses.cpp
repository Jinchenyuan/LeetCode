#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution {
private:
    void push(int left, int right, vector<string> &ret, string &str)
    {
        if (right <= 0)
        {
            ret.push_back(str);
            return;
        } 
        if (left == right)
        {
            str += "(";
            push(--left, right, ret, str);
        }
        else if(left < right)
        {
            if (left > 0)
            {
                string tmp = str.substr(0, str.size());
                int tmpl = left, tmpr = right;
                string strl = tmp + "(";
                push(--left, right, ret, strl);
                string strr = tmp + ")";
                push(tmpl, --tmpr, ret, strr);
            }
            else if(left == 0)
            {
                str += ")";
                push(left, --right, ret, str);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n <= 0)
            return ret;
        string str = "";
        push(n, n, ret, str);
        return ret;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    int num = 1;
    if (argc > 1)
        num = atoi(argv[1]);
    vector<string> ret = s.generateParenthesis(num);
    for (size_t i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << endl;
    }
    return 0;
}
