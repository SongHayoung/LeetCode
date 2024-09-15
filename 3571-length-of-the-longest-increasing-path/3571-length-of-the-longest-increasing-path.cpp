struct Seg {
    int mi, ma, val, base;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r, int base) : mi(A[l]), ma(A[r]), val(base), base(base), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m,base);
            right = new Seg(A,m+1,r,base);
        }
    }
    int query(int x) {
        if(ma < x) return val;
        if(mi >= x) return base;
        return max(left->query(x), right->query(x));
    }
    void update(int n, int k) {
        if(mi <= n and n <= ma) {
            val = max(val, k);
            if(left) left->update(n,k);
            if(right) right->update(n,k);
        }
    }
};
class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        vector<int> S;
        vector<array<int,3>> C;
        for(int i = 0; i < coordinates.size(); i++) {
            S.push_back(coordinates[i][1]);
            C.push_back({coordinates[i][0], coordinates[i][1], i});
        }
        sort(begin(C), end(C), [](auto& a, auto& b) {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg1 = new Seg(S,0,S.size() - 1, 0);
        Seg* seg2 = new Seg(S,0,S.size() - 1, INT_MIN);
        for(int i = 0, fl = 0; i < C.size(); i++) {
            if(!fl) {
                int best = seg1->query(C[i][1]);
                seg1->update(C[i][1], best + 1);
                if(C[i][2] == k) {
                    fl = 1;
                    seg2->update(C[i][1], best + 1);
                }
            } else {
                int best = seg2->query(C[i][1]);
                seg2->update(C[i][1], best + 1);
            }
        }
        return seg2->val;
    }
};