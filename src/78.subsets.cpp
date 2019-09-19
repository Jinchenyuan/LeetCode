/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets1(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int sub = pow(2, n);
        vector<vector<int>> ans(sub, vector<int>());
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < sub; j++)
            {
                if(j>>i & 1)
                {
                    ans[j].push_back(nums[i]);
                }
            }
        }
        return ans;
    }

    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        for (size_t i = 0; i < nums.size(); i++)
        {
            size_t ans_size = ans.size();
            for (size_t j = 0; j < ans_size; j++)
            {
                vector<int> tmp;
                tmp.insert(tmp.end(), ans[j].begin(), ans[j].end());
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

void dump(const vector<vector<int>> &strs)
{
	for (size_t i = 0; i < strs.size(); i++)
	{
		for (size_t j = 0; j < strs[i].size(); j++)
		{
			cout << "[" << strs[i][j] << "]" << "\t";
		}
		cout << endl;
	}
}

int main(void)
{
    vector<int> c = {1, 2, 3};
    Solution s;
    vector<vector<int>> ret = s.subsets1(c);
    dump(ret);
    return 0;
}
