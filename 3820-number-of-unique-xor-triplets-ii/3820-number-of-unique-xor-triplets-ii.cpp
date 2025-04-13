struct XORBasis {
    vector<pair<int,int>> base;
    vector<int> bit;
    XORBasis(vector<int>& A) : bit(vector<int>(32)) {
        for(auto& a : A) insert(a);
        compression();
    }
    XORBasis() : bit(vector<int>(32)) {}
    void insert(int x) {
        for(int i = 31; i >= 0; i--) {
            if(!on(x,i)) continue;
            if(bit[i]) x ^= bit[i];
            else {
                bit[i] = x;
                return;
            }
        }
    }
    void compression() {
        for(int i = 0; i < 32; i++) if(bit[i]) base.push_back({i,bit[i]});
    }
    pair<int,int> query(int x, bool match) {
        int bit = 0;
        for(int i = 0; i < base.size(); i++) {
            auto [f,s] = base[i];
            if(on(x,f) == match) {
                x ^= s, bit |= 1<<i;
            }
        }
        return {x,bit};
    }
    pair<int,int> minQuery(int x = 0) {
        return query(x, true);
    }
    pair<int,int> maxQuery(int x = 0) {
        return query(x, false);
    }
    bool on(int a, int i) {
        return (a>>i)&1;
    }
};

class Solution {
    void fwht(vector<long long>& A, bool fl) {
        for(int len = 1; len < A.size(); len<<=1) {
            for(int i = 0; i < A.size(); i += len * 2) {
                for(int j = 0; j < len; j++) {
                    long long u = A[i+j], v = A[i+j+len];
                    A[i+j] = u + v, A[i+j+len] = u - v;
                }
            }
        }
        if(fl) {
            for(int i = 0; i < A.size(); i++) A[i] /= A.size();
        }
    }
    vector<long long> compression(vector<int>& A) {
        XORBasis bi(A);
        vector<long long> f(1<<bi.base.size());
        for(auto& a : A) {
            f[bi.minQuery(a).second] = 1;
        }
        return f;
    }
public:
    int uniqueXorTriplets(vector<int>& A) {
        vector<long long> F = compression(A);
        fwht(F, false);
        for(auto& f : F) f = f * f * f;
        fwht(F, true);

        return F.size() - count(begin(F), end(F), 0);
    }
};