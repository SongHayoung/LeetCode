class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long res = 0, l = 0, r = 0, n = nums.size(), pop = -1, over = 0;
        unordered_map<int,int> freq;
        auto add = [&](int idx) {
            int x = nums[idx];
            if(++freq[x] == m) over++;
        };
        auto del = [&](int idx) {
            int x = nums[idx];
            if(freq[x] == m) over--;
            if(--freq[x] == 0) {
                pop = idx;
                freq.erase(x);
            }
        };
        while(r < n) {
            add(r++);
            while(freq.size() > k) del(l++);
            while(over == k and freq[nums[l]] > m) del(l++);
            if(over == k) res += (l - pop);
        }
        return res;
    }
};