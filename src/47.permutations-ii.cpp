#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    vector<vector<int> > res;
    void dfs(vector<int> &nums, int cnt, vector<bool> &visited, vector<int> &local)
    {
        if(cnt == nums.size())
        {
            res.push_back(local);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if(i != 0 && nums[i] == nums[i-1] && visited[i-1] == false)
                continue;
            if (visited[i])
                continue;
            visited[i] = true;
            local.push_back(nums[i]);
            dfs(nums, cnt + 1, visited, local);
            local.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int> local;
        dfs(nums, 0, visited, local);
        return res;
    }
};
int main(void)
{
    int t[] = {1, 2, 3, 4, 5};
    vector<int> v;
    for (size_t i = 0; i < 5; i++)
    {
        v.push_back(t[i]);
    }
    Solution s;
    vector<vector<int> > ret = s.permuteUnique(v);
    for (size_t i = 0; i < ret.size(); i++)
    {
        for (size_t k = 0; k < ret[i].size(); k++)
        {
            cout << ret[i][k] << " ";
        }
        cout << endl;
    }
}