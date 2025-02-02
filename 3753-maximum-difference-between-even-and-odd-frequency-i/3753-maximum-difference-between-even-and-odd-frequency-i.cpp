class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        for(auto& ch : s) freq[ch-'a']++;
        int res = INT_MIN;
        for(int i = 0; i < 26; i++) {
            if(!freq[i]) continue;
            if(freq[i] & 1) continue;
            for(int j = 0; j < 26; j++) {
                if(!freq[j]) continue;
                if(freq[j] % 2 == 0) continue;
                int now = freq[i] - freq[j];
                res = max(res, -now);
            }
        }
        return res;
    }
};