/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

void dump(const vector<vector<string>> &strs)
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

void dump(const vector<string> &strs)
{
    for (size_t j = 0; j < strs.size(); j++)
    {
        cout << "[" << strs[j] << "]" << "\t";
    }
    cout << endl;
	
}
class Solution {
private:
    bool static compare(string str1, string str2)
    {
        return str1.size() < str2.size();
    }
public:
	
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
		unordered_map<string, vector<string>> set;
		for (string& s : strs) {
			string s_copy = s;
			sort(s_copy.begin(), s_copy.end());

			set[s_copy].emplace_back(std::move(s)); 
		}
		ans.reserve(set.size());
		for (auto& pair : set) {
			vector<string>& anagrams = pair.second;
			ans.emplace_back(std::move(anagrams)); 
		}
        return ans;
    }

    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
		vector<vector<string>> ans;
        sort(strs.begin(), strs.end(), compare);
		for (size_t i = 0; i < strs.size();)
		{
			size_t len = strs[i].size();
			vector<vector<string>> tmp;
			vector<string> tmp1;
			tmp1.push_back(strs[i++]);
			tmp.push_back(tmp1);
			while (i < strs.size() && strs[i].size() == len)
			{
				size_t j = 0;
				for (; j < tmp.size(); j++)
				{
					if (match(tmp[j][0], strs[i]))
					{
						tmp[j].push_back(strs[i]);
						break;
					}
				}
				if (j == tmp.size())
				{
					vector<string> tmp2;
					tmp2.push_back(strs[i]);
					tmp.push_back(tmp2);
				}
				i++;
			}
			for (size_t k = 0; k < tmp.size(); k++)
			{
				ans.push_back(tmp[k]);
			}
		}
		return ans;
    }
	
private:
	bool match(string str1, string str2)
	{
		if (str1.length() != str2.length())
			return false;
		int size = str1.length();
		if (size == 0)
			return true;
		for (size_t i = 0; i < size; i++)
		{
			size_t j = 0;
			for (; j < size; j++)
			{
				if (str2[j] > 'z')
					continue;
				if (str1[i] == str2[j])
				{
					str2[j] += 30;
					break;
				}
			}
			if (j == size)
				return false;
		}
		return true;
	}
};

int main(void)
{
vector<string> strs = {"bac", "ab", "kf"};
	Solution s;
	vector<vector<string>> ret = s.groupAnagrams(strs);
	dump(ret);
	return 0;
}
