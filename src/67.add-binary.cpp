/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        int aLen = a.length(), bLen = b.length();
        int carryBit = 0;
        string ret = "";
        int i = 1;

        while (aLen - i >= 0 || bLen - i >= 0 || carryBit > 0)
        {
            int sum = 0;
            if (aLen - i >= 0 && a[aLen - i] == '1')
                sum++;
        
            if (bLen - i >= 0 && b[bLen - i] == '1')
                sum++;

            sum += carryBit;
            ret = ((sum % 2) ? '1' : '0') + ret;
            carryBit = sum / 2;
            i++;
        }

        return ret == "" ? "0" : ret;
    }
};

int main(void)
{
    string a = "11", b = "1";
    Solution s;
    cout << s.addBinary(a, b) << endl;
    return 0;
}
// @lc code=end

