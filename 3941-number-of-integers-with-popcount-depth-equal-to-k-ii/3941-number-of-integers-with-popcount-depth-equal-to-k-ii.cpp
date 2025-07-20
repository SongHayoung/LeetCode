long long fenwick[6][101010];
void update(int n, int k, int op) {
    n += 1;
    while(n < 101010) {
        fenwick[k][n] += op;
        n += n & -n;
    }
}
long long query(long long n, long long k) {
    n += 1;
    long long res = 0;
    while(n) {
        res += fenwick[k][n];
        n -= n & -n;
    }
    return res;
}
long long query(long long l, long long r, long long k) {
    return query(r,k) - (l ? query(l-1,k) : 0);
}
long long pc[64];
class Solution {
    long long helper(long long x) {
        if(x == 1) return 0;
        if(pc[x] != 0) return pc[x];
        return pc[x] = 1 + helper(__builtin_popcountll(x));
    }
    long long popcount(long long x) {
        if(x == 1) return 0;
        return 1 + helper(__builtin_popcountll(x));
    }
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        memset(fenwick, 0, sizeof fenwick);
        for(int i = 0; i < n; i++) {
            nums[i] = popcount(nums[i]);
            if(nums[i] <= 5) update(i,nums[i],1);
        }
        vector<int> res;
        for(auto& q : queries) {
            int op = q[0];
            if(op == 1) {
                int l = q[1], r = q[2], k = q[3];
                res.push_back(query(l,r,k));
            }
            if(op == 2) {
                long long idx = q[1], val = q[2];
                if(nums[idx] <= 5) update(idx,nums[idx], -1);
                nums[idx] = popcount(val);
                if(nums[idx] <= 5) update(idx,nums[idx], +1);
            }
        }
        return res;
    }
};