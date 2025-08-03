class Solution {
    bool helper(string& s, int m, vector<int>& ord, int k) {
        set<int> star;
        for(int i = 0; i <= m; i++) star.insert(ord[i]);
        long long cnt = 0, n = s.length();
        for(long long i = 0, alpha = 0; i < s.length() and cnt < k; i++) {
            alpha++;
            if(star.count(i)) {
                cnt += alpha * (n - i);
                alpha = 0;
            }
        }
        return cnt >= k;
    }
public:
    int minTime(string s, vector<int>& order, int k) {
        int l = 0, r = order.size() - 1, res = INT_MAX;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(s,m,order,k);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res == INT_MAX ? -1 : res;
    }
};


