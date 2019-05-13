#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubstring1(string s, int k) {
        int n = s.size(), max_idx = 0, res = 0;
        int m[128] = {0};
        bool ok = true;
        for (char c : s)
            ++m[c];
        for (int i = 0; i < n; ++i)
        {
            if (m[s[i]] < k) {
                res = max(res, longestSubstring1(s.substr(max_idx, i - max_idx), k));
                ok = false;
                max_idx = i + 1;
            }
        }
        return ok ? n : max(res, longestSubstring1(s.substr(max_idx, n - max_idx), k));
    }

    int longestSubstring2(string s, int k) {
        if(k <= 0)
            return s.size();
        if (s.size() < k)
            return 0;

        int flags[26];
        for(size_t i = 0; i < 26; i++)
        {
            flags[i] = 0;
        }
        for(size_t i = 0; i < s.size(); i++)
        {
            flags[s.at(i) - 'a']++;
        }
        vector<char> cv;
        for (size_t i = 0; i < 26; i++)
        {
            if (flags[i] > 0 && flags[i] < k) {
                cv.push_back(i + 'a');
                break;
            }
        }
        int len = s.size();
        vector<int> idxv;
        for (size_t i = 0; i < s.size(); i++)
        {
            for(size_t j = 0; j < cv.size(); j++)
            {
                if (s.at(i) == cv[j]) {
                    idxv.push_back(i);
                }
            }
        }
        if (idxv.size() > 0)
        {
            len = 0;
            for (size_t i = 0; i < idxv.size(); i++)
            {
                if (i == 0)
                {
                    len = max(longestSubstring2(s.substr(0, idxv[i]), k), len);
                }
                else
                {
                    len = max(longestSubstring2(s.substr(idxv[i - 1] + 1, idxv[i] - idxv[i - 1]), k), len);
                }
            }
            int last = longestSubstring2(s.substr(idxv[idxv.size() - 1] + 1, s.size() - idxv[idxv.size() - 1]), k);
            len = max(last, len);
        }
        return len;
    }

    int longestSubstring3(string s, int k) {
        if(k <= 0)
            return s.size();
        if (s.size() < k)
            return 0;

        int flags[26];
        for(size_t i = 0; i < 26; i++)
        {
            flags[i] = 0;
        }
        for(size_t i = 0; i < s.size(); i++)
        {
            flags[s.at(i) - 'a']++;
        }
        char c = -1;
        for (size_t i = 0; i < 26; i++)
        {
            if (flags[i] > 0 && flags[i] < k) {
                c = i + 'a';
                break;
            }
        }
        int len = s.size();
        int idx = -1;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s.at(i) == c) {
                idx = i;
                break;
            }
        }
        if (idx >= 0)
        {
            int l = longestSubstring3(s.substr(0, idx), k);
            int r = longestSubstring3(s.substr(idx + 1, s.size() - idx), k);
            len = max(l, r);
        }
        return len;
    }
};