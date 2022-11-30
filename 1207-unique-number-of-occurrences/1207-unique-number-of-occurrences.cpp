class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> us;
        for(auto a : arr) mp[a]++;
        for(auto [_, c] : mp) us.insert(c);
        return us.size() == mp.size();
    }
};