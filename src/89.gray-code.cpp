/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n == 0) 
            return ans;   
        helper(n - 1, ans);
        return ans;
    }
    
    void helper(int end, vector<int> &ans) {
        if(end < 0) 
            return;
        for(int i = 0; i <= end; i++) {
            ans.push_back(ans.back() ^ (1 << i));
            helper(i - 1, ans);
        }
    }
};

