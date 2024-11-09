class Solution {
    bool ok(int n, int t) {
        int p = 1;
        while(n) {
            p *= n % 10; n /= 10;
        }
        return p % t == 0; 
    }
public:
    int smallestNumber(int n, int t) {
        for(;;n++) if(ok(n,t)) return n;
        return -1;
    }
};