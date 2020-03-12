/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */


/**
 * 
 * 实际解题应当自己做一个hash函数来实现！！！！
 * 
 * */
// @lc code=start
#include <iostream>
#include <map>
using namespace std;
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        _map[key] = 1;
    }
    
    void remove(int key) {
        _map.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return _map.find(key) != _map.end();
    }
private:
    map<int, int> _map;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

