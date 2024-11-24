class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int x = s.length() / k;
        string ss = "", tt = "";
        unordered_map<string,int> f;
        for(int i = 0; i <= s.length(); i++) {
            if(i and i % x == 0) {
                f[ss]++, f[tt]--;
                ss = tt = "";
            }
            if(i < s.length()) {
                ss.push_back(s[i]);
                tt.push_back(t[i]);
            }
        }
        for(auto& [_,c] : f) if(c) return false;
        return true;
    }
};