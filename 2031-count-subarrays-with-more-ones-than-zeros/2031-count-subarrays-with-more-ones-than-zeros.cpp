class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        unordered_map<int, int> mp {{0,1}};
        int sum = 0, eq = 0, over = 0, mod = 1e9 + 7, res = 0;
        for(auto& n : nums) {
            sum += (n ? 1 : -1);
            
            auto peq = eq, pov = over;
            
            eq = mp[sum];
            
            if(n) over = (peq + pov + 1) % mod;
            else over = (pov - eq + mod) % mod;
            
            mp[sum]++;
            res = (res + over) % mod;
        }
        
        return res;
    }
};