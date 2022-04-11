/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
class Solution {
    int binarySearch(BinaryMatrix& b, int l, int r, int ans, int row) {
        int first = b.get(row, 0), last = b.get(row, r - 1);
        if(!first && !last) return INT_MAX;
        if(first) return 0;
        int res = INT_MAX;
        do {
            int m = (l + r) / 2, n = b.get(row, m);
            if(!n && m >= ans) return INT_MAX;
            if(n) res = min(res, r = m);
            else l = m;
        } while(l + 1 < r);
        return res;
    }
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> rowAndCol = binaryMatrix.dimensions();
        int r = rowAndCol[0], c = rowAndCol[1], res = INT_MAX;
        for(int i = 0; i < r; i++) {
            res = min(res, binarySearch(binaryMatrix, 0, c, res, i));
        }
        return res == INT_MAX ? - 1 : res;
    }
};
