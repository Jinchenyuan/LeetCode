#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
private:
    string strtbl[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void get(vector<string> strv, vector<int> visited, vector<string> &ret)
    {
        string str = "";
        for (int i = 0; i < visited.size(); i++)
            str += strv[i].at(visited[i]);
        ret.push_back(str);
    }
    bool run(vector<int> &visited, vector<int> sign, int idx)
    {
        if (idx < 0)
            return false;
        visited[idx]--;
        if (visited[idx] < 0)
        {
            visited[idx] = sign[idx];
            return run(visited, sign, idx - 1);
        }
        return true;
    }
    
    void addDigit(int digit, vector<string>& result, vector<string>& map) {
        if (map[digit].size() == 0) {
            return;
        }
        if (result.size() == 0) {
            for (int i = 0; i < map[digit].size(); i++) {
                string x = "";
                x = x + map[digit][i];
                result.push_back(x);
            }
        } else {
            int size = result.size();
            for (int i = 0; i < size; i++) {
                //取值
                string temp = result[0];
                //erase
                result.erase(result.begin());
                //添加
                for (int j = 0; j < map[digit].size(); j++) {
                    string x(temp);
                    x = x + map[digit][j];
                    result.push_back(x);
                }
            }
        }
    }
    vector<string> buildMap() {
        vector<string> map(10);
        map[0] = "";
        map[1] = "";
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        return map;
    }
public:
    vector<string> letterCombinations1(string digits) {
        vector<string> ret;
        vector<string> strv;
        vector<int> visited;
        vector<int> sign;
        for (int i = 0; i < digits.size(); i++)
        {
            int num = digits.at(i) - '0';
            if (num < 2 || num > 9)
                return ret;
            strv.push_back(strtbl[num]);
            sign.push_back(strtbl[num].size() - 1);
            visited.push_back(strtbl[num].size() - 1);
        }
        if (strv.size() < 1)
            return ret;
        visited[visited.size() - 1]++;
        while (run(visited, sign, sign.size() - 1))
            get(strv, visited, ret);
        return ret;
    }
    vector<string> letterCombinations2(string digits) {
        vector<string> result;
        vector<string> map = buildMap();
        for (int i = 0; i < digits.size(); i++) {
            int digit = digits[i] - '0';
            addDigit(digit, result, map);
        }
        return result;
    }
};

int main(void)
{
    Solution s;
    vector<string> ret = s.letterCombinations("23");
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}
