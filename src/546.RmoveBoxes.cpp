#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        unordered_map<int, int> memo;
        return dfs(boxes, memo, n, 0, n-1, 0);
    }
private:
    int dfs(vector<int>& boxes, unordered_map<int, int>& memo, int n, int l, int r, int k){
        if (l > r)
            return 0;
        int key = (l * n + r) * n + k;
        if (memo.find(key) != memo.end())
            return memo[key];
        while (l < r && boxes[r] == boxes[r - 1])
        {
            r--;
            k++;
        }
        while (l < r && boxes[l] == boxes[r]) {
            l++;
            k++;
        }
        key = (l * n + r) * n + k;
        memo[key] = dfs(boxes, memo, n, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++)
        {
            if (boxes[i] == boxes[r]) {
                while (i+1 < r && boxes[i+1] == boxes[r])
                    i++;
                memo[key] = max(memo[key], dfs(boxes, memo, n, l, i, k + 1) + dfs(boxes, memo, n, i + 1, r - 1, 0));
            }
        }
        return memo[key];
    }
};