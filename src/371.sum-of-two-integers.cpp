/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int c;
        while (b != 0)
        {
            c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        return a;
    }
};
int main(int argc, char **argv)
{
    Solution s;
    int sumValue = s.getSum(-1, 1);
    cout << sumValue << endl;
    return 0;
}

explain:
&       求进位
^       求当前各位值
<< 1    进位

example:
0011
0101

loop1:
c = 0011 & 0101 => 0001
a = 0011 ^ 0101 => 0110
b = 0001 << 1 => 0010

loop2:
c = 0110 & 0010 => 0010
a = 0110 ^ 0010 => 0100
b = 0010 << 1 => 0100

loop3:
c = 0100 & 0100 => 0100
a = 0100 ^ 0100 => 0000
b = 0100 << 1 => 1000

loop4:
c = 0000 & 1000 => 0000
a = 0000 ^ 1000 => 1000
b = 0000 << 1 => 0000

return a (1000)
// @lc code=end

