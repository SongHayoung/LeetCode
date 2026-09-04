struct Seg {
    long long mi, ma, sum, cnt;
    Seg* left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), sum(0), cnt(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void update(int x, int op) {
        if(mi <= x and x <= ma) {
            sum += x * op;
            cnt += op;
            if(left) left->update(x,op);
            if(right) right->update(x,op);
        }
    }
    long long miK(int k) {
        if(cnt <= k) return sum;
        if(mi == ma) return mi * k;
        if(left->cnt >= k) return left->miK(k);
        return left->sum + right->miK(k - left->cnt);
    }
    long long maK(int k) {
        if(cnt <= k) return sum;
        if(mi == ma) return ma * k;
        if(right->cnt >= k) return right->maK(k);
        return right->sum + left->maK(k - right->cnt);
    }
    long long lowK(int k) {
        if(mi == ma) return mi;
        if(left->cnt >= k) return left->lowK(k);
        return right->lowK(k - left->cnt);
    }
    long long topK(int k) {
        if(mi == ma) return mi;
        if(right->cnt >= k) return right->topK(k);
        return left->topK(k - right->cnt);
    }
};
using ll = long long;
ll mod = 1e9 + 7;
ll modpow(ll n, ll x, ll MOD = mod) {if(x<0){return modpow(modpow(n,-x,MOD),MOD-2,MOD);}n%=MOD;ll res=1;while(x){if(x&1){res=res*n%MOD;}n=n*n%MOD;x>>=1;}return res;}

class Solution {
public:
    vector<int> powerUpdate(vector<int>& nums, ll p, vector<vector<int>>& queries) {
        vector<int> S = nums;
        for(auto& q : queries) S.push_back(q[0]);
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size() - 1);
        for(auto& n : nums) seg->update(n, 1);
        vector<int> res;
        for(auto& q : queries) {
            int v = q[0], k = q[1];
            seg->update(v, 1);
            int x = seg->topK(k);
            p = modpow(p,x);
            res.push_back(p);
        }
        return res;
    }
};