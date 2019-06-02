#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
private:
    int travel(vector<int> height, int &ret, int start, int end)
    {
        if (start == end)
            return -1;
        int tmp = 0;
        int hight = 0;
        int hidx = -1;
        int i = start;
        for (;;)
        {
            if (start < end && i > end)
                break;
            else if (start > end && i < end)
                break;
            if (hight == 0)
            {
                if (height[i] > 0)
                {
                    hight = height[i];
                    hidx = i;
                }
            }
            else if (hight > 0)
            {
                if (height[i] > 0)
                {
                    if (height[i] >= hight)
                    {
                        ret += tmp;
                        tmp = 0;
                        hight = height[i];
                        hidx = i;
                    }
                    else
                    {
                        tmp += (hight - height[i]);
                    }
                }
                else
                {
                    tmp += hight;
                }
            }
            if (start < end)
                i++;
            else
                i--;
        }
        if (tmp > 0 && hidx >= 0)
            return hidx;
        return -1;
    }

public:
    int trap1(vector<int>& height) {
        const int sz = height.size();
        int ret = 0;
        if (sz < 2)
            return ret;
        int L = 0, R = sz - 1, maxL = height[L], maxR = height[R];
        while (L < R)
        {
            if (height[L] < height[R]) {
                if (height[L] > maxL)
                    maxL = height[L];
                else
                    ret += maxL - height[L];
                L++;
            }
            else
            {
                if (height[R] > maxR)
                    maxR = height[R];
                else
                    ret += maxR - height[R];
                R--;
            }
        }
        return ret;
    }

    int trap2(vector<int>& height) {
        int ret = 0;
        if (height.size() <= 0)
            return ret;
        int idx = travel(height, ret, 0, height.size() - 1);
        if (idx >= 0)
            travel(height, ret, height.size() - 1, idx);
        return ret;int main(void)
{
    vector<int> v;
    int t[] = {7, 1, 0, 2, 1, 4, 1, 3, 2, 1, 2, 1};
    for (size_t i = 0; i < 12; i++)
    {
        v.push_back(t[i]);
    }
    Solution s;
    int ret = s.trap(v);
    cout << ret << endl;
    return 0;
}
    }
};

int main(void)
{
    vector<int> v;
    int t[] = {7, 1, 0, 2, 1, 4, 1, 3, 2, 1, 2, 1};
    for (size_t i = 0; i < 12; i++)
    {
        v.push_back(t[i]);
    }
    Solution s;
    int ret = s.trap1(v);
    cout << ret << endl;
    return 0;
}

