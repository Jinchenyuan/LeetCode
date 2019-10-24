/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ret;
        string tmpStr;
        int tmpSize = 0, left = 0, right = -1;
        for (size_t i = 0; i < words.size(); i++)
        {
            tmpSize += tmpSize == 0 ? words[i].length() : words[i].length() + 1;
            if (tmpSize > maxWidth)
            {
                tmpSize -= words[i].length() + 1;
                int lastBlank = maxWidth - tmpSize;
                int wordBlank = (right == left) ? lastBlank : lastBlank / (right - left);
                int unDevideBlank = (right == left) ? 0 : lastBlank % (right - left);
                tmpStr = words[left];
                for (size_t j = left + 1; j <= right; j++)
                {
                    int blankNum = wordBlank + 1;
                    if (unDevideBlank > 0)
                    {
                        blankNum++;
                        unDevideBlank--;
                    }
                    pushBack(tmpStr, words[j], blankNum);
                }
                pushBack(tmpStr, "", maxWidth - tmpStr.length());
                ret.push_back(tmpStr);
                tmpStr = "";
                tmpSize = words[i].length();
                left = right = i;
            }
            else
            {
                right++;
            }
        }
        if (tmpSize > 0)
        {
            tmpStr = words[left];
            for (size_t j = left + 1; j <= right; j++)
            {
                int blankNum = 1;
                pushBack(tmpStr, words[j], blankNum);
            }
            pushBack(tmpStr, "", maxWidth - tmpStr.length());
            ret.push_back(tmpStr);
        }
        return ret;
    }

private:
    void pushBack(string &str1, string str2, int blankNum)
    {
        string blankStr = "";
        for (size_t i = 0; i < blankNum; i++)
        {
            blankStr = blankStr + " ";
        }
        str1 = str1 + blankStr + str2;
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
    vector<string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    Solution s;
    vector<string> ret = s.fullJustify(words, 16);
    dump(words);
    dump(ret);
    return 0;
}
// @lc code=end
