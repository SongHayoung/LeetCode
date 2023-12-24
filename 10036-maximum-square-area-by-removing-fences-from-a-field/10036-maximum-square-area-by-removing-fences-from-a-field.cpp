class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& A, vector<int>& B) {
        A.push_back(1);
        A.push_back(m);
        B.push_back(1);
        B.push_back(n);
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        unordered_set<int> da;
        for(int i = 0; i < A.size(); i++) {
            for(int j = i + 1; j < A.size(); j++) {
                da.insert(A[j] - A[i]);
            }
        }
        long long res = -1, mod = 1e9 + 7;
        for(int i = 0; i < B.size(); i++) {
            for(int j = i + 1; j < B.size(); j++) {
                long long d = B[j] - B[i];
                if(da.count(d)) res = max(res, d);
            }
        }
        if(res == -1) return -1;
        return res * res % mod;
    }
};