class Solution {
    vector<string> parse(string& p) {
        vector<string> res;
        string now = "";
        for(auto& ch : p) {
            if(ch == '*') {
                if(now != "") res.push_back(now);
                now = "";
            } else now.push_back(ch);
        }
        if(now != "") res.push_back(now);
        return res;
    }
    vector<int> pi(string& p) {
        vector<int> PI(p.length());
        for(int i = 1, j = 0; i < p.length(); i++) {
            while(j and p[i] != p[j]) j = PI[j-1];
            if(p[i] == p[j]) PI[i] = ++j;
        }
        return PI;
    }
    vector<int> kmp(string& s, string& p) {
        vector<int> PI = pi(p);
        vector<int> res;
        for(int i = 0, j = 0; i < s.length(); i++) {
            while(j and s[i] != p[j]) j = PI[j-1];
            if(s[i] == p[j]) {
                if(++j == p.length()) {
                    res.push_back(i - j + 1);
                    j = PI[j-1];
                }
            }
        }
        return res;
    }
public:
    int shortestMatchingSubstring(string s, string p) {
        if(p == "**") return 0;
        vector<string> token = parse(p);
        vector<long long> dp(s.length());
        for(int i = 0; i < s.length(); i++) dp[i] = i;
        bool fl = true;
        while(token.size()) {
            vector<int> now = kmp(s,token.back());
            vector<long long> dpp(s.length(), INT_MAX);
            long long best = INT_MAX;
            while(now.size()) {
                long long pos = now.back(), until = pos + token.back().length() - fl;
                while(dp.size() > until) best = min(best, dp.back()), dp.pop_back();
                dpp[pos] = best;
                now.pop_back();
            }
            token.pop_back();
            swap(dp,dpp);
            fl = false;
        }
        long long res = INT_MAX;
        for(int i = 0; i < dp.size(); i++) {
            res = min(res, dp[i] - i + 1);
        }
        return res > s.length() ? -1 : res;
    }
};