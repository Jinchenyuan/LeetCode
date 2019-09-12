#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1)
        {
            return 1;
        }
        vector<int> record(n, 0);
        record[0] = 1;
        record[1] = 2;
        for (int i = 2; i < n; i++)
        {
            record[i] = record[i - 1] + record[i - 2];
        }
        return record[n - 1];
    }
};

int main(void)
{
    Solution s;
    cout << s.climbStairs(2) << endl;
    return 0;
}

