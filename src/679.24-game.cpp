/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        size_t size = nums.size();
        if (size != 4)
            return false;
        int sum = 0;
        for (size_t i = 0; i < size; i++)
        {
            sum += nums[i];
        }
        if (sum < 10)
            return false;

        sort(nums.begin(), nums.end());
        do
        {
            double a = nums[0];
            double b = nums[1];
            double c = nums[2];
            double d = nums[3];

            // 1 & 3
            vector<double> abc = calculate3(a, b, c);
            for (size_t i = 0; i < abc.size(); i++)
            {
                vector<double> abc_d = calculate2(abc[i] , d);
                for (size_t k = 0; k < abc_d.size(); k++)
                {
                    if (abs(abc_d[k] - 24) < 0.001)
                    {
                        return true;
                    }
                } 
            }

            //2 & 2
            vector<double> ab = calculate2(a , b);
            vector<double> cd = calculate2(c , d);
            for (size_t i = 0; i < ab.size(); i++)
            {
                for (size_t j = 0; j < cd.size(); j++)
                {
                    vector<double> ab_cd = calculate2(ab[i] , cd[j]);
                    for (size_t k = 0; k < ab_cd.size(); k++)
                    {
                        if (abs(ab_cd[k] - 24) < 0.001)
                        {
                            return true;
                        }
                    } 
                }
            }
            
        }while (next_permutation(nums.begin(), nums.end()));

        return false;
    }

private:
    vector<double> calculate2(double a, double b)
    {
        vector<double> v;
        v.push_back(a + b);
        v.push_back(a - b);
        v.push_back(b - a);
        v.push_back(b / a);
        v.push_back(a / b);
        v.push_back(a * b);
        return v;
    }

    vector<double> calculate3(double a, double b, double c)
    {
        vector<double> v;
        vector<double> ab = calculate2(a , b);
        vector<double> ac = calculate2(a , c);
        vector<double> bc = calculate2(b , c);

        for (size_t i = 0; i < ab.size(); i++)
        {
            vector<double> tmp = calculate2(ab[i], c);
            for (size_t j = 0; j < tmp.size(); j++)
            {
                v.push_back(tmp[j]);
            }
        }
        for (size_t i = 0; i < ac.size(); i++)
        {
            vector<double> tmp = calculate2(ac[i], b);
            for (size_t j = 0; j < tmp.size(); j++)
            {
                v.push_back(tmp[j]);
            }
        }
        for (size_t i = 0; i < bc.size(); i++)
        {
            vector<double> tmp = calculate2(bc[i], a);
            for (size_t j = 0; j < tmp.size(); j++)
            {
                v.push_back(tmp[j]);
            }
        }
        return v;
    }
};
// @lc code=end

