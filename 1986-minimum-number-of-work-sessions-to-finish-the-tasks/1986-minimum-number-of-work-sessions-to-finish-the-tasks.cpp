class Solution {
    long long dp[1<<15];
    unordered_set<string> combDp;
    void combHelper(int& skip, vector<int>& A, int pos, int mask, vector<int>& combs, int& t, int sum, int& n, string s) {
        if(pos == n) {
            if(mask and !combDp.count(s)) {
                combs.push_back(mask);
                combDp.insert(s);
            }
        } else {
            combHelper(skip, A, pos + 1, mask, combs, t, sum, n, s);
            if((skip & (1<<pos)) or A[pos] + sum > t) return;
            combHelper(skip, A, pos + 1, mask | (1<<pos), combs, t, sum + A[pos], n, s + to_string(A[pos]) + "#");
        }
    }
    vector<int> combs(int& mask, vector<int>& A, int& t, int& n) {
        vector<int> res;
        combDp.clear();
        combHelper(mask, A, 0, 0, res, t, 0, n, "");      
        return res;
    }
    long long helper(int mask, vector<int>& A, int& t, int& n) {
        if(mask + 1== (1<<n)) return 0;
        if(dp[mask] != -1) return dp[mask];
        dp[mask] = INT_MAX;
        for(auto& c : combs(mask, A, t, n)) {
            dp[mask] = min(dp[mask], 1 + helper(mask | c, A, t, n));
        }
        return dp[mask];
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        memset(dp, -1, sizeof dp);
        sort(begin(tasks), end(tasks));
        int fit = 0, n = tasks.size();
        while(!tasks.empty() and tasks.back() == sessionTime) {
            fit++;
            tasks.pop_back();
        }
        n = tasks.size();
        return fit + helper(0, tasks, sessionTime, n);
    }
};