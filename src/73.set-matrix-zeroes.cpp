#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
class Solution {
public:
    void setZeroes1(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = 0;
        if (m <= 0)
            return;
        n = matrix[0].size();
        if (n <= 0)
            return;

        bool rowZero = false;
        map<int, int> columnhash;
        
        for (int i = 0; i < m; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (matrix[i][k] == 0)
                {
                    
                    if (!rowZero)
                    {
                        int l = k - 1;
                        while (l >= 0)
                            matrix[i][l--] = 0;
                        rowZero = true;
                    }
                    if (columnhash.find(k) == columnhash.end())
                    {
                        pair<int, int> value(k, 1);
                        columnhash.insert(value);
                        int u = i - 1;
                        while (u >= 0)
                            matrix[u--][k] = 0;
                    }
                    
                }
                else
                {
                    if (rowZero || columnhash.find(k) != columnhash.end())
                        matrix[i][k] = 0;
                }
            }
            rowZero = false;
        }
    }
    void setZeroes2(vector<vector<int> >& matrix) {
        if (matrix.empty())
            return;
        int lr = matrix.size();
        int lc = matrix[0].size();
        int zero_row = -1;
        for (int i = 0; i < lr; ++i) {
            if (zero_row != -1) break;
            for (int j = 0; j < lc; ++j) {
                if (matrix[i][j] == 0) {
                    zero_row = i;
                    break;
                }
            }
        }
        if (zero_row == -1)
            return;

        for (int i = zero_row + 1; i < lr; ++i) {
            bool set_zero = false;
            for (int j = 0; j < lc; ++j)
            {
                if (matrix[i][j] == 0) {
                    set_zero = true;
                    matrix[zero_row][j] = 0;
                }
            }
            if (set_zero)
                for (int j = 0; j < lc; ++j) 
                    matrix[i][j] = 0;
        }
        for (int j = 0; j < lc; ++j) {
            if (matrix[zero_row][j] == 0)
                for (int i = 0; i < lr; ++i)
                    matrix[i][j] = 0;
        }
        for (int j = 0; j < lc; ++j)
            matrix[zero_row][j] = 0;
    }

    //这个解法理解错了题目的意思，误认为是上下左右置零，不过觉得也挺有意思，就留下来了。
    void setZeroes3(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = 0;
        if (m <= 0)
            return;
        n = matrix[0].size();
        if (n <= 0)
            return;

        map<int, int> curhash;
        map<int, int> nexthash;
        map<int, int> *pcurhash = &curhash;
        map<int, int> *pnexthash = &nexthash;
        for (int i = 0; i < m; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (matrix[i][k] == 0 && pcurhash->find(k) == pcurhash->end())
                {
                    if (i > 0)
                        matrix[i - 1][k] = 0;
                    if (k > 0)
                        matrix[i][k - 1] = 0;
                    if (i + 1 < m)
                        if (matrix[i + 1][k] != 0)
                        {
                            matrix[i + 1][k] = 0;
                            pair<int, int> value(k, 1);
                            pnexthash->insert(value);
                        }
                    if (k + 1 < n)
                        if (matrix[i][k + 1] != 0)
                        {
                            matrix[i][k + 1] = 0;
                            k++;
                        }
                }
            }
            map<int, int> *ptmp;
            ptmp = pcurhash;
            pcurhash = pnexthash;
            pnexthash = ptmp;
            pnexthash->clear();
        }
    }
};

void print_vv(vector<vector<int> > vv)
{
    cout << "[ " << endl;
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
        cout << "]" << endl;
    }
    cout << " ]" << endl;
}

int main(void)
{
    vector<vector<int> > vv;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    vv.push_back(v1);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(1);
    vv.push_back(v2);
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(1);
    v3.push_back(1);
    vv.push_back(v3);


    Solution s;
    print_vv(vv);
    s.setZeroes1(vv);
    print_vv(vv);
    return 0;
}


