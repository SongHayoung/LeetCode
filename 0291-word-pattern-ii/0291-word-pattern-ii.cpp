class Solution {
    string p;
    bool check(string& s, unordered_map<char,int>& len) {
        unordered_map<char,string> mp;
        unordered_map<string,char> rmp;
        int j = 0;
        for(int i = 0; i < s.length();) {
            char ch = p[j++];
            string now = "";
            for(int x = 0; x < len[ch]; x++) now.push_back(s[i+x]);
            if(mp.count(ch)) {
                if(mp[ch] != now) return false;
            } else {
                mp[ch] = now;
                if(rmp.count(now)) return false;
                rmp[now] = ch;
            }
            i += now.length();
        }
        return true;
    }
    bool helper(vector<pair<char,int>>& A, int sum, int p, unordered_map<char,int>& len, string& s) {
        if(p == A.size() and sum == s.length()) {
            return check(s,len);
        }
        if(sum >= s.length() or p == A.size()) return false;
        for(int l = 1; l <= s.length(); l++) {
            len[A[p].first] = l;
            if(helper(A,sum + l * A[p].second, p + 1, len, s)) return true;
        }
        return false;
    }
public:
    bool wordPatternMatch(string pattern, string s) {
        p = pattern;
        unordered_map<char,int> freq;
        for(auto& p : pattern) freq[p]++;
        vector<pair<char,int>> A;
        for(auto& [k,v] : freq) A.push_back({k,v});
        unordered_map<char,int> len;
        return helper(A,0,0,len,s);
    }
};