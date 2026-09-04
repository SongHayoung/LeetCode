class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, pair<int,int>> freq;
        unordered_set<char> v{'a','e','i','o','u'};
        for(int i = s.length() - 1; i >= 0; i--) {
            if(!v.count(s[i])) continue;
            freq[s[i]] = {freq[s[i]].first + 1, i};
        }
        vector<char> S(begin(v), end(v));
        sort(begin(S), end(S), [&](auto& a, auto& b) {
           if(freq[a].first != freq[b].first) return freq[a].first < freq[b].first;
           return freq[a].second > freq[b].second;
        });
        for(auto& ch : s) {
            if(!v.count(ch)) continue;
            ch = S.back();
            if(--freq[S.back()].first == 0) S.pop_back();
        }
        return s;
    }
};