#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
class MinStack {
private:
    int _minv;
    int _minn;
    int _maxv;
    int _maxn;
    vector<int> _intv;

public:
    /** initialize your data structure here. */
    MinStack() {
        _minn = 0;
        _minv = INT32_MAX;
        _maxn = 0;
        _maxv = INT32_MIN;
    }

    void push(int x) {
        _intv.push_back(x);
        if (_minn != 0)
        {
            if (x < _minv)
            {
                _minn = 1;
                _minv = x;
            }
            else if (x == _minv)
            {
                _minn++;
            }
        }
        else
        {
            _minn++;
            _minv = x;
        }

        if (_maxn != 0)
        {
            if (x > _maxv)
            {
                _maxn = 1;
                _maxv = x;
            }
            else if (x == _maxv)
            {
                _maxn++;
            }
        }
        else
        {
            _maxn++;
            _maxv = x;
        }
    }

    void pop() {
        
        if (_intv.size() > 0)
        {
            int tmp = _intv.back();
            _intv.pop_back();
            if (tmp == _minv)
            {
                _minn--;
            }
            if (tmp == _maxv)
            {
                _maxn--;
            }
            if (_minn == 0 || _maxn == 0)
            {
                _minn = 0;
                _minv = INT32_MAX;
                _maxn = 0;
                _maxv = INT32_MIN;
                for (int i = 0; i < _intv.size(); i++)
                {
                    int tmp = _intv[i];
                    if (tmp < _minv)
                    {
                        _minn = 1;
                        _minv = tmp;
                    }
                    else if (tmp == _minv)
                    {
                        _minn++;
                    }
                    if (tmp > _maxv)
                    {
                        _maxn = 1;
                        _maxv = tmp;
                    }
                    else if (tmp == _maxv)
                    {
                        _maxn++;
                    }
                }
            }
        }
    }
    
    int top() {
        if (_intv.size() > 0)
            return _intv.back();
        else
            return INT32_MIN;
    }

    int getMin() {
        return _minv;
    }
};

int main(void)
{
    MinStack* obj = new MinStack();
    obj->push(-3);
    obj->push(0);
    obj->push(-2);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

