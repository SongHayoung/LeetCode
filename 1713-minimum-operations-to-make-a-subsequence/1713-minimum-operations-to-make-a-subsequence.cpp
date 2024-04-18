class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0; i < target.size(); i++) mp[target[i]] = i;
        vector<int> dp;
        for(auto& x : arr) {
            if(!mp.count(x)) continue;
            if(dp.size() == 0 or dp.back() < mp[x]) dp.push_back(mp[x]);
            else *lower_bound(begin(dp), end(dp), mp[x]) = mp[x];
        }
        
        return target.size() - dp.size();
    }
};