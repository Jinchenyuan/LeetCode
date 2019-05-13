#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;


class Solution {
public:
    string longestPalindrome1(string s) {
        int n = s.size(), len = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i, right = i;
            while (right < n && s[right + 1] == s[right])
                right++;
            i = right;
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }
            if(len < right-left+1){
                len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, len);
    }

    string longestPalindrome2(string s) {
        int l = 0, r = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, size = s.size();
        for(size_t i = 0; i < size; i++)
        {
            l = i, r = i, temp3 = i, temp4 = i;
            while (l >= 0 && r < size)
            {
                if (s.at(l) == s.at(r)) {
                    temp3 = l;
                    temp4 = r;
                    l--;
                    r++;
                }
                else
                    break;
            }
            if (temp4 - temp3 > temp2 - temp1) {
                temp1 = temp3;
                temp2 = temp4;
            }
        }

        for(size_t i = 0; i < size; i++)
        {
            l = i, r = i + 1, temp3 = 0, temp4 = 0;
            while (l >= 0 && r < size)
            {
                if (s.at(l) == s.at(r)) {
                    temp3 = l;
                    temp4 = r;
                    l--;
                    r++;
                }
                else
                    break;
            }
            if (temp4 - temp3 > temp2 - temp1) {
                temp1 = temp3;
                temp2 = temp4;
            }
        }
        return s.substr(temp1, temp2 - temp1 + 1);
    }
};