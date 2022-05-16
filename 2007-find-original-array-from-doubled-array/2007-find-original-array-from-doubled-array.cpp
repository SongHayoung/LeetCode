class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> mp;
        set<int> s;
        for(auto& n : changed) {
            mp[n]++;
            s.insert(n);
        }
        vector<int> res;
        if(mp.count(0) and mp[0] & 1) return {};
        for(int i = 0; i < mp[0] / 2; i++) {
            res.push_back(0);
        }
        
        s.erase(0);
        for(auto& num : s) {
            int count = mp[num];
            if(count == 0) continue;
            if(mp[num * 2] < count) return {};
            mp[num * 2] -= count;
            for(int i = 0; i < count; i++)
                res.push_back(num);
        }
        return res;
    }
};