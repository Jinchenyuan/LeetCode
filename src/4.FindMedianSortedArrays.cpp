#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int tmp = m;
            m = n;
            n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j - 1] > nums1[i])
            {
                iMin = i + 1;
            }
            else if (i > iMin && nums1[i-1] > nums2[j]) {
                iMax = i - 1;
            }
            else {
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                }
                else if (j == 0) {
                    maxLeft = nums1[i - 1];
                }
                else {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }
                if ( (m + n) % 2 == 1 ) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == m) {
                    minRight = nums2[j];
                }
                else if (j == n) {
                    minRight = nums1[i];
                }
                else {
                    minRight = min(nums2[j], nums1[i]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }

    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays2(nums2, nums1);
        int i, j, imin = 0, imax = m, half = (m + n + 1) / 2;
        while (imin <= imax)
        {
            i = (imin & imax) + ((imin ^ imax) >> 1);
            j = half - i;
            if (i > 0 && j < n && nums1[i - 1] > nums2[j])
                imax = i - 1;
            else if (j > 0 && i < m && nums2[j - 1] > nums1[i])
                imin = i + 1;
            else
                break;
        }
        int num1;
        if (!i)
            num1 = nums2[j - 1];
        else if (!j)
            num1 = nums1[i - 1];
        else
            num1 = max(nums1[i - 1], nums2[j - 1]);
        if ((m + n) & 1)
            return num1;
        int num2;
        if (i == m)
            num2 = nums2[j];
        else if (j == n)
            num2 = nums1[i];
        else
            num2 = min(nums1[i], nums2[j]);
        return (num1 + num2) / 2.0;
    }

    double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0, index2 = 0;
        vector<int> temp;
        while(index1 < nums1.size() || index2 < nums2.size())
        {
            if (index1 >= nums1.size())
            {
                temp.push_back(nums2[index2]);
                index2++;
                continue;
            }
            
            if (index2 >= nums2.size())
            {
                temp.push_back(nums1[index1]);
                index1++;
                continue;
            }
            
            if (nums1[index1] <= nums2[index2])
            {
                temp.push_back(nums1[index1]);
                index1++;
            }
            else
            {
                temp.push_back(nums2[index2]);
                index2++;
            }
        }
        int size1 = temp.size();
        double ret = 0.0;
        if (size1 > 0)
        {
            if (size1 % 2 == 0)
            {
                ret = (temp[(size1 - 1) / 2] + temp[(size1) / 2]) / (double)(2.0);
            }
            else
            {
                ret = (double)temp[(size1 - 1) / 2];
            }
        }
        return ret;
    }
};