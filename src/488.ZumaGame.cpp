#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int aux(string s, vector<int>& c) {
    if (s.empty()) return 0;
    int res = 2 * s.length() + 1;
    for (int i = 0; i < s.length();)
    {
        int j = i++;
        while (i < s.length() && s[i] == s[j])
            i++;
        int inc = 3 - i + j;
        if (c[s[j]] >= inc)
        {
            int used = inc <= 0 ? 0 : inc;
            c[s[j]] -= used;
            int temp = aux(s.substr(0, j) + s.substr(i), c);
            if (temp >= 0)
                res = min(res, used + temp);
            c[s[j]] += used;
        }
        }
        return res == 2 * s.length() + 1 ? -1 : res;
    }
    int findMinStep(string board, string hand) {
        vector<int> c(128);
        for (char x : hand)
        {
            c[x]++;
        }
        return  aux(board, c);
    }
};