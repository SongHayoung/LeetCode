
class Solution {
    int helper(vector<int>& A) {
        int l = 0, r = A.size() - 1, res = 0;
        while(l < r) res += abs(A[l++] - A[r--]);
        return res;
    }
public:
    int mirrorFrequency(string s) {
        vector<int> alpha(26), digit(10);
        for(auto& ch : s) {
            if(isalpha(ch)) alpha[ch-'a']++;
            else digit[ch-'0']++;
        }
        return helper(alpha) + helper(digit);
    }
};
