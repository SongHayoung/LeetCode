/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int p;
    bool nxt;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), p(nums[0]), nxt(nums.size() > 1) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return p;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int res = p;
        if(Iterator::hasNext()) {
            p = Iterator::next();
        }
        else nxt = false;
        return res;
	}
	
	bool hasNext() const {
	    if(Iterator::hasNext()) return true;
        else if(nxt) return true;
        return false;
	}
};