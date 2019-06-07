#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if (size == 0)
        {
            digits.push_back(1);
            return digits;
        }
        for (int i = size - 1; i >= 0; i--)
        {
            digits[i] += 1;
            if (digits[i] >= 10)
            {
                digits[i] = 0;
                if(i == 0)
                {
                    vector<int>::iterator it = digits.begin();
                    digits.insert(it, 1);
                    return digits;
                }
            }
            else
            {
                return digits;
            }
        }
        return digits;
    }
};

int main(void)
{
    vector<int> digits;
    digits.push_back(4);
    digits.push_back(3);
    digits.push_back(2);
    digits.push_back(1);
    Solution s;
    vector<int> ret = s.plusOne(digits);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}

