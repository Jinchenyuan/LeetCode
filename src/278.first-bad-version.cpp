/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, ret = n;
        while (left < ret)
        {
            int mid = left + ((ret - left) >> 1);
            if (isBadVersion(mid))
            {
                ret = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
