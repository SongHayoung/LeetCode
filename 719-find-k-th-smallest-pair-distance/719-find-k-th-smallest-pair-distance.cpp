class Solution {
public:
    int smallestDistancePair(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int n = A.size(), l = INT_MAX, r = A.back() - A[0];
        
        for(int i = 0; i < n; i++)
            l = min(l, A[i+1]-A[i]);
        
        while(l <= r) {
            int m = l + (r-l)/2, c = 0;
            
            for(int i = 0; i < n; i++) {
                c += upper_bound(begin(A) + i,end(A),A[i]+m) - (begin(A) + i) - 1;
            }
            
            if(c >= k) r = m - 1;
            else l = m + 1;
        }
        
        
        return l;
    }
};