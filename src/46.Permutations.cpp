#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //dfs
        //首先，固定第一个数字，递归求后序数组的全排列，
        //比如example中，递归过程为：固定1，求[2,3]的全排列，
        //然后固定2，求[1,3]的全排列，
        //固定[3],求[2,1]的全排列将结果保存，返回。
        vector<vector<int>> res;
        per(nums,0,res);
        return res;
    }
    private:
    void  per(vector<int> &nums,int level,vector<vector<int>>& res)
    {
        if(level==nums.size())
        {
            res.push_back(nums);
            return ;
        }
        for(int i=level;i<nums.size();i++)
        {
            swap(nums[i],nums[level]);
            per(nums,level+1,res);
            swap(nums[i],nums[level]);
        }
    }
};