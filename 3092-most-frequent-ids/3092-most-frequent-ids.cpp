class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> mp;
        map<long long, int> cnt{{0,nums.size() + 1}};
        vector<long long> res;
        for(int i = 0; i < nums.size(); i++) {
            int id = nums[i], f = freq[i];
            if(--cnt[mp[id]] == 0) cnt.erase(mp[id]);
            mp[id] += f;
            cnt[mp[id]] += 1;
            res.push_back(prev(end(cnt))->first);
        }
        return res;
    }
};