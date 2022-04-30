class Solution {
    int search(vector<int>& A, int d, int k) {
        int l = 0, r = 0, sum = 0, n = A.size();
        
        while(r < n) {
            if(A[r] > d) {
                l = ++r;
            } else {
                ++r;
            }
            if(r - l == k) {
                sum++;
                l = r;
            }
        }
        
        
        return sum;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1ll * m * k > bloomDay.size()) return -1;
        int l = 1, r = INT_MAX;
        while(l <= r) {
            int d = l + (r-l) / 2;
            int s = search(bloomDay, d, k);
            if(s >= m) r = d - 1;
            else l = d + 1;
        }
        return l;
    }
};