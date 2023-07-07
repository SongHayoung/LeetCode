class Solution {
    int helper(string& S, int k, char t) {
        int res = 0, l = 0, r = 0, n = S.length(), inc = 0;
        while(r < n) {
            while(r < n and inc <= k) {
                res = max(res, r - l);
                if(S[r++] == t) inc++;
            }
            if(inc <= k)
                res = max(res, r - l);
            while(l < r and inc > k) {
                if(S[l++] == t) inc--;
            }
        }
        return res;
    }
public:
    int maxConsecutiveAnswers(string S, int k) {
        return max(helper(S, k, 'T'), helper(S, k, 'F'));
    }
};