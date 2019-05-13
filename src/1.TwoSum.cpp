#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> indices;
        int lenOfVectors = nums.size();
        bool found = false;
        vector<pair<int, int>> new_nums;
        for(int i=0; i<lenOfVectors; ++i){
            new_nums.push_back(make_pair(nums[i], i));
        }
        sort(new_nums.begin(), new_nums.end());
        int j=0, k=lenOfVectors-1;
        while(j<k){
            if(new_nums[j].first + new_nums[k].first == target){
                indices.push_back(new_nums[j].second);
                indices.push_back(new_nums[k].second);
                break;
            }
            else if(new_nums[j].first + new_nums[k].first < target){
                j++;
            }
            else{
                k--;
            }
        }
        return indices;
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        int i;
        map<int, int> hash;
        vector<int> v;
        for (i = 0; i < nums.size(); ++i)
        {
            int findNum = target - nums[i];
            if (hash.find(findNum) != hash.end())
            {
                v.push_back(i);
                v.push_back((hash.find(findNum))->second);
                return v;
            }
            pair<int, int> value(nums[i], i);
            hash.insert(value);
        }
        return v;
    }
};