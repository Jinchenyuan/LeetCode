/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
       size_t len = S.length();
       size_t idx = len - 1;
       string ret;
       for (size_t i = 0; i < len; i++)
       {
           if (!((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')))
           {
               ret.push_back(S[i]);
           }
           else
           {
               while (!((S[idx] >= 'a' && S[idx] <= 'z') || (S[idx] >= 'A' && S[idx] <= 'Z')) && idx >= 0) idx--;
               
               if (idx >= 0)
               {
                   ret.push_back(S[idx]);
                   idx--;
               }
           }
       }
       return ret;
    }
};
// @lc code=end

