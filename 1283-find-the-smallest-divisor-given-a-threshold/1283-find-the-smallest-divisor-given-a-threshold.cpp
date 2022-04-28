class Solution {
    int search(vector<int>& A, int m) {
        return accumulate(begin(A), end(A), 0.0, [&](int sum, int a) {
            return sum + ceil(1.0 * a / m);
        });
    }
public:
    int smallestDivisor(vector<int>& A, int t) {
        int l = 1, r = 1e6;
        while(l <= r) {
            int m = (l + r) / 2;
            int s = search(A, m);
            if(s > t) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};