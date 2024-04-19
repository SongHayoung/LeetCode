class Solution {
    int add(map<int,int>& mp, int x) {
        auto it = mp.upper_bound(x);
        if(it == begin(mp)) {
            mp[x] = x;
            if(it->first == x + 1) {
                mp[x] = it->second;
                mp.erase(it);
            }
            return 0;
        }
        --it;
        int res = 0;
        if(it->second + 1 == x) {
            it->second = x;
        } else if(it->second < x) {
            mp[x] = x;
            it++;
        } else {
            res = it->second - x + 1;
            it->second++;
        }
        auto nit = next(it);
        if(nit != end(mp) and it->second + 1 == nit->first) {
            it->second = nit->second;
            mp.erase(nit);
        }
        
        
        
        
        return res;
    }
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, int> mp;
        int res = 0;
        mp[nums[0]] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            res += add(mp,nums[i]);
        }
        return res;
    }
};