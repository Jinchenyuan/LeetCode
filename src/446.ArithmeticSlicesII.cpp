#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    int numberOfArithmeticSlices1(vector<int>& A) {
        int res = 0;
        int n = A.size();
        unordered_map<long long, vector<int>> nums;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            nums[A[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long num = A[j] * 2LL - A[i];
                if (nums.count(num) > 0) {
                    for (auto k : nums[num]) {
                        if (k >= j) {
                            break;
                        }
                        dp[j][i] += 1 + dp[k][j];
                    }
                }
                res += dp[j][i];
            }
        }
        return res;
    }
    int numberOfArithmeticSlices2(vector<int>& A) {
        int res = 0, n = A.size();
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j) {
                long delta = (long)A[i] - A[j];
                if (delta > INT_MAX || delta < INT_MIN)
                    continue;
                int diff = (int)delta;
                ++dp[i][diff];
                if (dp[j].count(diff))
                {
                    res += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return res;
    }
};