class Solution {
    long long mod = 1e9 + 7;
    long long h = 31;
public:
    int equalDigitFrequency(string s) {
        unordered_set<long long> us;
        for(int i = 0; i < s.length(); i++) {
            long long hash = 0, ma = 0, uniq = 0;
            vector<long long> freq(10);
            for(int j = i; j < s.length(); j++) {
                int d = s[j] - '0';
                if(++freq[d] == 1) uniq++;
                ma = max(ma, freq[d]);
                hash = (hash * h + d + 1) % mod;
                if(ma * uniq == j - i + 1)
                    us.insert(hash);
            }
        }
        
        return us.size();
    }
};