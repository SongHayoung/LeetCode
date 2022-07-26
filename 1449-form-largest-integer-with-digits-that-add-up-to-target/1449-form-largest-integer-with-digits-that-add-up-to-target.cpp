class Solution {
    string large(string a, string b) {
        if(a.length() != b.length()) return a.length() > b.length() ? a : b;
        vector<int> freq(10);
        for(int i = 0; i < a.length(); i++) freq[a[i]-'0']++;
        for(int i = 0; i < b.length(); i++) freq[b[i]-'0']--;
        for(int i = 9; i > 0; i--) {
            if(freq[i] == 0) continue;
            return freq[i] > 0 ? a : b;
        }
        return a;
    }
public:
    string largestNumber(vector<int>& cost, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < cost.size(); i++) {
            mp[cost[i]] = i + 1;
        }
        vector<string> dp(target + 1, "");
        for(int i = 1; i <= target; i++) {
            for(auto& [cost, num] : mp) {
                if(cost == i) {
                    dp[i] = large(dp[i], string(1, num + '0'));
                } else if(i > cost and dp[i-cost] != "") {
                    string now = dp[i-cost];
                    now.push_back(num + '0');
                    dp[i] = large(dp[i], now);
                }
            }
        }
        sort(rbegin(dp[target]), rend(dp[target]));
        return dp[target] == "" ? "0" : dp[target];
    }
};