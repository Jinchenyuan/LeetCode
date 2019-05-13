#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    enum DIRECTION
    {
        RIGHT = 0,
        DOWN = 1,
        LEFT = 2,
        UP = 3
    };
    void run(int m1, int m2, int n1, int n2, int direction, vector<vector<int> > matrix, vector<int> &ret)
    {
        switch (direction)
        {
        case RIGHT:
            {
                for (int i = n1; i <= n2; i++)
                    ret.push_back(matrix[m1][i]);
                m1++;
                if (m1 > m2)
                    return;
            }
            break;
        case DOWN:
            {
                for (int i = m1; i <= m2; i++)
                    ret.push_back(matrix[i][n2]);
                n2--;
                if (n2 < n1)
                    return;
            }
            break;
        case LEFT:
            {
                for (int i = n2; i >= n1; i--)
                    ret.push_back(matrix[m2][i]);
                m2--;
                if (m2 < m1)
                    return;
            }
            break;
        case UP:
            {
                for (int i = m2; i >= m1; i--)
                    ret.push_back(matrix[i][n1]);
                n1++;
                if (n1 > n2)
                    return;
            }
            break;
        }
        direction = (++direction) > UP ? RIGHT : direction;
        run(m1, m2, n1, n2, direction, matrix, ret);
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        vector<int> ret;
        int m = matrix.size(), n = 0;
        if (m > 0)
            n = matrix[0].size();
        int m1 = 0, m2 = m - 1, n1 = 0, n2 = n - 1, direction = RIGHT;
        run(m1, m2, n1, n2, direction, matrix, ret);
        return ret;
    }
};