class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
       if (m <= 0 || n <= 0)
           return 0;
       int dp[50][50] = {};
       for (int k = 0; k < N; k++)
       {
           int prior[50] = {};
           for (int i = 0; i < m; i++)
           {
               for (int j = 0; j < n; j++)
               {
                   unsigned int paths = 0;
                   paths += (i == 0 ? 1 : prior[j]);
                   paths += (j == 0 ? 1 : prior[j - 1]);
                   paths += (i == m - 1 ? 1 : dp[i + 1][j]);
                   paths += (j == n - 1 ? 1 : dp[i][j + 1]);
                   paths %= 1000000007;
                   prior[j] = dp[i][j];
                   dp[i][j] = paths;
               }
           }
        }
        return dp[i][j];
    }
};