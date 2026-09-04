class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int sum = 0, res = INT_MAX;
        auto append = [&](int x) {
            if(freq[x] == 0) sum += x;
            ++freq[x];
        };
        auto pop = [&](int x) {
            if(freq[x] == 1) sum -= x;
            --freq[x];
        };
        for(int i = 0, j = 0; i < nums.size(); i++) {
            while(j < nums.size() and sum < k) append(nums[j++]);
            if(sum >= k) {
                res = min(res, j - i);
            }
            pop(nums[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};