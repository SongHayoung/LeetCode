class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,vector<int>> at;
        int n = nums.size(), res = 0;
        vector<int> le(n), ri(n);
        for(int i = 0; i < n; i++) {
            le[i] = ri[i] = i;
            if(nums[i]) at[-nums[i]].push_back(i);
        }
        auto merge = [&](int i, int j) {
            ri[i] = ri[j];
            le[j] = le[i];
        };
        for(auto& [_, vec] : at) {
            while(vec.size()) {
                auto p = vec.back(); vec.pop_back();
                if(ri[p] != p) continue;
                if(p + 1 < n and nums[p+1] >= nums[p]) merge(p,p+1);
                while(le[p] and nums[le[p]-1] >= nums[p]) merge(le[p]-1,p);
                res++;
            }
        }
        return res;
    }
};