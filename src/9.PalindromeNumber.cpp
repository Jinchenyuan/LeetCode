#include <math.h>

class Solution {
public:
    bool isPalindrome1(int x) {
        long tmp = (long)x;
        tmp = abs(tmp);
        long reverse = 0;
        while(tmp){
            reverse = reverse * 10 + (tmp % 10);
            tmp /= 10;
        }
        return reverse == x;
    }
    bool isPalindrome2(int x) {
        if (x < 0) {
            return false;
        }
        int bith = 1, bitl = 10;
        while(x/bith >= 10){
            bith *= 10;
        }
        while (bith >= bitl){
            int h = (x / bith) % 10;
            int l = (x % bitl) / (bitl / 10);
            if (h == l){
                bith /= 10;
                bitl *= 10;
            }
            else{
                return false;
            }
        }
        return true;
    }
};