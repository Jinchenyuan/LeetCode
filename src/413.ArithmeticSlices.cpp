#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0;
        int tmp = 0;
        if (A.size() < 3)
            return cnt;
        for (size_t i = 2; i < A.size(); i++)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                tmp = tmp == 0 ? 3 : (tmp + 1);
            else
            {
                if (tmp >= 3)
                    cnt += ((tmp - 2) * (tmp - 1) / 2);
                tmp = 0;
            }
        }
        if (tmp >= 3)
            cnt += ((tmp - 2) * (tmp - 1) / 2);
        return cnt;
    }
};