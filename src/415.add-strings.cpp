/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret = "";
        int carryBit = 0, len1 = num1.size(), len2 = num2.size(), idx = 1;
        while (len1 - idx >= 0 || len2 - idx >= 0 || carryBit > 0)
        {
            int sum = 0;
            if (len1 - idx >= 0)
            {
                sum += num1[len1 - idx] - '0';
            }
            if (len2 - idx >= 0)
            {
                sum += num2[len2 - idx] - '0';
            }
            sum += carryBit;
            ret = static_cast<char>(sum % 10 + '0') + ret;
            carryBit = sum / 10;
            idx++;
        }
        return ret == "" ? "0" : ret;
    }
};

int main(void)
{
    string str1 = "1", str2 = "1";
    Solution s;
    cout << s.addStrings(str1, str2) << endl;
    return 0;
}
// @lc code=end

