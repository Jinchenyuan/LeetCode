/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
/**
 * 有两种求解思路：
 * 1）采用递归，不断缩减 s 和 wordDict，直到无法缩减，时间复杂度O(n^2)
 * 2）采用动态规划，wordDict每一个符合条件的string，对于它的后续来说无论求解多少次，
 * 解都是相同的，因此可以采用动态规划,时间复杂度O(n)~O(n^2)之间
 * 
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<vector<string>> dict(26);
        for (int i = 0; i < wordDict.size(); ++i)
            dict[wordDict[i][0] - 'a'].push_back(wordDict[i]);
        for (int i = 0; i < 26; ++i)
            sort(dict[i].begin(), dict[i].end());
        vector<string> ans;
        vector<int> dp(s.length(), -1);
        if (judge(s, 0, dict, dp))
        {
            vector<string> one_ans;
            breaking(s, 0, dict, one_ans, ans);
        }
        return ans;
    }

private:
    void breaking(const string &s, const int &here, vector<vector<string>> &dict, vector<string> &one_ans, vector<string> &ans)
    {
        if (here == s.length())
        {
            string temp = "";
            for (int i = 0; i < one_ans.size(); ++i)
            {
                if (i > 0)
                    temp += ' ';
                temp += one_ans[i];
            }
            ans.push_back(temp);
            return;
        }
        else
        {
            int match = 0;
            while ((match = nextMatch(s, here, dict, match)) != -1)
            {
                one_ans.push_back(dict[s[here] - 'a'][match]);
                breaking(s, here + dict[s[here] - 'a'][match].length(), dict, one_ans, ans);
                one_ans.pop_back();
                ++match;
            }
            return;
        }
    }

    bool judge(const string &s, const int &here, vector<vector<string>> &dict, vector<int> &dp)
    {
        if (here == s.length())
            return true;
        else if (dp[here] != -1)
            return dp[here] == 1;
        else
        {
            bool result = false;
            int match = 0;
            while ((match = nextMatch(s, here, dict, match)) != -1)
            {
                result = result || judge(s, here + dict[s[here] - 'a'][match].length(), dict, dp);
                if (result)
                    break;
                else
                    ++match;
            }
            dp[here] = result ? 1 : 0;
            return result;
        }
    }

    int nextMatch(const string &s, const int &here, vector<vector<string>> &dict, int match)
    {
        int index = s[here] - 'a';
        if (match == dict[index].size())
            return -1;
        else
            for (int i = match; i < dict[index].size(); ++i)
            {
                int result = s.compare(here, dict[index][i].length(), dict[index][i]);
                if (result == 0)
                    return i;
                else if (result < 0)
                    break;
            }
        return -1;
    }
};

void dump(vector<string> words)
{
    cout << "------------------------" << endl;
    for (size_t i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
    cout << "------------------------" << endl
         << endl;
}

int main(void)
{
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    Solution so;
    vector<string> ret = so.wordBreak(s, wordDict);
    dump(wordDict);
    dump(ret);
    return 0;
}
// @lc code=end
