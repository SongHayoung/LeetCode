class Solution {
    long double EPS = 1e-5;
    bool helper(vector<int>& A, int loss, long double m) {
        long double less = 0.0, greater = 0.0;
        for(auto& a : A) {
            if(a < m) less += m - a;
            else greater += a - m;
        }
        return greater * (1.-loss/100.) >= less;
    }
public:
    double equalizeWater(vector<int>& A, int loss) {
        sort(begin(A), end(A));
        long double l = A[0], r = A.back();
        
        while(l + EPS < r) {
            long double m = l + (r-l) / 2.0;
            bool pass = helper(A, loss, m);
            if(pass) l = m;
            else r = m;
        }
        return l;
    }
};