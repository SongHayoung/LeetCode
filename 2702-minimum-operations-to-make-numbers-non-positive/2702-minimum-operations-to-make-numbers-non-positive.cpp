class Solution {
    long long helper(long long a, long long x, long long y, long long m) {
        long long diff = a - y * m;
        return (diff + x - y - 1) / (x - y);
    }
    bool helper(vector<int>& A, int x, int y, long long m) {
        long long cnt = 0;
        for(auto a : A) {
            if(a <= y * m) continue;
            cnt += helper(a,x,y,m);
            if(m < cnt) return false;
        }
        return true;
    }
public:
    int minOperations(vector<int>& A, int x, int y) {
        sort(begin(A), end(A));
        long long l = 0, r = INT_MAX, res = r;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(A,x,y,m);
            if(ok) {
                res = min(res,m);
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};