struct Seg {
    int mi, ma, sum;
    Seg *le, *ri;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), sum(0), le(nullptr), ri(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            le = new Seg(A,l,m);
            ri = new Seg(A,m+1,r);
        }
    }
    void add(int x) {
        if(mi <= x and x <= ma) {
            sum++;
            if(le) le->add(x);
            if(ri) ri->add(x);
        }
    }
    int query(int l, int r) {
        if(l <= mi and ma <= r) return sum;
        if(mi > r or ma < l) return 0;
        return le->query(l,r) + ri->query(l,r);
    }
};
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int> S = nums;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        int ma = S.back();
        set<int> st;
        for(auto& x : S) {
            st.insert(x);
            st.insert(x + k);
            st.insert(x - k);
        }
        Seg* seg = new Seg(S,0,S.size() - 1);
        for(auto& n : nums) seg->add(n);
        int res = 0;
        for(auto& value : st) {
            int window = seg->query(value-k,value+k), cnt = seg->query(value,value);
            res = max(res, cnt + min(window - cnt, numOperations));
        }
        return res;
    }
};