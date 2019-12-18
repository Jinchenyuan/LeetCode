/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// @lc code=start
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
#include <iostream>
#include <vector>
using namespace std;

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
	struct Data
	{
		struct Data *next;
		int val;
		Data(int v):next(NULL), val(v){}
	};
	struct Data *pHead;
	struct Data *pIndex;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), pHead(NULL), pIndex(NULL) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
		struct Data *tmp = NULL;
		for (size_t i = 0; i < nums.size(); i++)
		{
			struct Data *d = new Data(nums[i]);
			if (!pHead)
				pHead = d;
			if (!tmp)
			{
				tmp = d;
			}	
			else
			{
				tmp->next = d;
				tmp = tmp->next;
			}		
		}
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(pIndex)
		{
			if (pIndex->next)
				return pIndex->next->val;
			else
				return pIndex->val;
		}
		else
		{
			return pHead->val;
		}
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (pIndex)
		{
			if (pIndex->next)
				pIndex = pIndex->next;
		}
		else
		{
			pIndex = pHead;
		}
		return pIndex->val;
	}

	bool hasNext() const {
		if (pIndex)
			return !!(pIndex->next);
		return !!(pHead);
	}
};
// @lc code=end

