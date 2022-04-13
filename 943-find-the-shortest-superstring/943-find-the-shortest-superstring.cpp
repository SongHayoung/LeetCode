class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dist(n, vector<int>(n));
        vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));
        vector<vector<int>> path(1<<n, vector<int>(n));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = getDist(words[i], words[j]);
        
        for(int mask = 1; mask < 1<<n; mask++) {
            for(int inc = 0; inc < n; inc++) {
                if(mask & (1<<inc)) {
                    int rmMask = mask ^ (1<<inc);
                    if(rmMask == 0) {
                        dp[mask][inc] = words[inc].length();
                    } else {
                        for(int i = 0; i < n; i++) {
                            if(dp[rmMask][i] != INT_MAX and dp[rmMask][i] + dist[i][inc] < dp[mask][inc]) {
                                dp[mask][inc] = dp[rmMask][i] + dist[i][inc];
                                path[mask][inc] = i;
                            }
                        }
                    }                  
                }
            }
        }
        
        int mi = INT_MAX, last = -1, mask = (1<<n) - 1;
        for(int i = 0; i < n; i++) {
            if(dp[mask][i] < mi) {
                mi = dp[mask][i];
                last = i;
            }
        }
        
        vector<int> seq;
        while(mask) {
            seq.push_back(last);
            int nMask = mask ^ (1<<last);
            last = path[mask][last];
            mask = nMask;
        }
        int from = seq.back();
        string res = words[from];
        seq.pop_back();
        while(!seq.empty()) {
            int to = seq.back();
            seq.pop_back();

            res += words[to].substr(words[to].length()-dist[from][to]);
            
            from = to;
        }
        return res;
    }
    
    int getDist(string& from, string& to) {
        for(int i = 1; i < from.length(); i++) {
            bool included = true;
            for(int stFrom = i, stTo = 0; stTo < to.length() and stFrom < from.length() and included; stFrom++, stTo++) {
                if(from[stFrom] != to[stTo])
                    included = false;
            }
            if(included) {
                return to.length() - (from.length() - i);
            }
        }
        return to.length();
        
    }
};