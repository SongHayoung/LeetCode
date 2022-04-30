class Fancy {
    long m = 1, p = 0, mod = 1e9 + 7;
    vector<array<long,3>> A;
    
    long modPow(long n, long x) {
        if(x == 1) return n;
        long res = modPow(n, x>>1);
        res = (res * res) % mod;
        if(x & 1) res = (res * n) % mod;
        return res;
    }
public:
    Fancy() {
        
    }
    
    void append(int val) {
        A.push_back({val, m, p});
    }
    
    void addAll(int inc) {
        p = (p + inc) % mod;
    }
    
    void multAll(int mul) {
        m = (m * mul) % mod;
        p = (p * mul) % mod;
    }
    
    int getIndex(int idx) {
        if(A.size() <= idx) return -1;
        auto [n, multi, plus] = A[idx];
        auto eval = m * modPow(multi, mod - 2) % mod;
        return (eval * (mod + n - plus) % mod + p) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */