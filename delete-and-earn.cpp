class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sum(10001, 0);
        for(auto& n : nums) sum[n] += n;
        int get = 0, skip = 0;
        for(int i = 1; i <= 10000; i++) {
            int s = skip + sum[i];
            skip = max(get, skip);
            get = s;
        }
        return max(skip, get);
    }
};
