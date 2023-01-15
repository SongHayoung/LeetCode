/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
    int helper(ArrayReader &reader, int l, int r) {
        if(l == r) return l;
        
        int len = r - l + 1;
        if(len & 1) {
            int m = len / 2;
            int cmp = reader.compareSub(l,l + m - 1, l + m + 1, r);
            if(cmp == 0) return l + m;
            return cmp == 1 ? helper(reader, l, l + m - 1) : helper(reader, l + m + 1, r);
        } else {
            int m = len / 2;
            int cmp = reader.compareSub(l,l + m - 1, l + m, r);
            if(l + 1 == r)
                return cmp == 1 ? l : r;
            return cmp == 1 ? helper(reader, l, l + m - 1) : helper(reader, l + m, r);
        }
    }
public:
    int getIndex(ArrayReader &reader) {
        int len = reader.length();
        return helper(reader,0,len-1);
    }
};