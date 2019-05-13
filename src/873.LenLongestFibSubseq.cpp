#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int lenLongestFibSubseq1(vector<int>& A) {
        int N = A.size();
        unordered_map<int, int> index;
        for (int i = 0; i < N; ++i)
            index[A[i]] = i;

        unordered_map<int, int> longest;
        int ans = 0;
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < k; ++j) {
                if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
                    int i = index[A[k] - A[j]];
                    longest[j * N + k] = longest[i * N + j] + 1;
                    ans = max(ans, longest[j * N + k] + 2);
                }
            }

        return ans >= 3 ? ans : 0;
    }
    
    int lenLongestFibSubseq2(vector<int>& A) {
        int N = A.size();
        unordered_set<int> S(A.begin(), A.end());
        int ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j) {
                int x = A[j], y = A[i] + A[j];
                int length = 2;
                while (S.find(y) != S.end()) {
                    int z = x + y;
                    x = y;
                    y = z;
                    ans = max(ans, ++length);
                }
            }
        return ans >= 3 ? ans : 0;
    }

    int lenLongestFibSubseq3(vector<int>& A) {
        int num = 0;
        int len = A.size();
        for(int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len - 1; j++)
            {
                int temp_i = i;
                int temp_j = j;
                int temp = 0;
                int k = j + 1;
                while (k < len)
                {
                    if (A[temp_i] + A[temp_j] == A[k])
                    {
                        temp_i = temp_j;
                        temp_j = k;
                        temp = temp == 0 ? 3 : (temp + 1);
                    }
                    k++;
                }
                num = max(temp, num);
            }
        }
        return num;
    }
};