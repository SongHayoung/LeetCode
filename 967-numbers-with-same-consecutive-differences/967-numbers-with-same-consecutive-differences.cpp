class Solution {
    vector<int> res;
    void dfs(int n, int k, int c) {
        if(!n) {
            res.push_back(c); return;
        }
        int nextLessDigit = c % 10 - k, nextGreaterDigit = c % 10 + k;
        if(0 <= nextGreaterDigit and nextGreaterDigit <= 9) dfs(n-1,k,c*10 + nextGreaterDigit);
        if(0 <= nextLessDigit and nextLessDigit <= 9 and nextLessDigit != nextGreaterDigit) dfs(n-1,k,c*10 + nextLessDigit);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i <= 9; i++) {
            dfs(n-1, k ,i);
        }

        return res;
    }
};