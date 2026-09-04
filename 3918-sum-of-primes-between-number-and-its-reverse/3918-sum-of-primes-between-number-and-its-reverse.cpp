class Solution {
    bool prime(int n) {
        if(n == 1) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
public:
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(begin(s), end(s));
        int l = stoi(s), r = n;
        if(l > r) swap(l,r);
        int res = 0;
        for(int i = l; i <= r; i++) {
            if(prime(i)) res += i;
        } 
        return res;
    }
};