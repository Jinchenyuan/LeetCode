#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
private:
    void connect(vector<vector<int> >& srcvv, vector<int> newv)
    {
        vector<vector<int> >::iterator it;
        for (it = srcvv.begin(); it != srcvv.end(); it++)
        {
            if ((newv[0] >= (*it)[0] && newv[0] <= (*it)[1])
                || (newv[1] >= (*it)[0] && newv[1] <= (*it)[1])
                || (newv[0] < (*it)[0] && newv[1] > (*it)[1]) )
            {
                int l = min(newv[0], (*it)[0]);
                int r = max(newv[1], (*it)[1]);
                (*it)[0] = l;
                (*it)[1] = r;

                vector<vector<int> >::iterator itleft = it;
                while (itleft != srcvv.begin())
                {
                    itleft--;
                    if ((*itleft)[1] < (*it)[0])
                    {
                        break;
                    }
                    else if ((*itleft)[0] <= (*it)[0] && (*itleft)[1] >= (*it)[0])
                    {
                        (*it)[0] = (*itleft)[0];
                        break;
                    }
                    else if ((*itleft)[0] > (*it)[0])
                    {
                        itleft = srcvv.erase(itleft);
                    }
                }  
                
                vector<vector<int> >::iterator itright = it;
                while (true)
                {
                    itright++;
                    if (itright == srcvv.end())
                        break;
                    if ((*itright)[0] > (*it)[1])
                    {
                        break;
                    }
                    else if ((*itright)[0] <= (*it)[1] && (*itright)[1] >= (*it)[1])
                    {
                        (*it)[1] = (*itright)[1];
                        break;
                    }
                    else if ((*itright)[1] < (*it)[1])
                    {
                        itright = srcvv.erase(itright);
                        itright--;
                    }
                }
                
                return;
            }
            else if(newv[1] < (*it)[0])
            {
                srcvv.insert(it, newv);
                return;
            }
        }
        srcvv.push_back(newv);
    }

public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > vv;
        int size = intervals.size();
        if (size == 0)
            return vv;
        vv.push_back(intervals[0]);
        if (size == 1)
            return vv;
        for (int i = 1; i < size; i++)
        {
            connect(vv, intervals[i]);
        }
        return vv;
    }
};

int main(void)
{
    vector<vector<int> > vv;

//     vector<int> v1;
//     v1.push_back(0);
//     v1.push_back(0);
//     vv.push_back(v1);
//     vector<int> v2;
//     v2.push_back(3);
//     v2.push_back(5);
//     vv.push_back(v2);
//     vector<int> v3;
//     v3.push_back(2);
//     v3.push_back(6);
//     vv.push_back(v3);

    vector<int> v1;
    v1.push_back(0);
    v1.push_back(0);
    vv.push_back(v1);
    vector<int> v2;
    v2.push_back(6);
    v2.push_back(7);
    vv.push_back(v2);
    vector<int> v3;
    v3.push_back(3);
    v3.push_back(5);
    vv.push_back(v3);
    vector<int> v4;
    v4.push_back(2);
    v4.push_back(6);
    vv.push_back(v4);
    vector<int> v5;
    v5.push_back(8);
    v5.push_back(8);
    vv.push_back(v5);
    vector<int> v6;
    v6.push_back(9);
    v6.push_back(13);
    vv.push_back(v6);
    vector<int> v7;
    v7.push_back(1);
    v7.push_back(1);
    vv.push_back(v7);
    vector<int> v8;
    v8.push_back(2);
    v8.push_back(4);
    vv.push_back(v8);
    // vector<int> v9;
    // v9.push_back(0);
    // v9.push_back(0);
    // vv.push_back(v9);
    // vector<int> v10;
    // v10.push_back(0);
    // v10.push_back(0);
    // vv.push_back(v10);
    // vector<int> v11;
    // v11.push_back(0);
    // v11.push_back(0);
    // vv.push_back(v11);
    // vector<int> v12;
    // v12.push_back(0);
    // v12.push_back(0);
    // vv.push_back(v12);

    Solution s;
    vector<vector<int> > ret = s.merge(vv);
    for (size_t i = 0; i < ret.size(); i++)
    {
        for (size_t k = 0; k < ret[i].size(); k++)
        {
            cout << ret[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}
