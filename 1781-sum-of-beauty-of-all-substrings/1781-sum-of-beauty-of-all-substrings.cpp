class Solution {
public:
    int beautySum(string s) {
        vector<int> freq(26);
        int n = s.length(), res = 0;
        vector<vector<int>> freqs;
        freqs.push_back(freq);
        for(auto& ch : s) {
            freq[ch-'a']++;
            freqs.push_back(freq);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int mi = INT_MAX, ma = INT_MIN;
                for(int k = 0; k < 26; k++) {
                    int diff = freqs[j][k] - freqs[i][k];
                    if(diff == 0) continue;
                    mi = min(mi, diff);
                    ma = max(ma, diff);
                }
                if(mi == INT_MAX or ma == mi) continue;
                res += ma - mi;
            }
        }
        return res;
    }
};