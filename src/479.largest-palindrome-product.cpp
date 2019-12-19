/*
 * @lc app=leetcode id=479 lang=cpp
 *
 * [479] Largest Palindrome Product
 */

// @lc code=start
//TODO 并没有解决问题
#include <iostream>
#include <deque>
using namespace std;

const int STEP = 10;
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 0)
            return 0;
        int max = 1;
        for (size_t i = 0; i < n; i++)
        {
            max *= 10;
        }
        int min = max / 10;
        max = max - 1;
        return findMaxPalindrome(max, min) % 1337;
    }
private:
    long long  findMaxPalindrome(int max, int min)
    {
        if (max < min)
            return 0;
        long long maxPal = 0;
        for (int i = max; i > (max - STEP); --i)
        {
            for (int j = i; j > (max - STEP); --j)
            {
                long long tmp = (long long)j * (long long)i;
                if (isPalindrome(tmp) && (tmp > maxPal))
                {
                    maxPal = tmp;
                }
            }
        }
        if (maxPal > 0)
            return maxPal;
        else
            return findMaxPalindrome(max - STEP, min);
    }

    deque<long long> int2array(long long n)
    {
        deque<long long> ret;
        if (n == 0)
        {
            ret.push_back(0);
            return ret;
        }
        long long p = 1;
        while (n / p > 0)
        {
            ret.push_front((n % (p * 10)) / p);
            p *= 10;
        }
        return ret;
    }
    bool isPalindrome(long long n)
    {
        deque<long long> vec = int2array(n);
        int left = 0, right = vec.size() - 1;
        while (left <= right)
        {
            if (vec[left++] != vec[right--])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

