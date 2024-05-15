class Solution {
    long long fenwick[4040];
    void update(int n, int k) {
        while(n < 4040) {
            fenwick[n] += k;
            n += n & -n;
        }
    }
    long long query(int n) {
        long long res = 0;
        while(n) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
public:
    long long countQuadruplets(vector<int>& A) {
        long long res = 0;
        memset(fenwick,0,sizeof fenwick);
        update(A[0],1);
        int n = A.size();
        for(int j = 1; j < A.size(); j++) {
            int hi = (n - A[j] - (query(n) - query(A[j])));
            for(int k = j + 1; k + 1 < A.size() and hi; k++) {
                if(A[k] < A[j]) {
                    res += hi * query(A[k]);
                } else hi--;
            }
            update(A[j],1);
        }
        return res;
    }
};