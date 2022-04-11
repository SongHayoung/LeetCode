class Solution {
    unordered_map<string, int> mp;
    int len, totlen;
    bool verify(string& s, int i) {
        unordered_map<string,int> tmp;
        for(int st = i; st < i + totlen; st+=len) {
            string w = s.substr(st,len);
            if(!mp.count(w) or mp[w] < ++tmp[w]) return false;
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        len = words[0].length(), totlen = words.size() * len;
        
        
        for(auto w : words) mp[w]++;
        for(int i = 0; i <= (int)s.length() - totlen; i++) {
            if(verify(s,i))
                res.push_back(i);
        }
        
        return res;
    }
};