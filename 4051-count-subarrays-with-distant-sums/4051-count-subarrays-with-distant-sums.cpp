
struct Seg {
    long long mi, ma, cnt;
    Seg *left, *right;
    Seg(vector<long long>& A, int l, int r) : mi(A[l]), ma(A[r]), cnt(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void update(long long n) {
        if(mi <= n and n <= ma) {
            cnt++;
            if(left) left->update(n);
            if(right) right->update(n);
        }
    }
    long long query(long long l, long long r) {
        if(l <= mi and ma <= r) return cnt;
        if(l > ma or r < mi) return 0;
        return left->query(l,r) + right->query(l,r);
    }
};
class Solution {
public:
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        long long n = nums.size();
        if(k == 0) return n * (n + 1) / 2;
        vector<long long> pre{0};
        for(auto& n : nums) pre.push_back(pre.back() + n);
        vector<long long> S = pre;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size() - 1);
        long long res = 0;
        seg->update(0);
        for(int i = 1; i <= n; i++) {
            long long l = pre[i] - goal - k + 1;

            long long r = pre[i] - goal + k - 1;
            
           long long c = seg->query(l,r);
           res += i - c;
           seg->update(pre[i]);
        }
        return res;
    }
};