class Solution {
public:
    string reverseByType(string s) {
        vector<int> at[2];
        for(int i = 0; i < s.length(); i++) {
            at[isalpha(s[i]) ? 1 : 0].push_back(i);
        }
        for(auto& pos : at) {
            for(int l = 0, r = pos.size() - 1; l < r; l++,r--) swap(s[pos[l]],s[pos[r]]);
        }
        return s;
    }
};