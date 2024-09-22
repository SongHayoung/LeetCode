class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> freq1(26), freq2(26);
        for(auto& ch : word2) freq2[ch-'a']++;
        int ok = count(begin(freq2), end(freq2), 0);
        long long res = 0;
        for(int i = 0, j = 0; i < word1.size(); i++) {
            while(j < word1.size() and ok < 26) {
                int x = word1[j++] - 'a';
                if(++freq1[x] == freq2[x]) ok++;
            }
            if(ok == 26) res += word1.size() - j + 1;
            int x = word1[i] - 'a';
            if(--freq1[x] == freq2[x] - 1) ok--;
        }
        return res;
    }
};