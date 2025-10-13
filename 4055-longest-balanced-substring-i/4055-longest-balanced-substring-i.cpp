class Solution {
public:
    int longestBalanced(string s) {
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            int ma = 0, cnt = 0, freq[26]{0,};
            for(int j = i; j < n; j++) {
                ma = max(ma, ++freq[s[j]-'a']);
                if(freq[s[j]-'a'] == 1) cnt++;
                if(j - i + 1 == cnt * ma) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};