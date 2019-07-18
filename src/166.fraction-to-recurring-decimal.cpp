/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        long long int numer = numerator;
        long long int denum = denominator;
        int sign = 1;
        if (numer < 0)
        {
            sign *= -1;
            numer *= -1;
        }
        if (denum < 0)
        {
            sign *= -1;
            denum *= -1;
        }
        long long int IntPart = numer / denum;
        numer %= denum;
        if (numer == 0)
            return (sign > 0 ? "" : "-") + to_string(IntPart);
        string DecPart = "";
        unordered_map<long long int, int> map;
        int idx = 0;
        while (!map.count(numer))
        {
            map[numer] = idx;
            numer *= 10;
            int nextdigit = numer / denum;
            DecPart += '0' + nextdigit;
            numer %= denum;
            if (numer == 0)
                return (sign > 0 ? "" : "-") + to_string(IntPart) + "." + DecPart;
        }
        DecPart.insert(DecPart.begin() + map[numer], '(');
        DecPart += ")";
        return (sign > 0 ? "" : "-") + to_string(IntPart) + "." + DecPart;
    }
};

int main(void)
{
    Solution s;
    string ret = s.fractionToDecimal(1, 7);
    cout << ret.data() << endl;
    return 0;
}
