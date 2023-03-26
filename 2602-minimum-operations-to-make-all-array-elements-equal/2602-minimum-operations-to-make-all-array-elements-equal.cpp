struct Seg {
    long long mi, ma, sum, cnt;
    Seg *left, *right;
    Seg(int l, int r) : mi(l), ma(r), sum(0), cnt(0), left(nullptr), right(nullptr) {
        if(l != r) {
            int m = l + (r - l) / 2;
            left = new Seg(l,m);
            right = new Seg(m+1,r);
        }
    }
    void update( long long n,  long long val) {
        if(mi <= n and n <= ma) {
            sum += val;
            cnt += 1;
            if(left) left->update(n,val);
            if(right) right->update(n,val);
        }
    }
    pair<long long, long long> query( long long l,  long long r) {
        if(l > r) return {0,0};
        if(l <= mi and ma <= r) return {sum, cnt};
        if(mi > r or ma < l) return {0,0};
        long long sum = 0, cnt = 0; 
        if(left) {
            auto [s,c] = left->query(l,r);
            sum += s, cnt += c;
        }
        if(right) {
            auto [s,c] = right->query(l, r);
            sum += s, cnt += c;
        }
        return {sum, cnt};
    }
};

class Solution {
    unordered_map<int, int> helper(vector<int>& A, vector<int>& Q) {
        set<int> st;
        for(auto a : A) st.insert(a);
        for(auto q : Q) st.insert(q);
        unordered_map<int, int> res;
        int id = 0;
        for(auto s : st) res[s] = id++;
        return res;
    }
public:
    vector<long long> minOperations(vector<int>& A, vector<int>& Q) {
        unordered_map<int, int> seq = helper(A, Q);
        Seg* seg = new Seg(0,seq.size());
        for(auto a : A) seg->update(seq[a], a);
        vector<long long> res;
        for(auto q : Q) {
            auto id = seq[q];
            auto [ls, lc] = seg->query(0,id-1);
            auto [rs, rc] = seg->query(id+1,seq.size());
            long long x = lc * q - ls + rs - rc * q;
            res.push_back(x);
        }
        return res;
    }
};
