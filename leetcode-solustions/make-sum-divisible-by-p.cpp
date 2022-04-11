class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<long> sums(nums.size() + 1, 0);
        unordered_map<int, int> index;
        
        for(int i = 1; i < sums.size(); i++) {
            sums[i] = sums[i - 1] + (nums[i - 1] % p);
        }
        
        int res = INT_MAX, back = sums.back() % p;

        if(back == 0)
            return 0;
        
        for(int i = 0; i < sums.size(); i++) {
            index[sums[i] % p] = i;
            long remainder = (p + sums[i] - back) % p;
            if(index.find(remainder) != index.end())
                res = min(res, i - index[remainder]);
        }

        return res >= nums.size() ? -1 : res;
    }
};
