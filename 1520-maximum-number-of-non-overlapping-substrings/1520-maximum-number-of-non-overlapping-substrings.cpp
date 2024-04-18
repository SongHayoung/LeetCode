
class Solution {
    pair<bool,int> helper(string& s, int p, vector<pair<int,int>>& at) {
        int r = at[s[p]-'a'].second, l = p;
        while(p < r) {
            if(at[s[p]-'a'].first < l) return {false,0};
            r = max(r, at[s[p++]-'a'].second);
        }
        return {true, r - l + 1};
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> freq(26);
        vector<pair<int, int>> at(26, {INT_MAX,INT_MIN});
        for(int i = 0; i < s.length(); i++) {
            freq[s[i]-'a']++;
            at[s[i]-'a'].first = min(at[s[i]-'a'].first, i);
            at[s[i]-'a'].second = max(at[s[i]-'a'].second, i);
        }
        vector<string> res;
        int until = -1;
        for(int i = 0; i < s.length(); i++) {
            if(at[s[i]-'a'].first != i) continue;
            auto [ok, len] = helper(s,i,at);
            if(!ok) continue;
            if(until < i) res.push_back("");
            until = i + len - 1;
            res.back() = s.substr(i,len);
        }
        return res;
    }
};