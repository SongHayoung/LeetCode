
struct Counter {
    unordered_map<int,int> mp;
    int odds = 0;
    void update(int x, int op) {
        mp[x] += op;
        if(mp[x] & 1) odds++;
        else odds--;
        if(mp[x] == 0) mp.erase(x);
    }
    bool ok(int k) {
        if(mp.size() != k) return false;
        return !odds;
    }
};
class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        Counter c;
        vector<array<int,3>> Q;
        vector<int> counts{0};
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++) {
            us.insert(nums[i]);
            counts.push_back(us.size());
        }
        for(int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            int len = r - l + 1;
            if(len & 1) continue;
            if(len < 2 * k) continue;
            if(counts[r+1] - counts[l] > k) continue;
            if(len % k) continue;
            Q.push_back({l, r, i});
        }
        int sq = sqrt(queries.size());
        sort(begin(Q), end(Q), [&](auto& a, auto& b) {
            int asq = a[0] / sq, bsq = b[0] / sq;
            if (asq == bsq) {
                return a[1] < b[1];
            }
            return asq < bsq;
        });
        vector<bool> res(queries.size());
        int l = 0, r = 0;
        for(auto& [le,ri,idx] : Q) {
            while(r <= ri) c.update(nums[r++],1);
            while(l > le) c.update(nums[--l], 1);
            while(r > ri + 1) c.update(nums[--r],-1);
            while(l < le) c.update(nums[l++], -1);
            res[idx] = c.ok(k);
        }
        return res;
    }
};