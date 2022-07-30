/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        int a = 1, b = 0, op = -1;
        int q1 = reader.query(0,1,2,3), q2 = reader.query(1,2,3,4);
        auto update = [&](int q1, int q2, int idx) {
            if(q1 == q2) a++;
            else {
                b++; op = idx;
            }
        };
        update(q1,q2,4);
        q1 = reader.query(0,2,3,4);
        update(q1,q2,1);
        q1 = reader.query(0,1,3,4);
        update(q1,q2,2);
        q1 = reader.query(0,1,2,4);
        update(q1,q2,3);
        q1 = reader.query(0,1,2,3);
        int p = 5;
        
        while(p < n) {
            q2 = reader.query(1,2,3,p);
            update(q1,q2,p);
            p++;
        }
        
        if(a > b) return 0;
        else if(a < b) return op;
        else return -1;
    }
};