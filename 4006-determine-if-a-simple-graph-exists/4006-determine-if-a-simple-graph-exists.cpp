class Solution {
public:
    bool simpleGraphExists(vector<int>& A) {
        if(A.size() == 0) return true;
        sort(rbegin(A), rend(A));
        vector<long long> pre{0};
        for(auto& n : A) pre.push_back(pre.back() + n);
        if(pre.back() & 1) return false;
        for(long long i = 1; i < pre.size(); i++) {
            long long le = pre[i], ri = i * (i - 1);
            long long l = i, r = pre.size() - 2, best = -1;
            while(l <= r) {
                long long m = l + (r - l) / 2;
                if(A[m] <= i) {
                    best = m;
                    r = m - 1;
                } else l = m + 1;
            }
            if(best == -1) ri += (A.size() - i) * i;
            else ri += (best - i) * i + pre.back() - pre[best];
            if(le > ri) return false;
        }
        return true;
    }
};