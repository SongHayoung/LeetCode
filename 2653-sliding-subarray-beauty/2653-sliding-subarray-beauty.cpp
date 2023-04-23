
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int,int> freq;
        int neg = 0;
        auto insert = [&](int x) {
            if(x < 0) neg += 1;
            freq[x] += 1;
        };
        auto erase = [&](int x) {
            if(x < 0) neg -= 1;
            freq[x] -= 1;
            if(freq[x] == 0) freq.erase(x);
        };
        for(int i = 0; i < k; i++) insert(nums[i]);
        auto work = [&]() {
            if(neg < x) return 0;
            int now = x;
            for(auto [k,v] : freq) {
                now -= v;
                if(now <= 0) return k;
            }
            return 0;
        };
        vector<int> res;
        res.push_back(work());
        for(int i = k; i < nums.size(); i++) {
            insert(nums[i]);
            erase(nums[i-k]);
            res.push_back(work());
        }
        return res;
    }
};
