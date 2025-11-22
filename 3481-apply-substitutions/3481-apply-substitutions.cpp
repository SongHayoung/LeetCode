class Solution {
    string getKey(string& k, unordered_map<string,string>& mp, unordered_map<string,string>& dp) {
        if(dp.count(k)) return dp[k];
        if(!mp.count(k)) return k;
        return dp[k] = process(mp[k], mp, dp);
        
    }
    string process(string& s, unordered_map<string,string>& mp, unordered_map<string,string>& dp) {
        string res = "", chk = "";
        for(auto& ch : s) {
            if(ch == '%' or chk != "") {
                chk.push_back(ch);
                if(chk.size() > 1 and chk.back() == '%') {
                    res += getKey(chk,mp,dp);
                    chk = "";
                }
            } else res.push_back(ch);
        }
        return res; 
    }
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string,string> mp, dp;
        for(auto& r : replacements) mp["%" + r[0] + "%"] = r[1];
        return process(text, mp, dp);
    }
};