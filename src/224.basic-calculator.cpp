/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
/*
 * 使用栈来解答，从左到右，遇到优先级跟高的入栈
 * 结束高优先级则出栈，并且把结果再次与栈尾结算。
 * 遍历完所有符号，则栈中仅剩一个值，即为最终结果。
 * 
 * */

#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    long long val;
    int op;
};


class Solution {
public:
    int calculate(string s) {
        long long ret = 0;
        stack<Node> st;
    }
};
// @lc code=end

