class Solution {
    bool compare(unordered_map<char, int>& origin, int target[128]) {
        for(auto [k, v] : origin) {
            if(v > target[k]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        int counter[128]{0,}, req = 0;
        for(auto ch : t)
            if(counter[ch]++ == 0)
                req++;
        
        int sCounter[128]{0,};
        int l = 0, r = 0, len = INT_MAX;
        string res = "";
        while(r < s.length()) {
            if(++sCounter[s[r]] == counter[s[r]] and counter[s[r]] > 0) {
                req--;
            }
            r++;
            
            while(!req) {
                if(r - l < len and !req) {
                    res = s.substr(l, r - l);
                    len = res.length();
                }
                
                if(sCounter[s[l]]-- == counter[s[l]] and counter[s[l]] > 0) {
                    req++;
                }
                l++;
            }          
        }
        return res;
    }
};