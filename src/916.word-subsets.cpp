/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        string strB = strMerge(B);
        
        vector<string> ret;
        for (size_t i = 0; i < A.size(); i++)
        {
            if (A[i].length() < strB.length())
                continue;

            string tmp = A[i].substr(0);
            for (size_t k = 0; k < strB.length(); k++)
            {
                if (!wordCotainChar(tmp, strB[k]))
                {
                    goto NOT_CONTAIN;
                }
            } 
            
            ret.push_back(A[i]);
NOT_CONTAIN:
            continue;
        }
        return ret;  
    }

private:
    bool wordCotainChar(string& str, char c) {
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == c)
            {
                str = str.substr(0, i) + str.substr(i + 1);
                return true;
            }
        }
        return false;
    }

    string strMerge(vector<string>& strs) {
        string ret;
        if (strs.size() > 0)
            ret = strs[0].substr(0);

        for (size_t i = 1; i < strs.size(); i++)
        {
            string tmp = ret.substr(0);
            for (size_t j = 0; j < strs[i].length(); j++)
            {
                if (!wordCotainChar(tmp, strs[i][j]))
                {
                    ret.push_back(strs[i][j]);
                }
            } 
        }
        
        return ret;
    }
};

int main(void)
{
    string str1("abc");
    string str2("bcc");
    vector<string> A;
    vector<string> B;
    A.push_back(str1);
    B.push_back(str2);
    Solution s;
    vector<string> ret = s.wordSubsets(A, B);
    for (size_t i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << endl;
    }
    return 0;
}

// @lc code=end

