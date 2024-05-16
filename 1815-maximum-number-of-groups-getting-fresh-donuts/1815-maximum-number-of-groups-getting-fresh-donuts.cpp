class Solution {
    unordered_map<string,int> dp[10];
    bool fin(vector<int>& A) {
        for(int i = 0; i < A.size(); i++) if(A[i]) return false;
        return true;
    }
    string key(vector<int>& A) {
        string res = "";
        for(int i = 0; i < A.size(); i++) res += to_string(A[i]) + "#";
        return res;
    }
    int helper(vector<int>& A, int sum, int x) {
        if(fin(A)) return 0;
        string k = key(A);
        if(dp[sum].count(k)) return dp[sum][k];
        int& res = dp[sum][k] = sum == 0;
        for(int i = 0; i < x; i++) {
            if(!A[i]) continue;
            A[i] -= 1;
            res = max(res, (sum == 0) + helper(A,(sum + i) % x, x));
            A[i] += 1;
        }
        return res;
    }
public:
    int maxHappyGroups(int k, vector<int>& A) {
        vector<int> buc(k);
        for(auto& x : A) buc[x%k]++;
        int res = buc[0]; buc[0] = 0;
        for(int i = 1, j = k - 1; i <= j; i++,j--) {
            if(i != j) {
                int mi = min(buc[i], buc[j]);
                res += mi;
                buc[i] -= mi; buc[j] -= mi;
            } else {
                int mi = buc[i] / 2;
                res += mi;
                buc[i] -= mi * 2;
            }
        }
        for(int i = 0; i < 10; i++) dp[i].clear();
        if(!fin(buc)) {
            res += helper(buc,0,k);
        }
        return res;
    }
};