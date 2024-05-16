struct Seg {
    int mi, ma, val;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), val(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void update(int n, int k) {
        if(mi <= n and n <= ma) {
            val = max(val, k);
            if(left) left->update(n,k);
            if(right) right->update(n,k);
        }
    }
    int query(int n) {
        if(mi >= n) return val;
        if(ma < n) return 0;
        return max(left->query(n), right->query(n));
    }
};
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<int> S = scores;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size() - 1);
        vector<pair<int,int>> ord;
        for(int i = 0; i < ages.size(); i++) ord.push_back({ages[i], scores[i]});
        sort(begin(ord), end(ord));
        int res = 0;
        while(ord.size()) {
            auto [_,s] = ord.back(); ord.pop_back();
            int x = seg->query(s) + s;
            res = max(res, x);
            seg->update(s,x);
        }
        return res;
    }
};