#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;
        int len = s.size();
        if (len % 2 != 0)
            return false;

        vector<char> v;
        for (int i = 0; i < len; i++)
        {
            if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{' )
            {
                v.push_back(s.at(i));
            }
            else if (s.at(i) == ')' || s.at(i) == ']' || s.at(i) == '}')
            {
                if (v.size() > 0 && v.back() < s.at(i) && s.at(i) - v.back() <= 2)
                    v.pop_back();
                else
                {
                    return false;
                }
                    
            }
        }
        return v.size() == 0 ? true : false;
    }

    bool isValid2(string s) {
        if (s.empty())
            return true;
        int len = s.size();
        if (len % 2 != 0)
            return false;
        bool ret = false;
        int left = 0;
        int right = left + 1;
        while(right < len){
            if (s.at(left) < s.at(right) && s.at(right) - s.at(left) <= 2)
            {
                ret = isValid2(s.substr(left + 1, right - left - 1));
                ret = (isValid2(s.substr(0, left) + s.substr(right + 1, len - right - 1)) && ret);
                break;
            }
            else if (s.at(left) == s.at(right))
                left = right;
            right++;
        }
        return ret;
    }
};