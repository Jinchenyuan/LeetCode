#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
private:
    int integerDivide(long n){
        int num = 0;
        while(n > 1 && n % 2 == 0){
            n = n / 2;
            num++;
        }
        if (n == 1)
            return num;
        if (n % 2 == 1){
            num++;
            num += min(integerDivide(long(n) + 1), integerDivide(long(n) - 1));
        }
        return num;
    }
public:
    int integerReplacement1(long n) {
        if (n == INT_MAX)
            return 32;
        int ans = 0;
        while (n != 1) {
            if ((n&1) == 0)
                n >>= 1;
            else if (n != 3 && (n + 1) % 4 == 0)
                n++;
            else
                n--;
            ans++;
        }
        return ans;
    }
    int integerReplacement2(long n) {
        int num = 0;
        while (n > 1 && n % 2 == 0)
        {
            n = n / 2;
            num++;
        }
        if (n == 1)
            return num;
        if (n % 2 == 1) {
            num++;
            num += min(integerReplacement2(n + 1), integerReplacement2(n - 1));
        }
        return num;
    }
    int integerReplacement3(int n) {
        int num = 0;
        if (n == 1)
            return num;

        if (n % 2 == 1){
            num++;
            num += min(integerDivide(long(n) + 1), integerDivide(long(n) - 1));
        }
        else
        {
            num = integerDivide(long(n));
        }
        return num;
    }
};