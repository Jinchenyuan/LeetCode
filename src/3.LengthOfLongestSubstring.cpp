#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) 
    {
        int flags[256];
        for (int i = 0; i < 256; i++)
            flags[i] = -1;
        int longest = 0;
        int i = 0;
        int collision = -1;
        while (s[i] != 0)
        {
            if (flags[s[i]] != -1)
                collision = (collision > flags[s[i]] ? collision : flags[s[i]]);
            flags[s[i]] = i;
            longest = (i - collision > longest ? i - collision : longest);
            i++;
        }
        return longest;
    }

    int lengthOfLongestSubstring2(string s) {
        int index = 0, len = s.length();
        int maxNum = 0;
        std::map<int, char> map;
        while(index < len)
        {
            char c = s.at(index);
            for (auto it = map.begin(); it != map.end(); ++it) {
                if (it->second == c)
                {
                    map.erase(map.begin(), ++it);
                    break;
                }
            }
            
            std::pair<int, char> p(index, c);
            map.insert(p);
            
            int size = map.size();
            if (size > maxNum)
            {
                maxNum = size;
            }
            index++;
        }
        return maxNum;
    }
};