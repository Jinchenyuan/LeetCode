/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
#include <iostream>
using namespace std;
class Solution
{
public:
    //牛顿迭代法
    int mySqrt1(int x)
    {
        long r = x;
        long a = x;
        while (r * r > x)
        {
            r = (r + a / r) / 2;
        }
        return r;
    }
    //普通二分法
    int mySqrt2(int x)
    {
        if (x == 1)
            return 1;
        int left = 0, right = x;
        long long mid = (left + right) / 2;
        while (left + 1 < right)
        {
            if (mid * mid > x)
            {
                right = mid;
            }
            else if (mid * mid < x)
            {
                left = mid;
            }
            else
            {
                break;
            }
            mid = (left + right) / 2;
        }
        return mid;
    }
};
int main(void)
{
    Solution s;
    cout << s.mySqrt1(4) << endl;
    return 0;
}
// @lc code=end
