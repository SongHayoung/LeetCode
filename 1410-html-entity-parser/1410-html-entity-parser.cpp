class Solution {
    bool helper(string k, string& s, int p) {
        for(int i = 0; i < k.length(); i++) {
            if(p + i == s.length()) return false;
            if(s[i + p] != k[i]) return false;
        }
        return true;
    }
public:
    string entityParser(string text) {
        string res = "";
        text.push_back('#');
        int i = 0, n = text.length();
        unordered_map<string, string> mp;
        mp["&quot;"] = "\"";
        mp["&apos;"] = "'";
        mp["&amp;"] = "&";
        mp["&gt;"] = ">";
        mp["&lt;"] = "<";
        mp["&frasl;"] = "/";
        while(i < n) {
            bool eq = false;
            for(auto& [k, v] : mp) {
                if(helper(k,text,i)) {
                    res += v;
                    i += k.length();
                    eq = true;
                }
            }
            if(!eq) {
                res.push_back(text[i++]);
            }
        }
        res.pop_back();
        return res;
    }
};