class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        vector<int> freq(26,0);
        for(auto& ch : s) freq[ch-'a']++;
        int odd = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] & 1) odd++;
        }
        return odd <= k;
    }
};