class Solution {
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
public:
    int beautifulSubsets(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int n = A.size(), res = 0;
        vector<int> bad;
        for(int i = 0; i < n; i++) {
            int mask = 0;
            for(int j = 0; j < n; j++) {
                if(abs(A[i] - A[j]) == k) mask ^= 1<<j;
            }
            bad.push_back(mask);
        }
        for(int i = 1; i < 1<<n; i++) {
            bool ok = true;
            for(int j = 0; j < n and ok; j++) {
                if(!bit(i,j)) continue;
                if(i & bad[j]) ok = false;
            }
            if(ok) res++;
        }
        return res;
    }
};