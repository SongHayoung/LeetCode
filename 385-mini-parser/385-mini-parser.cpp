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
    NestedInteger createRecursively(string &s, int &pos) {
        int val = 0;
        bool flag = false, valueFlag = false;
        NestedInteger nestedInteger;
        for (; pos < s.length(); pos++) {
            if (s[pos] == '[') {
                ++pos;
                nestedInteger.add(createRecursively(s, pos));
            } else if (s[pos] == ']') {
                if (valueFlag)
                    nestedInteger.add(flag ? -val : val);
                return nestedInteger;
            } else if (s[pos] == ',') {
                if (valueFlag)
                    nestedInteger.add(flag ? -val : val);
                val = 0;
                flag = valueFlag = false;
            } else if (s[pos] == '-'){
                flag = true;
            } else {
                valueFlag = true;
                val = (val << 3) + (val << 1) + (s[pos] & 0b1111);
            }
        }
        return nestedInteger;
    }

public:
    NestedInteger deserialize(string s) {
        int pos = 1;
        return s[0] == '[' ? createRecursively(s, pos) : NestedInteger(stoi(s));
    }
};