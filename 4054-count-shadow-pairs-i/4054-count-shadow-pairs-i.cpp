

struct Seg {
    int mi,ma,val;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), val(INT_MAX), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void update(int n, int x) {
        if(mi <= n and n <= ma) {
            val = min(val, x);
            if(left) left->update(n,x);
            if(right) right->update(n,x);
        }
    }
    int query(int n) {
        if(ma < n) return val;
        if(mi >= n) return INT_MAX;
        return min(left->query(n), right->query(n));
    }
};
long long fenwick[101010];
void update(int n) {
    n += 1;
    while(n < 101010) {
        fenwick[n] += 1;
        n += n & -n;
    }
}
long long query(long long n) {
    n += 1;
    long long res = 0;
    while(n) {
        res += fenwick[n];
        n -= n & -n;
    }
    return res;
}
long long query(long long l, long long r) {
    return query(r) - (l ? query(l-1) : 0);
}
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        auto S = nums;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)),end(S));
        Seg * seg = new Seg(S,0,S.size()-1);
        vector<int> at(nums.size());
        map<int,deque<int>> ord;
        for(int i = nums.size() - 1; i >= 0; i--) {
            at[i] = min((int)nums.size() - 1, seg->query(nums[i]) - 1);
            seg->update(nums[i], i);
            ord[-nums[i]].push_front(i);
        }
        long long res = 0;
        memset(fenwick, 0, sizeof fenwick);
        for(auto& [_,ats] : ord) {
            for(auto& pos : ats) {
                int until = at[pos];
                res += query(pos,until);
                update(pos);
            }
        }
        return res;
    }
};