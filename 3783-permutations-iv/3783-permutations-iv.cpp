class Solution {
    int get(set<int>& s, int k) {
        if(s.size() < k) return -1;
        int res = 0;
        for(auto& x : s) {
            if(--k == 0) {
                res = x;
                break;
            }
        }
        s.erase(res);
        return res;
    }
    long long nth(long long k, int a, int b) {
        long long res = k;
        for(int i = 1; i <= a; i++) res /= i;
        for(int i = 1; i < b; i++) res /= i;
        return res + 1;
    }
    long long nextK(long long k, int base, int a, int b) {
        if(base == 1) return k;
        long long op = 1;
        for(int i = 1; i <= a; i++) op *= i;
        for(int i = 1; i < b; i++) op *= i;
        return k - (base - 1) * op;
    }
    void helper(vector<int>& res, int pos, long long& k, set<int>& odd, set<int>& even) {
        if(even.size() + odd.size() == 1) {
            if(even.size()) res.push_back(*begin(even));
            if(odd.size()) res.push_back(*begin(odd));
            return;
        }
        if(pos == 0) {
            long long e = even.size(), o = odd.size(), base = nth(k,e,o);
            if(e == o) {
                if(e + o < base) return;
                res.push_back(get(base & 1 ? odd : even, (base + 1) / 2));
            } else {
                res.push_back(get(odd,base));
            }
            if(res.back() <= 0) return;

            k = nextK(k,base,e,o);
            helper(res,pos+1, k,odd,even);
        } else {
            set<int>& now = res.back() & 1 ? even : odd;
            set<int>& prv = res.back() & 1 ? odd : even;
            long long n = now.size(), p = prv.size(), base = nth(k,p,n);
            res.push_back(get(now,base));
            k = nextK(k,base,p,n);
            helper(res,pos+1,k,odd,even);
        }
    }
public:
    vector<int> permute(int n, long long k) {
        set<int> odd, even;
        for(int i = 1; i <= n; i++) {
            if(i&1) odd.insert(i);
            else even.insert(i);
        }
        vector<int> res;
        helper(res,0,--k,odd,even);
        if(k or *min_element(begin(res), end(res)) != 1) return {};
        return res;
    }
};