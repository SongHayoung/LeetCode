class Solution {
    bool helper(vector<int>& A, int k, int m) {
        int cnt = 0;
        for(auto& a : A) {
            cnt += a / m;
            if(cnt >= k) return true;
        }
        return false;
    }
public:
    int maxLength(vector<int>& ribbons, int k) {
        int l = 1, r = 1e5, res = 0;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(ribbons, k, m);
            if(ok){
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
};