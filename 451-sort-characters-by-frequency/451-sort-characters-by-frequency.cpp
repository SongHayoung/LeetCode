class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto& ch : s) mp[ch]++;
        for(auto& [k, v] : mp) pq.push({v, k});
        while(!pq.empty()) {
            auto [c, ch] = pq.top(); pq.pop();
            res += string(c, ch);
        }
        return res;
    }
};