class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), res = 0, l = 0;
        deque<int> ma, mi;

        for (int r = 0; r < n; r++) {
            while (ma.size() and nums[ma.back()] <= nums[r]) ma.pop_back();
            ma.push_back(r);
            while (!mi.empty() and nums[mi.back()] >= nums[r]) mi.pop_back();
            mi.push_back(r);

            while (l <= r) {
                long long diff = nums[ma.front()] - nums[mi.front()];
                long long len = r - l + 1;
                if (diff * len <= k) break;

                if (ma.size() and ma.front() == l) ma.pop_front();
                if (mi.size() and mi.front() == l) mi.pop_front();
                l++;
            }

            res += (r - l + 1);
        }
        return res;
    }
};