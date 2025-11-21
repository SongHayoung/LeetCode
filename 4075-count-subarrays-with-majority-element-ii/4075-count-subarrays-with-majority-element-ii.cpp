
struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void add(int i, long long v=1){ for(; i<=n; i += i&-i) bit[i]+=v; }
    long long sum(int i){ long long r=0; for(; i>0; i -= i&-i) r += bit[i]; return r; }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> pre(n+1);
        for(int i=0;i<n;i++) pre[i+1] = pre[i] + ((nums[i]==target) ? 1 : -1);

        vector<long long > A = pre;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A));
        auto at = [&](long long x) {
            return lower_bound(begin(A), end(A), x) - begin(A) + 1;
        };

        Fenwick fw(A.size());
        long long res = 0;
        for(int i=0;i<=n;i++){
            int x = at(pre[i]);
            if(x - 1 >= 1) res += fw.sum(x);
            fw.add(x, 1);
        }
        return res;
    }
};