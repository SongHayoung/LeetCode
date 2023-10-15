class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        map<int,int> mp;
        for(int i = indexDifference; i < nums.size(); i++) mp[nums[i]] = i;
        for(int i = 0; i < nums.size(); i++) {
            int lo = nums[i] - valueDifference, hi = nums[i] + valueDifference;
            auto ub = mp.upper_bound(lo), lb = mp.lower_bound(hi);
            if(lb != end(mp)) {
                return {i,lb->second};
            }
            if(ub != begin(mp)) {
                --ub;
                return {i,ub->second};
            }
            
            if(i + indexDifference >= nums.size()) break;
            int x = nums[i+indexDifference];
            if(mp[x] == i+indexDifference) mp.erase(x);
        }
        return {-1,-1};
    }
};
