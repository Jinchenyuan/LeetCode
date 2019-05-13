#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
#include <limits.h>

using namespace std;

class LRUCache1 {
public:
    LRUCache1(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    HIPII cache;
    LI used;
    int _capacity;
};

class LRUCache2
{
private:
    struct Node {
        int key, value;
        struct Node *prev, *next;
    };
    int capacity, sz;
    unordered_map<int, Node *> lookup;
    Node *head, *tail;
    void update(Node *node, bool needUpdate = false, int _value = 0)
    {
        if (needUpdate) {
            node->value = _value;
        }
        if (node == tail)
            return;
        if (head == tail)
            return;
        if (head == node)
            head = head->next;
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        node->next = NULL;
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    void add(int key, int value)
    {
        // pop head if necessary
        if (sz == capacity) {
            Node *cur = lookup[head->key];
            if (head->next)
                head->next->prev = NULL;
            if (head == tail)
                head = tail = NULL;
            else
                head = head->next;
            lookup.erase(cur->key);
            free(cur);
            sz--;
        }
        // insert
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->key = key;
        newNode->value = value;
        newNode->prev = newNode->next = NULL;
        lookup[key] = newNode;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        sz++;
    }
public:
    LRUCache2(int _capacity)
    {
        capacity = _capacity;
        sz = 0;
        lookup.clear();
        head = NULL;
        tail = NULL;
    }

    int get(int key)
    {
        if (lookup.find(key) != lookup.end()) {
            update(lookup[key]);
            return lookup[key]->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (lookup.find(key) == lookup.end())
            add(key, value);
        else
            update(lookup[key], true, value);
    }
};


class LRUCache3 {
struct Node
{
    int key;
    int val;
    Node *next;
    Node *pre;
};
private:
    int _capacity;
    map<int, Node*> _data;
    bool resetKey(int key){
        map<int, Node *>::iterator it = _data.find(key);
        if (it == _data.end())
            return false;
        Node *node = it->second;
        if (node->pre)
        {
            node->pre->next = node->next;
            if (node->next)
                node->next->pre = node->pre;
            Node *p = node->pre;
            while(p->pre){
                p = p->pre;
            }
            p->pre = node;
            node->pre = NULL;
            node->next = p;
        }
        return true;
    }
    Node* findLast(){
        if (_data.size() > 0)
        {
            Node *node = _data.begin()->second;
            while(node && node->next){
                node = node->next;
            }
            return node;
        }
        return NULL;
    }
    void insertFront(Node *node){
        if (_data.size() > 0)
        {
            Node *p = _data.begin()->second;
            while(p && p->pre){
                p = p->pre;
            }
            node->next = p;
            if (p)
                p->pre = node; 
        }
        
    }

  public:
    LRUCache3(int capacity)
    {
        _capacity = capacity;
    }
    int get(int key) {
        if (_data.find(key) != _data.end())
        {
            if (resetKey(key))
                return (_data.find(key))->second->val;
            else
                return -1;
        }
        else
            return -1;
    }
    void put(int key, int value) {
        if(_data.find(key) == _data.end())
        {
            if (_data.size() >= _capacity)
            {
                Node *node = findLast();
                _data.erase(_data.find(node->key));
                if (node->pre)
                    node->pre->next = NULL;
                node->pre = NULL;
                node->next = NULL;
                node->key = key;
                node->val = value;
                insertFront(node);
                _data.insert(pair<int, Node *>(key, node));
            }
            else
            {
                Node *node = new Node;
                node->key = key;
                node->val = value;
                node->pre = NULL;
                node->next = NULL;
                insertFront(node);
                _data.insert(pair<int, Node *>(key, node));
            }
        }
        else
        {
            if (resetKey(key))
                (_data.find(key))->second->val = value;
        }
    }
};

class LRUCache4 {
private:
    struct Node
    {
        int len;
        Node *next;
        int val;
    };
    int _capacity;
    Node* _remember;
    map<int, int> _data;
    void resetRemember(int key)
    {
        Node *p = _remember;
        Node *p1 = NULL;
        while (p)
        {
            if (p->val == key) {
                if (!p1)
                {
                    Node *p2 = _remember->next;
                    if (p2)
                    {
                        p2->len = _remember->len;
                        Node *tmp = _remember;
                        _remember = p2;
                        tmp->next = NULL;
                        while (p2->next)
                        {
                            p2 = p2->next;
                        }
                        p2->next = tmp;
                    }
                }
                else
                {
                    p1->next = p->next;
                    while(p1->next){
                        p1 = p1->next;
                    }
                    p1->next = p;
                    p->next = NULL;
                }
                break;
            }
            p1 = p;
            p = p->next;
        }
    }
    void putRemember(int key, int& delKey)
    {
        int ret = -1;
        if (_remember)
        {
            if (_remember->len >= _capacity)
            {
                Node *p = _remember->next;
                if (p)
                {
                    p->len = _remember->len;
                    delKey = _remember->val;
                    _remember->val = key;
                    Node *tmp = _remember;
                    _remember = p;
                    tmp->next = NULL;
                    while (p->next)
                    {
                        p = p->next;
                    }
                    p->next = tmp;
                }
                else
                {
                    delKey = _remember->val;
                     _remember->val = key;
                }
            }
            else
            {
                Node *p = _remember;
                while (p->next)
                {
                    p = p->next;
                }
                Node *tmp = new Node;
                tmp->val = key;
                tmp->next = NULL;
                p->next = tmp;
                _remember->len += 1;
            }
        }
        else
        {       
            _remember = new Node;
            _remember->val = key;
            _remember->next = NULL;
            _remember->len = 1;
        }
    }

  public:
    LRUCache4(int capacity)
    {
        _capacity = capacity;
        _remember = NULL;
    }
    int get(int key) {
        resetRemember(key);
        if (_data.find(key) != _data.end())
            return (_data.find(key))->second;
        else
            return -1;
    }
    void put(int key, int value) {
        if(_data.find(key) == _data.end())
        {
            int del = -1;
            putRemember(key, del);
            if (del > 0)
                 _data.erase(_data.find(del));
            _data.insert(pair<int, int>(key, value));
        }
        else
        {
            resetRemember(key);
            (_data.find(key))->second = value;
        }
    }
};