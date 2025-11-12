
class Solution {
    bool check(vector<int>& A) {
        int now = A[0];
        for(int i = 1; i < A.size(); i++) now = __gcd(now,A[i]);
        return now == 1;
    }
    int work(vector<int> A, int st) {
        int res = 0;
        for(int i = st; i < A.size() - 1; i++) {
            if(A[i+1] == 1) continue;
            A[i+1] = __gcd(A[i], A[i+1]);
            res += 1;
        }
        if(A.back() != 1) return INT_MAX;
        for(int i = A.size() - 1; i; i--) {
            if(A[i-1] == 1) continue;
            A[i-1] = __gcd(A[i-1], A[i]);
            res += 1;
        }
        return res;
    }
public:
    int minOperations(vector<int>& A) {
        if(!check(A)) return -1;
        int res = INT_MAX;
        for(int i = 0; i < A.size(); i++) {
            res = min(res, work(A,i));
        }
        return res;
    }
};
