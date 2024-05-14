class Solution {
    long long mod = 1e9 + 7;
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int> freq(26);
        for(int i = 0; i < s.length(); i++) freq[s[i]-'a']++;
        sort(rbegin(freq), rend(freq));
        while(freq.back() == 0) freq.pop_back();
        long long res = 0, best = -1;
        for(int i = 0; i < 1ll<<freq.size(); i++) {
            int cnt = __builtin_popcountll(i);
            if(cnt != k) continue;
            long long sum = 0, comb = 1;
            for(int j = 0; j < 26 and comb; j++) {
                if(!bit(i,j)) continue;
                comb = comb * freq[j] % mod;
                sum = sum + freq[j];
            }
            if(comb) {
                if(best < sum) res = comb, best = sum;
                else if(best == sum) res = (res + comb) % mod;
            }
        }
        
        return res;
    }
};