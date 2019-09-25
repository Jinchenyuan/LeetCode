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
    //左耳朵耗子的解法，参见：https://github.com/haoel/leetcode/blob/master/algorithms/cpp/grayCode/grayCode.cpp
    vector<int> grayCode1(int n) {
        vector<int> ret;   
        int size = 1 << n;   
        for(int i = 0; i < size; ++i) {
            ret.push_back((i >> 1)^i);   
        }
        return ret;
    }
    vector<int> grayCode2(int n) {
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

