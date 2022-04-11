class Solution {
    int factorial(int n) {
        return n == 1 ? 1 : n * factorial(n-1);
    }
    string helper(int n, int k) {
        if(n == 1) return string(1, '0' + k);
        int comb = factorial(n-1);

        int front = (k - 1) / comb;
        return string(1, '1' + front) + helper(n-1,k - front * comb);
    }
public:
    string getPermutation(int n, int k) {
        string res = helper(n,k);
        for(int num = 1; num <= n; num++) {
            for(int i = 0; i < res.length(); i++) {
                if((res[i] & 0b1111) == num) {
                    for(int j = i + 1; j < res.length(); j++)
                        if(res[j] >= res[i]) res[j]++;
                    break;
                }
                
            }
        }
        return res;
    }
};