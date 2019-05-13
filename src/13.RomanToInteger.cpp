#include <iostream>
#include <map>

using namespace std;
class Solution
{
public:
    int romanToInt(string s) {
        map<char, int> arr;
        arr.insert(pair<char, int>('I', 1));
        arr.insert(pair<char, int>('V', 5));
        arr.insert(pair<char, int>('X', 10));
        arr.insert(pair<char, int>('L', 50));
        arr.insert(pair<char, int>('C', 100));
        arr.insert(pair<char, int>('D', 500));
        arr.insert(pair<char, int>('M', 1000));
        int num = 0;
        int temp = 0;
        for (auto c : s)
        {
            if (arr.find(c) == arr.end())
                return 0;
            if (temp > 0 && arr.find(c)->second > temp) {
                num -= 2 * temp;
            }
            temp = arr.find(c)->second;
            num += temp;
        }
        return num;
    }
};