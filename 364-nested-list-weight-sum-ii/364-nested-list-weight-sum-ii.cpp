/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    map<int, list<int>> m;
    bool hasInteger(vector<NestedInteger>& n) {
        for(auto& ni : n) {
            if(ni.isInteger()) return true;
        }
        return false;
    }
    int takeOff(vector<NestedInteger> n) {
        if(n.size() == 1 && !n[0].isInteger()) return takeOff(n[0].getList());
        return getSum(n);
    }
    void buildMap(vector<NestedInteger> n, int depth) {
        for(auto& ni : n) {
            if(ni.isInteger()) m[depth].push_back(ni.getInteger());
            else buildMap(ni.getList(), depth + 1);
        }
    }

    int getSum(vector<NestedInteger> n) {
        m.clear();
        buildMap(n, 1);
        if(m.empty()) return 0;
        int reverse = prev(m.end())->first + 1;
        int res = 0;
        for(auto& e : m) {
            for(auto& val : e.second) {
                res += (reverse - e.first) * val;
            }
        }
        return res;
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        return takeOff(nestedList);
    }
};