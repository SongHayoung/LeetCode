class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        vector<int> sArr(26), pArr(26);
        vector<int> res;
        for(int i = 0; i < p.size(); i++) {
            sArr[s[i] - 'a']++;
            pArr[p[i] - 'a']++;
        }
        for(int i = 0; i < s.size()-p.size(); i++) {
            if(sArr == pArr) res.push_back(i);
            sArr[s[i + p.size()] - 'a']++;
            sArr[s[i] - 'a']--;
        }
        if(sArr == pArr) res.push_back(s.size() - p.size());

        return res;
    }
};
