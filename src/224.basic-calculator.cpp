/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
/*
 * 使用栈来解答，从左到右，遇到优先级跟高的入栈
 * 结束高优先级则出栈，并且把结果再次与栈尾结算。
 * 
 * */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ret = 0;
        stack<int> st;
        size_t sLen = s.size();
        int op = 1;
        for (size_t i = 0; i < sLen; ++i)
        {
            char c = s[i];
            if (c == '-')
            {
                op = -1;
            }
            else if (c == '+')
            {
                op = 1;
            }
            else if (s[i] == '(')
            {
                st.push(ret);
                st.push(op);
                ret = 0;
                op = 1;
            }
            else if (s[i] == ')')
            {
                ret *= st.top();
                st.pop();
                ret += st.top();
                st.pop();
            }
            else if (c >= '0' && c <= '9')
            {
                int num = 0;
                while (s[i] >= '0' && s[i] <= '9' && i < sLen)
                {
                    num = num * 10 + (s[i++] - '0');
                }
                ret += op * num;
                i--;
            }
        }
        
        return ret;
    }
};
// @lc code=end

