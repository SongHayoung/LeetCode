class Solution {
    int helper(string& s, int k) {
        int n = s.length();
        vector<vector<int>> pre(n+1);
        {
            vector<int> freq(26);
            pre[0] = freq;
            for(int i = 0; i < s.length(); i++) {
                freq[s[i]-'a'] += 1;
                pre[i+1] = freq;
            }
        }
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            for(int j = i + k; j <= s.length() and (j - i) / k <= 26; j += k) {
                int t = (j - i) / k;
                bool ok = true;
                bool over = false;
                for(int x = 0; x < 26; x++) {
                    int d = pre[j][x] - pre[i][x];
                    if(d == 0) continue;
                    if(d != k) ok = false;
                    if(d > k) over = true;
                    if(!ok) break;
                    if(d == k) t -= 1;
                }
                if(ok and t == 0) res += 1;
                if(over) break;
            }
        }
        return res;
    }
public:
    int countCompleteSubstrings(string word, int k) {
        string now = "";
        int res = 0;
        for(auto& ch : word) {
            if(now.size() == 0 or abs(now.back() - ch) <= 2) now.push_back(ch);
            else {
                res += helper(now,k);
                now = "";
                now.push_back(ch);
            }
        }
        res += helper(now,k);
        return res;
    }
};
