class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        vector<long long> res(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        for(auto [k,v] : mp) {
            long long le = 0, ri = accumulate(begin(v), end(v), 0ll);
            long long lec = 0, ric = v.size();
            for(int i = 0; i < v.size(); i++) {
                ri -= v[i];
                ric -= 1;
                res[v[i]] = abs(le - lec * v[i]) + abs(ri - ric * v[i]);
                le += v[i];
                lec += 1;
            }
        }
        return res;
    }
};