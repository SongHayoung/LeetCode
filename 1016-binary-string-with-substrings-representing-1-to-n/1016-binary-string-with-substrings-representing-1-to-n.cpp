class Solution {
public:
    bool queryString(string s, int n) {
        vector<bool> seen(n+1);
        int cnt = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') continue;
            long long num = 0;
            for(int j = i; j < min(i + 31, (int)s.length()); j++) {
                num = num * 2 + (s[j] == '1');
                if(num <= n and !seen[num]) {
                    cnt += seen[num] = true;
                }
            }
        }
        return cnt == n;
    }
};