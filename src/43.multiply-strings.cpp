/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <iostream>
using namespace std;
class Solution
{
public:
    /**
     * 在常规算术的方式有所升级，用一变量保存每次相乘的值
     * 每一次相乘的位数根据乘数的位置计算得出（避免了常规思维依次相加）
     * 保证以上两点，即可达到本题目的最优时间复杂度 O(n^2)
     * */
    string multiply1(string num1, string num2)
    {
        if (num1.empty() || num2.empty())
            return "";

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        std::string res(num1.size() + num2.size(), '0');
        for (int j = 0; j < num2.size(); j++)
        {
            int tmp = 0;
            int val = num2[j] - '0';
            for (int i = 0; i < num1.size(); i++)
            {
                tmp += (num1[i] - '0') * val + (res[i + j] - '0');
                res[i + j] = tmp % 10 + '0';
                tmp /= 10;
            }
            if (tmp != 0)
                res[num1.size() + j] = tmp + '0';
        }
        std::reverse(res.begin(), res.end());
        int count = 0;
        while (count < res.size() - 1 && res[count] == '0')
            count++;
        res.erase(0, count);
        return res;
    }
    /**
     * 常规算术思维，各个位数依次相乘，每次的结果相加
     * 
     * */
    string multiply2(string num1, string num2)
    {
        string ret = "0";
        size_t len1 = num1.length();
        size_t len2 = num2.length();
        if (len1 == 0 || len2 == 0)
        {
            return ret;
        }
        int multInt = 0;
        for (int i = len1 - 1; i >= 0; i--)
        {
            char single = num1[i];
            if (single > '0' && single <= '9')
            {
                string multStr = mult(single, num2);
                backZero(multStr, multInt);
                ret = add(ret, multStr);
            }
            multInt++;
        }
        return ret;
    }

private:
    string mult(char single, string str)
    {
        string ret = "";
        size_t len = str.length();
        int idx = 1;
        int carryBit = 0;
        while (idx <= len || carryBit > 0)
        {
            int num = 0;
            if (idx <= len)
                num = str[len - idx] - '0';
            carryBit += num * (single - '0');
            ret = static_cast<char>(carryBit % 10 + '0') + ret;
            carryBit /= 10;
            idx++;
        }
        return ret;
    }
    string add(string str1, string str2)
    {
        string ret = "";
        size_t len1 = str1.length();
        size_t len2 = str2.length();
        int idx = 1;
        int carryBit = 0;
        while (idx <= len1 || idx <= len2 || carryBit > 0)
        {
            int num1 = 0, num2 = 0;
            if (idx <= len1)
                num1 = str1[len1 - idx] - '0';
            if (idx <= len2)
                num2 = str2[len2 - idx] - '0';
            carryBit += num1 + num2;
            ret = static_cast<char>(carryBit % 10 + '0') + ret;
            carryBit /= 10;
            idx++;
        }
        return ret;
    }
    void backZero(string &str, int num)
    {
        if (str.length() > 0 && str[0] > '0')
            for (int i = 0; i < num; i++)
                str.push_back('0');
    }
};

int main(void)
{
    string str1 = "24265476547365";
    string str2 = "23658657987623425435";
    Solution s;
    cout << s.multiply1(str1, str2) << endl;
    return 0;
}
// @lc code=end
