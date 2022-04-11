class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() <= 10) return {};
        
        int hash = 0;
        int mod = (1<<20) - 1;
        unordered_map<char, int> lookup {{'A',0},{'C',1},{'G',2},{'T',3}};
        unordered_map<int, int> counter;
        vector<string> res;
        for(int i = 0; i < 10; i++) hash = (hash * 4 + lookup[s[i]]) % mod;
        counter[hash]++;
        for(int i = 10; i < s.length(); i++) {
            hash = (hash * 4 + lookup[s[i]]) & mod;
            if(counter[hash]++ == 1) {
                res.push_back(s.substr(i-9, 10));
            }
        }
        return res;
    }
};