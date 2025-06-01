class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        vector<bool> masks(1<<n);
        auto ok = [&](int mask) {
            long long mul = 1;
            for(int i = 0; i < n and mul <= target; i++) if((mask>>i)&1) mul *= nums[i];
            return mul == target;
        };
        for(int mask = 1; mask < 1<<n; mask++) {
            masks[mask] = ok(mask);
            if(masks[mask]) continue;
            for(int base = mask, sub = base; sub and !masks[mask]; sub = (sub - 1) & mask) {
                if(masks[sub] and masks[mask ^ sub]) masks[mask] = true;
            }
        }
        return masks.back();
    }
};
