class Solution {
public:
    string customSortString(string order, string s) {
        int o = 1;
        unordered_map<char, int> mp;
        for(auto& ch : order)
            mp[ch] = o++;
        sort(begin(s), end(s), [&](char a, char b) {
            return mp[a] < mp[b];
        });
        return s;
    }
};