/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        int ret = 0;
        for (int i = 2; i < n; ++i) 
        {
            if (primes[i]) 
            {
                ++ret;
                for (int j = i; j < n; j += i)
                {
                    primes[j] = false;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    cout << solution.countPrimes(499979) << endl;
    return 0;
}
// @lc code=end

