#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <fstream>
using namespace std;

class Solution {
public:
    int groupNum(vector<int>& nums) {
        int ret = 0;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        for (size_t i1 = 0; i1 < nums.size() - 3; ++i1)
        {
            temp.push_back(nums[i1]);
            for (size_t i2 = i1 + 1; i2 < nums.size() - 2 ; i2++)
            {
                temp.push_back(nums[i2]);
                for (size_t i3 = i2 + 1; i3 < nums.size() - 1 ; i3++)
                {
                    temp.push_back(nums[i3]);
                    for (size_t i4 = i3 + 1; i4 < nums.size(); i4++)
                    {
                        temp.push_back(nums[i4]);
                        if (temp.size() == 4 && std::accumulate(temp.begin(), temp.end(), 0) <= 9)
                        {
                            cout << i1 + 1 << " :" << temp[0] << ", " << i2 + 1 << " :" << temp[1] << ", "  << i3  + 1 << " :" << temp[2] << ", " << i4 + 1 << ": " << temp[3] << endl;
                            ret++;
                        }
                        temp.pop_back();
                    }
                    temp.pop_back();
                }
                temp.pop_back();
            }
            temp.pop_back();
        }
        return ret;
    }
    int groupNum2(vector<int>& nums) {
        int ret = 0;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        ofstream myCout("D:\\Projects\\github\\LeetCode\\temp.txt");
        for (size_t i1 = 0; i1 < nums.size() - 3; ++i1)
        {
            temp.push_back(nums[i1]);
            for (size_t i2 = i1 + 1; i2 < nums.size() - 2 ; i2++)
            {
                temp.push_back(nums[i2]);
                for (size_t i3 = i2 + 1; i3 < nums.size() - 1 ; i3++)
                {
                    temp.push_back(nums[i3]);
                    for (size_t i4 = i3 + 1; i4 < nums.size(); i4++)
                    {
                        temp.push_back(nums[i4]);
                        if (temp.size() == 4)
                        {
                            if (temp[0] + temp[1] == 9 && temp[2] + temp[3] == 9
                            || temp[0] + temp[2] == 9 && temp[1] + temp[3] == 9
                            || temp[0] + temp[3] == 9 && temp[1] + temp[2] == 9)
                            {
                                myCout << i1 + 1 << " :" << temp[0] << ", " << i2 + 1 << " :" << temp[1] << ", "  << i3  + 1 << " :" << temp[2] << ", " << i4 + 1 << ": " << temp[3] << endl;
                                ret++;
                            }
                        }
                        temp.pop_back();
                    }
                    temp.pop_back();
                }
                temp.pop_back();
            }
            temp.pop_back();
        }
        myCout.close();
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<int> ret = {0,1,2,2,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,8,8,8,9,9,10,10,11,12};
    int num = s.groupNum2(ret);
    cout << num << endl;
    return 0;
}