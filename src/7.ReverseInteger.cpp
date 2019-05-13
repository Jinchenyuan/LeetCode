#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
#define INT32_MIN -2147483648
#define INT32_MAX 2147483647
public:
    int reverse(int x) {
        long ret = 0;
        int p = 1;
        while(x != 0){
            ret = ret * p;
            ret = (ret + (x % 10));
            x = x / 10;
            p = 10;
        }
        if (ret < INT32_MIN || ret > INT32_MAX)
            return 0;
        return (int)ret;
    }
};