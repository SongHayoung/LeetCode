class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> at;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') at.push_back(i);
        }
        if(at.size() < k) return "";
        int len = 1e9;
        for(int i = k - 1; i < at.size(); i++) {
            len = min(len, at[i] - at[i-k+1] + 1);
        }
        vector<string> cand;
        for(int i = k - 1; i < at.size(); i++) {
            if(len !=  (at[i] - at[i-k+1] + 1)) continue;
            cand.push_back(s.substr(at[i-k+1],len));
        }
        sort(begin(cand), end(cand));
        return cand[0];
    }
};