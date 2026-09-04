
struct Seg {
    int mi,ma,cnt;
    Seg *left, *right;

    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), cnt(0), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void update(int n) {
        if(mi <= n and n <= ma) {
            cnt++;
            if(left) left->update(n);
            if(right) right->update(n);
        }
    }
    int query(int x) {
        if(mi == ma) return mi;
        if(left->cnt < x) return right->query(x - left->cnt);
        return left->query(x);
    }
};
class Solution {
    long long mod = 1e9 + 7;
    long long modpow(long long n, long long x, long long mod) {
        if(x<0){
            return modpow(modpow(n,-x,mod),mod-2,mod);
        }
        n%=mod;
        long long res=1;
        while(x){if(x&1){res=res*n%mod;}n=n*n%mod;x>>=1;}return res;
    }
public:
    vector<int> powerUpdate(vector<int>& nums, int p, vector<vector<int>>& queries) {
        vector<int> S = nums;
        for(auto& q : queries) S.push_back(q[0]);
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size() - 1);
        for(auto& n : nums) seg->update(n);
        vector<int> res;
        int tot = nums.size();
        for(auto& q : queries) {
            int val = q[0], k = q[1];
            tot++;
            seg->update(val);
            int x = seg->query(tot - k + 1);
            p = modpow(p,x,mod);
            res.push_back(p);
        }
        return res;
    }
};