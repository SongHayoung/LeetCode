class Solution {
    long long helper(int n) {
        if(n == 0) return 0;
        int res = 1;
        while(res * (res + 1) / 2 < n) res++;
        return res;
    }
public:
    int minimumBoxes(int n) {
        long long res = 1, sum = 0, cnt = 1;
        while(sum + res <= n) {
            sum += res;
            res = res + ++cnt;
        }
        return (res - cnt) + helper(n-sum);
    }
};