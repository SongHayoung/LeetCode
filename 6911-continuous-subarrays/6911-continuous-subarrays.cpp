class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<long long, long long> freq;
        auto ok = [&]() {
            if(freq.size() > 3) return false;
            if(freq.size() == 0) return true;
            long long mi = begin(freq)->first, ma = prev(end(freq))->first;
            return ma - mi <= 2;
        };
        auto incr = [&](int x) {
            freq[x] += 1;
        };
        auto decr = [&](int x) {
            if(--freq[x] == 0) freq.erase(x);
        };
        long long res = 0, l = 0, r = 0, n = nums.size();
        while(r < n) {
            while(r < n and ok()) {
                incr(nums[r++]);
                if(ok()) res += (r - l);
                else {
                    break;
                }
            }
            bool flag = false;
            while(l < n and !ok()) {
                flag = true;
                decr(nums[l++]);
            }
            if(flag) res += (r - l);
        }
        return res;
    }
};