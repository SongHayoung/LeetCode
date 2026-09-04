class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        unordered_map<int,int> seen;
        vector<pair<int,int>> now;
        for (int r = 0; r < n; r++) {
            vector<pair<int,int>> nxt{{nums[r],r}};
            for (auto &p : now) {
                int v = p.first | nums[r];
                int b = p.second;
                if (nxt.back().first == v) nxt.back().second = min(nxt.back().second, b);
                else nxt.push_back({v, b});
            }

            swap(now,nxt);
            seen[nums[r]] = r;

            long long prevB = r + 1;
            for (auto &p : now) {
                int v = p.first;
                long long L = p.second;
                long long R = prevB - 1;

                long long lp = -1;
                if(seen.count(v)) lp = seen[v];

                long long T = min(R, lp);
                if (T >= L) res += (T - L + 1);

                prevB = p.second;
            }
        }
        return res;
    }
};