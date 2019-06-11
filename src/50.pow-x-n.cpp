#include <iostream>
#include <stdlib.h>
using namespace std;

/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 || x == 1.0)
            return x;
        if (n == 0)
            return 1.0;
        if (n == INT32_MIN)
        {
            double ans = myPow(x, n / 2);
            return ans * ans;
        }
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        double ans = myPow(x, n / 2);
        if (n & 1 == 1)
        {
            return ans * ans * x;
        }
        else
        {
            return ans * ans;
        }
    }
};

int main(void)
{
    Solution s;
    double ret = s.myPow(2, 4);
    cout << ret << endl;
    return 0;
}
