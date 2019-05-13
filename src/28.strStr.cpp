#include <iostream>

using namespace std;
class Solution {
public:
    bool isMatch(string src, string pa, int idx)
    {
        int pIdx = 0;
        int len = pa.size();
        while (pIdx < len && src.at(idx) == pa.at(pIdx))
        {
            pIdx++;
            idx++;
        }
        return pIdx == len;
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        if (needle.size() > haystack.size())
            return -1;

        int ret = -1;
        for(int i = 0; i < haystack.size() - needle.size() + 1; i++)
        {
            if (isMatch(haystack, needle, i))
                return i;
        }
        return ret;
    }
};