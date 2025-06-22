
struct Seg {
    int mi, ma, val;
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
            val = x;
            if(left) left->update(n,x);
            if(right) right->update(n,x);
        }
    }
    int query(int l, int r) {
        if(l <= mi and ma <= r) return val;
        if(l > ma or r < mi) return INT_MAX;
        return min(left->query(l,r), right->query(l,r));
    }
} *seg;
class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        vector<bool> sieve(5e4 + 1, true);
        sieve[0] = sieve[1] = false;
        for(long long i = 2; i < sieve.size(); i++) {
            if(!sieve[i]) continue;
            for(long long j = i * i; j < sieve.size(); j += i) sieve[j] = false;
        }
        vector<int> A;
        for(auto& n : nums) if(sieve[n]) A.push_back(n);
        if(A.size() == 0) return 0;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A));
        seg = new Seg(A,0,A.size() - 1);
        int until = INT_MAX, last = 0, res = 0;
        deque<int> dq;
        auto qry = [&](int x) -> int {
            int le = x - k - 1, ri = x + k + 1, res = INT_MAX;
            if(le >= 0) res = min(res, seg->query(0,le));
            if(ri <= 5e4) res = min(res, seg->query(ri, 5e4));
            return res == INT_MAX ? nums.size() - 1 : res - 1;
        };
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(!sieve[nums[i]]) res += last;
            else {
                if(dq.size()) {
                    until = min(until, qry(nums[i]));
                    if(until >= dq[0]) last = until - dq[0] + 1;
                    else last = 0;
                    res += last;
                }
                dq.push_front(i);
                seg->update(nums[i], i);
            }
        }
        return res;
    }
};
