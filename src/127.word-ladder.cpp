/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
	int ladderLength1(string beginWord, string endWord, vector<string>& wordList)
	{
		if (beginWord == endWord) return 1;
        unordered_map<string, int> visited(wordList.size() << 1);
        
        for(auto && x : wordList) 
            visited[x] = 0;
        
        if (!visited.count(endWord))
            return 0;
        
        visited[beginWord] = 1;
        visited[endWord] = 2;
        queue<pair<string, int>> q1, q2;
        q1.push({beginWord, 1});
        q2.push({endWord, 1});
        while(!q1.empty() && !q2.empty()) {
            decltype(q1) * l1ptr = q1.size() < q2.size() ? &q1 : &q2;
            decltype(q2) * l2ptr = l1ptr == &q1 ? &q2 : &q1;
            string & word = l1ptr->front().first;
            for(int i = 0; i < word.size(); i ++) {
                char temp = word[i];
                for(char c = 'a'; c <= 'z'; ++ c) {
                    if (c != temp) {
                        word[i] = c;
                        auto it = visited.find(word);
                        if (it != visited.end()) {
                            if (it -> second == 0) {
                                word[i] = c;
                                l1ptr->push({word, l1ptr->front().second + 1});
                                it -> second = (l1ptr == &q1 ? 1 : 2);
                            } else if (it -> second == (l1ptr == &q1 ? 2 : 1)) {
                                word[i] = c;
                                while(l2ptr->front().first != word) {
                                    l2ptr->pop();
                                }
                                return l1ptr->front().second + l2ptr->front().second;
                            }
                        }
                    }
                }
                word[i] = temp;
            }
            l1ptr -> pop();
        }
        return 0;
	}

	int ladderLength2(string beginWord, string endWord, vector<string>& wordList)
	{
		int endIdx = checkValid(endWord, wordList);
		if (endIdx == -1 || beginWord.size() != endWord.size() || beginWord == endWord)
			return 0;
		vector<int> bDiff = findOneBitDifference(beginWord, wordList);
		if (bDiff.size() < 1)
			return 0;
		int ans = INT_MAX;
		vector<int> dp(wordList.size(), -1);
		vector<int> nextDiff(1, endIdx);
		dp[endIdx] = 0;
		do
		{
			nextDiff = findNext(nextDiff, wordList, dp);
		} while (nextDiff.size() > 0);
		for (size_t i = 0; i < bDiff.size(); i++)
		{
			if (ans > dp[bDiff[i]] && dp[bDiff[i]] > -1)
				ans = dp[bDiff[i]];
		}
		return ans == INT_MAX ? 0 : (ans + 2);
	}

private:
	vector<int> findNext(vector<int> startVec, vector<string>& wordList, vector<int>& dp)
	{
		vector<int> ret;
		for (size_t i = 0; i < startVec.size(); i++)
		{
			for (size_t j = 0; j < wordList.size(); j++)
			{
				if ((dp[j] > 0 && dp[j] > dp[startVec[i]] + 1) || dp[j] == -1)
				{
					if (isCoustomBitDiff(wordList[startVec[i]], wordList[j]))
					{
						dp[j] = (dp[startVec[i]] == -1) ? 1 : (dp[startVec[i]] + 1);
						ret.push_back(j);
					}
				}
			}
		}
		return ret;
	}

	vector<int> findOneBitDifference(string str, vector<string>& wordList)
	{
		vector<int> ret;
		for (size_t i = 0; i < wordList.size(); i++)
		{
			if (isCoustomBitDiff(str, wordList[i]))
				ret.push_back(i);
		}
		return ret;
	}

	int checkValid(string endWord, vector<string>& wordList)
	{
		for (size_t i = 0; i < wordList.size(); i++)
		{
			if (endWord == wordList[i])
				return i;
		}
		return -1;
	}

	bool isCoustomBitDiff(string str1, string str2, int num = 1)
	{
		if (str1.size() != str2.size())
			return false;
		int difCnt = 0;
		for (size_t i = 0; i < str1.size(); i++)
		{
			if (str1[i] != str2[i])
			{
				difCnt++;
				if (difCnt > num)
					return false;
			}
		}
		return difCnt == num;
	}
};

int main(void)
{
	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
	string beginWord("hit");
	string endWord("cog");
	Solution s;
	int ret = s.ladderLength1(beginWord, endWord, wordList);
	cout << ret << endl;
	return 0;
}
