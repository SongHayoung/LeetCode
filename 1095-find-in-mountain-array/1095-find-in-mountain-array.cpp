/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int top(MountainArray &A, int l, int r) {
        while(l < r) {
            int m = (l + r) / 2;
            if(A.get(m) > A.get(m + 1)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    int binarySearch(MountainArray &A, int l, int r, int t) {
        while(l <= r) {
            int m = (l + r) / 2, mv = A.get(m);
            if(mv == t) return m;
            else if(mv < t) l = m + 1;
            else r = m - 1;
        }
        return - 1;
    }
    int reverseBinarySearch(MountainArray &A, int l, int r, int t) {
        while(l <= r) {
            int m = (l + r) / 2, mv = A.get(m);
            if(mv == t) return m;
            else if(mv < t) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int t, MountainArray &A) {
        int n = A.length();
        int l = 0, r = n-1, m = top(A,l,r), bs = binarySearch(A,l,m,t);
        return bs == -1 ? reverseBinarySearch(A,m+1,r,t) : bs;
    }
};