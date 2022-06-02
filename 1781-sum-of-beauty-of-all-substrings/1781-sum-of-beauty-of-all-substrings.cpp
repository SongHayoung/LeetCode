class Solution {
public:
    int beautySum(string s) {
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            int freq[26] = {0,}, ma = 0, mi = 0;
            for(int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                freq[idx]++;
                ma = max(ma, freq[idx]);
                if(freq[idx] - 1 == mi) {
                    mi = INT_MAX;
                    for(int k = 0; k < 26; k++) {
                        if(freq[k] == 0) continue;
                        mi = min(mi, freq[k]);
                    }
                } else if(freq[idx] < mi) mi = freq[idx];
                res += ma - mi;
            }
        }
        return res;
    }
};