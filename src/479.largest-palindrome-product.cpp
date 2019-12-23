/*
 * @lc app=leetcode id=479 lang=cpp
 *
 * [479] Largest Palindrome Product
 */

// @lc code=start
//TODO 并没有解决问题
/**
 * 以下参考的他人的做法，纯数学技巧，本人数学欠佳，后续有时间再学习。
 * 
 * */
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int largestPalindrome(int n) {
        long maxNum = pow(10, n) - 1;
        long maxPal = 0;
        long half = maxNum-1;
        
        if (1 == n)
        {
            return 9;
        }
        
        if (0 == (n % 2))
        {
            long peer = maxNum + 2 - pow(10, n / 2);
            maxPal = peer * maxNum;
            half = 0;
        }
        
        while (half)
        {
            long full = genPalindrome(half);
            long root = sqrt(full);
            bool flag = false;
            
            for (long n1 = maxNum; root <= n1; --n1)
            {
                if (full % n1)
                {
                    continue;
                }
                
                flag = true;
                maxPal = full;
                break;
            }
            
            if (flag)
            {
                break;
            }    
            half--;
        }
        return maxPal % 1337;
    }

private:

    long genPalindrome(long num)
    {
        stringstream ss;
        string s = to_string(num);
        long res;
        
        ss<<s;
        reverse(s.begin(), s.end());
        ss<<s;
        
        ss>>res;
        return res;
    }
};
// @lc code=end

