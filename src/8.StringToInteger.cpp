#include <iostream>
#include <string>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
class Solution {
public:
    int myAtoi1(string str) {
        if (str.empty())
            return 0;
        auto offset = 0;
        while (str[offset] == ' ' && offset < str.length())
            offset++;
        auto sign = 1;
        if (str[offset] == '-') {
            sign = -1;
            ++offset;
        }
        else if (str[offset] == '+') {
            sign = 1;
            ++offset;
        }
        auto ret = 0;
        for (auto i = offset; i < str.length(); ++i) {
            auto c = str[i];
            auto val = 0;
            if (c >= '0' && c <= '9')
                val = c - '0';
            else
                break;
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && val > 7))
                return sign > 0 ? INT_MAX : INT_MIN;
            ret *= 10;
            ret += val;
        }
        return sign * ret;
    }
    
    int myAtoi2(string str) {
        if (str.size() == 0) {
            return 0;
        }
        int ret = 0;
        int idx = 0;
        int p = 1;
        bool isStart = false;
        while(idx < str.size() && str.at(idx) == ' '){
            idx++;
        }
        for(size_t i = idx; i < str.size(); i++)
        {

            if (str.at(i) >= '0' && str.at(i) <= '9')
            {
                int pop = (str.at(i) - 48) * p;
                if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7))
                {
                    return INT_MAX;
                }
                if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && pop < -8))  
                {
                    return INT_MIN;
                }
                ret = ret * 10 + pop;
                isStart = true;
            }
            else if ((str.at(i) == '+' || str.at(i) == '-') && !isStart)
            {
                if(str.at(i) == '-')
                {
                    p = -1;
                }
                isStart = true;
            }
            else
            {
                return ret;
            }
        }
        return ret;
    }
};