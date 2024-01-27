class Solution {
    int singleSum(unordered_map<int, int>& mp, vector<int>& s, int d) {
        int res = 0;
        for(auto x : s) {
            if(3 * x % d == 0 and mp[x] >= 3) {
                res += mp[x] * (mp[x]-1) * (mp[x]-2) / 6;
            }
        }
        return res;
    }
    int twoSum(unordered_map<int, int>& mp, vector<int>& s, int d) {
        int res = 0;
        for(auto x : s) {
            if(mp[x] < 2) continue;
            int target = (2 * d - 2 * x) % d;
            if(target == x) continue;
            if(!mp.count(target)) continue;
            res += mp[x] * (mp[x]-1) / 2 * mp[target];
        }
        return res;
    }
    int threeSum(unordered_map<int, int>& mp, vector<int>& s, int d) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i + 1; j < s.size(); j++) {
                int k = (d - (s[i] + s[j]) % d) % d;
                if(k > s[j] and mp.count(k)) {
                    res += mp[s[i]] * mp[s[j]] * mp[k];
                }
            }
        }
        return res;
    }
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        unordered_map<int, int> mp;
        for(auto x : nums) {
            mp[x%d] += 1;
        }
        vector<int> s;
        int res = 0;
        for(auto& [k,_] : mp) s.push_back(k);
        sort(begin(s), end(s));
        res += singleSum(mp,s,d);
        res += twoSum(mp,s,d);
        res += threeSum(mp,s,d);
        return res;
    }
};