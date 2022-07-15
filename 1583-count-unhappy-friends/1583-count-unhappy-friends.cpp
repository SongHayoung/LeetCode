class Solution {
    bool helper(int me, int matched, int target, vector<int>& A) {
        for(auto& a : A) {
            if(a == matched) return true;
            if(a == target) return false;
        }
        return false;
    }
public:
    int unhappyFriends(int n, vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0;
        vector<int> match(n);
        for(auto& b : B) {
            match[b[0]] = b[1];
            match[b[1]] = b[0];
        }
        for(int i = 0; i < n; i++) {
            bool happy = true;
            for(auto& pref : A[i]) {
                if(pref == match[i]) break;
                if(!happy) break;
                happy = helper(pref, match[pref], i, A[pref]);
            }
            res += !happy;
        }
        return res;
    }
};