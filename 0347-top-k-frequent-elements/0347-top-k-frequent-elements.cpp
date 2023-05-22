class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> res(k);
        for(auto& num : nums) {
            m[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto& elem : m) {
            pq.push({elem.second, elem.first});
        }
        while(k--) {
            res[k] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};