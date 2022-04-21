class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int> mp;
        vector<string> bucket(s.length() + 1, "");
        for(auto& ch : s) mp[ch]++;
        for(auto& [k, v] : mp) bucket[v].append(string(v,k));
        for(int i = s.length(); i >= 0; i--) res.append(bucket[i]);
        return res;
    }
};