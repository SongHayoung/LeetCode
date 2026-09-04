struct Seg {
    long long mi, ma, sum;
    Seg *left, *right;
    Seg(vector<long long>& A, int l, int r) : mi(A[l]), ma(A[r]), sum(0), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void update(long long x) {
        if(mi <= x and x <= ma) {
            sum++;
            if(left) left->update(x);
            if(right) right->update(x);
        }
    }
    long long query(long long x) {
        if(mi >= x) return sum;
        if(ma < x) return 0;
        return left->query(x) + right->query(x);
    }
};
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        vector<long long> S{hp};
        for(auto& d : damage) S.push_back(S.back() + d);
        Seg *seg = new Seg(S,0,S.size() - 1);
        long long acc = 0, res = 0;
        for(int i = 0; i < damage.size(); i++) {
            seg->update(hp + acc);
            res += seg->query(damage[i] + requirement[i] + acc);
            acc += damage[i];
        }
        return res;
    }
};