class Solution {
    unordered_map<string,int> helper(string& s) {
        s.push_back(' ');
        string now = "";
        unordered_map<string,int> res;
        for(auto& ch : s) {
            if(ch == ' ') {
                res[now]++;
                now = "";
            } else now.push_back(ch);
        }
        return res;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> f1 = helper(s1), f2 = helper(s2);
        vector<string> res;
        for(auto& [k,v] : f1) if(v == 1 and f2.count(k) == 0) res.push_back(k);
        for(auto& [k,v] : f2) if(v == 1 and f1.count(k) == 0) res.push_back(k);
        return res;
    }
};