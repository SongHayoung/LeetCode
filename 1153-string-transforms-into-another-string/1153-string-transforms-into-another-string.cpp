class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        unordered_map<char, char> mp;
        int n = str1.length();
        for(int i = 0; i < n; i++) {
            char u = str1[i], v = str2[i];
            if(!mp.count(u)) mp[u] = v;
            else {
                if(mp[u] != v) return false;
            }
        }
        
        if(mp.size() != 26)
            return true;
        
        unordered_map<char, vector<char>> rmp;        
        for(auto [k, v] : mp) {
            rmp[v].push_back(k);
        }
        for(auto& [k, v] : rmp) {
            if(v.size() >= 2) {
                for(int i = 1; i < v.size(); i++)
                    mp.erase(v[i]);
            }
        }
        return mp.size() != 26;
    }
};