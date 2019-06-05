#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
class Solution {
public:
    vector<vector<int>> insert1(vector<vector<int>>& intervals, vector<int> newInterval) {
        if (newInterval.size() != 2)
        {
            return intervals;
        }
        sort(newInterval.begin(), newInterval.end());
        if (intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int start = newInterval[0];
        int end = newInterval[1];
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < start) {
                ans.push_back(intervals[i]);
            }
            else if (intervals[i][0] > end) {
                vector<int> tmp;
                tmp.push_back(start);
                tmp.push_back(end);
                ans.push_back(tmp);
                copy(intervals.begin() + i, intervals.end(), back_inserter(ans));
                return ans;
            }
            else {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        vector<int> tmp;
        tmp.push_back(start);
        tmp.push_back(end);
        ans.push_back(tmp);
        return ans;
    }


    vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (newInterval.size() != 2)
        {
            return intervals;
        }
        sort(newInterval.begin(), newInterval.end());
        if (intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>>::iterator it = intervals.begin();
        int min_num = newInterval[0], max_num = newInterval[1];
        while (it != intervals.end())
        {
            //on left
            if(max_num < (*it)[0])
            {
                break;
            }
            //on right
            else if(min_num > (*it)[1])
            {
                // return;
            }
            //contain lef
            else if (min_num >= (*it)[0] && min_num <= (*it)[1])
            {
                if ((*it)[1] >= max_num)
                {
                    return intervals;
                }  
                it++;
                while (it != intervals.end())
                {
                    if ((*it)[0] > max_num)
                    {
                        it--;
                        (*it)[1] = max_num;
                        return intervals;
                    }
                    else if ((*it)[0] <= max_num && (*it)[1] >= max_num)
                    {
                        max_num = (*it)[1];
                        it = intervals.erase(it);
                        it--;
                        (*it)[1] = max_num;
                        return intervals;
                    }
                    else if ((*it)[1] < max_num)
                    {
                        it = intervals.erase(it);
                    }
                }
                it--;
                (*it)[1] = max_num;
                return intervals;
            }
            //contain right
            else if(max_num >= (*it)[0] && max_num <= (*it)[1])
            {
                if ((*it)[0] <= min_num)
                {
                    return intervals;
                } 
                if (it == intervals.begin())
                {
                    (*it)[0] = min((*it)[0], min_num);
                    return intervals;
                } 
                it--;
                while (true)
                {
                    if ((*it)[1] < min_num)
                    {
                        it++;
                        (*it)[0] = min_num;
                        return intervals;
                    }
                    else if ((*it)[0] <= min_num && (*it)[1] >= min_num)
                    {
                        min_num = (*it)[0];
                        it = intervals.erase(it);
                        it--;
                        (*it)[0] = min_num;
                        return intervals;
                    }
                    else if ((*it)[0] > min_num)
                    {
                        it = intervals.erase(it);
                        it--;
                    }
                }
                return intervals;
            }
            it++;
        }
        if (it == intervals.begin())
        {
            intervals.insert(it, newInterval);
            return intervals;
        }
        it--;
        while (true)
        {
            if(min_num > (*it)[1])
            {
                it++;
                if (it == intervals.end())
                    intervals.push_back(newInterval);
                else
                    intervals.insert(it, newInterval);
                return intervals;
            }
            else
            {
                it = intervals.erase(it);
                if (it == intervals.begin())
                {
                    intervals.push_back(newInterval);
                    return intervals;
                }
                it--;
            }
        }
    }
};

void print_vv(vector<vector<int> > vv)
{
    cout << "[ ";
    for (size_t i = 0; i < vv.size(); i++)
    {
        cout << "[";
        for (size_t k = 0; k < vv[i].size(); k++)
        {
            if (k != vv[i].size() - 1)
                cout << vv[i][k] << ", ";
            else
                cout << vv[i][k];
            
        }
        if (i != vv.size() - 1)
            cout << "], ";
        else
           cout << "]";
    }
    cout << " ]" << endl;
}

int main(void)
{
    vector<vector<int>> vv;
    
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(7);
    // vv.push_back(v1);

    vector<int> v2;
    v2.push_back(8);
    v2.push_back(10);
    // vv.push_back(v2);

    vector<int> v3;
    v3.push_back(12);
    v3.push_back(15);
    vv.push_back(v3);

    // vector<int> v4;
    // v4.push_back(12);
    // v4.push_back(13);
    // vv.push_back(v4);

    // vector<int> v5;
    // v5.push_back(16);
    // v5.push_back(19);
    // vv.push_back(v5);

    vector<int> newv;
    newv.push_back(9);
    newv.push_back(13);
    Solution s;
    vector<vector<int>> ret = s.insert(vv, newv);
    print_vv(ret);
    return 0;
}

