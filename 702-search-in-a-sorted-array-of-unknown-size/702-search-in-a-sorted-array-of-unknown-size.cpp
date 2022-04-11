/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int st = 0, boost = 1;
        while(true) {
            int n = reader.get(st);
            if(n == target) return st;
            else if(n > target) return -1;
            else {
                while(reader.get(st + boost) <= target) {
                    boost *= 2;
                }
                st += max((boost/2), 1);
                boost = 1;
                
            }
        }
        return -1;
    }
};