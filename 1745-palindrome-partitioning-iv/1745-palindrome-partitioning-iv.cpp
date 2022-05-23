class Solution {
public:
    bool checkPartitioning(string s) {
        string extend = "#";
        for(auto& ch : s) {
            extend.push_back(ch);
            extend.push_back('#');
        }
        
        int l = 0, r = -1, n = extend.length();
        vector<int> dp(n);
        vector<int> bound;
        for(int i = 0; i < n; i++) {
            dp[i] = max(0, min(r - i, (r + l - i >= 0? dp[r + l - i] : -1)));
            while(i + dp[i] < n and i - dp[i] >= 0 and extend[i + dp[i]] == extend[i - dp[i]])
                dp[i]++;
            if(i > 0 and i - dp[i] < 0)
                bound.push_back(i + dp[i]);
            if(i + dp[i] > r) {
                r = i + dp[i];
                l = i - dp[i];
            }
        }
        sort(begin(bound), end(bound));
        for(int i = n - 2; i >= 0; i--) {
            if(i + dp[i] < n) continue;
            int left = i - dp[i];
            for(int i = 0; i < bound.size() and bound[i] <= left; i++) {
                int mid = (bound[i] + left) / 2;
                int dis = left - mid;
                if(bound[i] == left and extend[mid] == '#') continue;
                if(dp[mid] > left - mid) return true;
            }
        }
        return false;
    }
};